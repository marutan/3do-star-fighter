/* AI conversion of Laser_Plot.s using a simple MS copilot prompt request
   Then hand fixed to use types and functions from the rest of the code
 */
#include <stdint.h>

#include "Star3000.h"
#include "Global_2.h"
#include "Laser_Struct.h"
#include "Maths_Stuff.h"
#include "Plot_Graphic.h"
#include "SF_ARMCell.h"
#include "SF_CelUtils.h"

#define LASER_POWER_1 1
#define LASER_POWER_2 2
#define LASER_POWER_3 3
#define LASER_POWER_4 4
#define LASER_POWER_5 5
#define LASER_POWER_6 6
#define BEAM_LASER 7

#define POLY_CLIP_DIST 1280
#define CLIP_DISTANCE 2048
#define LASER_SHADE 25

// Screen bounds (from the assembly checks)
#define SCREEN_HALF_HEIGHT 120
#define SCREEN_HALF_WIDTH 160

// Laser structure layout (matching the EQU offsets)
// PJH this matches a subsection of the laser_stack struct in Laser_Struct.h
// and could be replaced by it
typedef struct Laser {
  int32_t x1;      // laser_x_pos      (offset 0)
  int32_t y1;      // laser_y_pos      (offset 4)
  int32_t z1;      // laser_z_pos      (offset 8)
  int32_t x2;      // laser_x_pos2     (offset 12)
  int32_t y2;      // laser_y_pos2     (offset 16)
  int32_t z2;      // laser_z_pos2     (offset 20)
  int32_t type;    // laser_type       (offset 24)
  int32_t counter; // laser_counter    (offset 28)
} Laser;

// -----------------------------------------------------------------------------
// C version of plot_laser
// r0 in assembly is the pointer to the laser link; we skip the 12‑byte header.
// -----------------------------------------------------------------------------
void
plot_laser(void *laser_link_base)
{
  // Skip the 12‑byte link header to get to the Laser struct
  uint8_t *base = (uint8_t *) laser_link_base;
  Laser *laser = (Laser *) (base + 12);

  // --- Rotate start point into camera space ---
  int32_t sx = laser->x1 - camera_x_position;
  int32_t sy = laser->y1 - camera_y_position;
  int32_t sz = camera_z_position - laser->z1;

  // Fixed‑point shift (>> 12) before rotation
  sx >>= 12;
  sy >>= 12;
  sz >>= 12;

  rotate_node_x_y_z_camera(&sx, &sy, &sz);

  // r0‑r2: sx, sy, sz (start point in camera space)

  // Reject if too near or behind camera (depth clipping)
  {
    int32_t clip = sy + CLIP_DISTANCE;

    // |sx| > clip ?
    int32_t ax = sx < 0 ? -sx : sx;
    if (ax > clip) {
      return;
    }

    // |sz| > clip ?
    int32_t az = sz < 0 ? -sz : sz;
    if (az > clip) {
      return;
    }
  }

  // Save start point
  int32_t sx_cam = sx;
  int32_t sy_cam = sy;
  int32_t sz_cam = sz;

  // --- Rotate end point into camera space ---
  int32_t ex = laser->x2 - camera_x_position;
  int32_t ey = laser->y2 - camera_y_position;
  int32_t ez = camera_z_position - laser->z2;

  ex >>= 12;
  ey >>= 12;
  ez >>= 12;

  rotate_node_x_y_z_camera(&ex, &ey, &ez);

  // r0‑r2: ex, ey, ez (end point in camera space)
  // r3‑r5: sx_cam, sy_cam, sz_cam (start point)

  // --- Depth clipping against POLY_CLIP_DIST ---
  if (ey < POLY_CLIP_DIST) {
    if (sy_cam < POLY_CLIP_DIST) {
      // both too near: discard
      return;
    }
    // clip line (start & end)
    clip_3d_line(&sx_cam, &sy_cam, &sz_cam, &ex, &ey, &ez);
  } else if (sy_cam < POLY_CLIP_DIST) {
    // start too near: clip
    clip_3d_line(&sx_cam, &sy_cam, &sz_cam, &ex, &ey, &ez);
  }
  // else: no clipping

  // --- Perspective scaling ---
  // r1 = ey, r4 = sy_cam in assembly
  int32_t depth_end = ey;
  int32_t depth_start = sy_cam;

  // Clear low 6 bits (bic #63)
  depth_end &= ~63;
  depth_start &= ~63;

  // Table index: depth >> 4
  int32_t scale_end = pex_table[depth_end >> 4];
  int32_t scale_start = pex_table[depth_start >> 4];

  // Scale to screen space (fixed‑point >> 16)
  int32_t ex_screen = (int32_t) ((int64_t) ex * scale_end >> 16);
  int32_t ez_screen = (int32_t) ((int64_t) ez * scale_end >> 16);
  int32_t sx_screen = (int32_t) ((int64_t) sx_cam * scale_start >> 16);
  int32_t sz_screen = (int32_t) ((int64_t) sz_cam * scale_start >> 16);

  // r7‑r8: start x,y; r9‑r10: end x,y
  int32_t x0 = sx_screen;
  int32_t y0 = sz_screen;
  int32_t x1 = ex_screen;
  int32_t y1 = ez_screen;

  // --- Compute line deltas and unsigned distances ---
  int32_t dx = x0 - x1;
  int32_t dy = y0 - y1;

  int32_t adx = dx < 0 ? -dx : dx;
  int32_t ady = dy < 0 ? -dy : dy;

  // Initial width components
  int32_t wx = ~127; // mvn #127 -> -128
  int32_t wy = 128;

  // If |dx| > 2*|dy|, no x width
  if (adx > (ady << 1)) {
    wx = 0;
  }

  // If |dy| > 2*|dx|, no y width
  if (ady > (adx << 1)) {
    wy = 0;
  }

  // Flip width based on sign of dx, dy
  if (dx < 0) {
    wy = -wy;
  }
  if (dy < 0) {
    wx = -wx;
  }

  // --- Scale width by perspective for start and end ---
  int32_t w0x = (int32_t) ((int64_t) wx * scale_end >> 17);
  int32_t w0y = (int32_t) ((int64_t) wy * scale_end >> 17);
  int32_t w1x = (int32_t) ((int64_t) wx * scale_start >> 17);
  int32_t w1y = (int32_t) ((int64_t) wy * scale_start >> 17);

  // Ensure non‑zero widths
  if (w0x == 0) {
    w0x = 1;
  }
  if (w0y == 0) {
    w0y = 1;
  }
  if (w1x == 0) {
    w1x = 1;
  }
  if (w1y == 0) {
    w1y = 1;
  }

  // --- Build the 4 polygon points (laser quad) ---
  // r0‑r7: 4 x,y screen coords
  int32_t p0x = x0 + w0x;
  int32_t p0y = y0 + w0y;
  int32_t p1x = x1 + w1x;
  int32_t p1y = y1 + w1y;
  int32_t p2x = x1 - w1x;
  int32_t p2y = y1 - w1y;
  int32_t p3x = x0 - w0x;
  int32_t p3y = y0 - w0y;

  // --- Screen clipping (simple bounds checks) ---
  // bottom
  if (p0y > SCREEN_HALF_HEIGHT && p1y > SCREEN_HALF_HEIGHT &&
      p2y > SCREEN_HALF_HEIGHT && p3y > SCREEN_HALF_HEIGHT) {
    return;
  }

  // top
  if (p0y < -SCREEN_HALF_HEIGHT && p1y < -SCREEN_HALF_HEIGHT &&
      p2y < -SCREEN_HALF_HEIGHT && p3y < -SCREEN_HALF_HEIGHT) {
    return;
  }

  // left
  if (p0x < -SCREEN_HALF_WIDTH && p1x < -SCREEN_HALF_WIDTH &&
      p2x < -SCREEN_HALF_WIDTH && p3x < -SCREEN_HALF_WIDTH) {
    return;
  }

  // right
  if (p0x > SCREEN_HALF_WIDTH && p1x > SCREEN_HALF_WIDTH &&
      p2x > SCREEN_HALF_WIDTH && p3x > SCREEN_HALF_WIDTH) {
    return;
  }

  // --- Fill cel_quad polygon data ---
  cel_celdata *q = &cel_quad;

  q->x_pos0 = p0x;
  q->y_pos0 = p0y;
  q->x_pos1 = p1x;
  q->y_pos1 = p1y;
  q->x_pos2 = p2x;
  q->y_pos2 = p2y;
  q->x_pos3 = p3x;
  q->y_pos3 = p3y;

  // Shade
  q->shade = LASER_SHADE;

  // Colour / bitmap based on laser type (and #7 mask)
  int32_t type = laser->type & 7;
  //  q->bitmap = 159 - type; // rsb r1,r1,#159

  // Plot polygon
  arm_addpolycel32(q, 159 - type);
}
