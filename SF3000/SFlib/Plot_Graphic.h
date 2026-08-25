#ifndef __sflib_plot_graphics_h__
#define __sflib_plot_graphics_h__

#include <stdint.h>

extern void plot_stars(void);
extern void plot_space_stars(void);
extern void setup_rotations(void);
extern void plot_spinning_ship(long, long);

extern void plot_ship_graphic(void *);
extern void plot_bit_graphic(void *);
extern void rotate_node_from_c(void *);
extern void plot_smoke(void *);
extern void machine_code_constants(void *);
extern void rotate_sky(void *);
extern long find_rotation(long, long);
extern void plot_laser(void *);
extern void plot_bit(void *);
extern void rotate_sky_node(void *);
extern void plot_planets(void);
extern void clip_3d_line(int32_t *x1, int32_t *y1, int32_t *z1, int32_t *x2,
                         int32_t *y2, int32_t *z2);

/* Variables in Plot_Graphic.c/.s */

extern int32_t collision_box_colour_adder;
extern int32_t camera_x_position;
extern int32_t camera_y_position;
extern int32_t camera_z_position;
extern int32_t camera_x_rotation;
extern int32_t camera_y_rotation;
extern int32_t camera_z_rotation;
extern int32_t camera_x_velocity;
extern int32_t camera_y_velocity;
extern int32_t camera_z_velocity;
extern int32_t air_to_ground_scan_temp;
extern long air_to_ground_scan;
extern int32_t air_to_ground_x;
extern int32_t air_to_ground_y;
extern int32_t air_to_ground_z;
extern int32_t atg_selected;
extern int32_t air_to_air_scan_temp;
extern long air_to_air_scan;
extern int32_t air_to_air_x;
extern int32_t air_to_air_y;
extern int32_t air_to_air_z;
extern int32_t ata_selected;
extern int32_t silly_x;
extern int32_t silly_y;
extern int32_t planet_1_x_pos;
extern int32_t planet_1_y_pos;
extern int32_t planet_1_z_pos;
extern int32_t planet_2_x_pos;
extern int32_t planet_2_y_pos;
extern int32_t planet_2_z_pos;
extern int32_t are_we_in_space_or_wot;


#ifndef __GRAPHIC_STUFF_H
#define __GRAPHIC_STUFF_H

typedef struct rotate_node {
  long x_pos;
  long y_pos;
  long z_pos;
  long x_rot;
  long y_rot;
  long z_rot;
} rotate_node;

#endif

#endif /* __sflib_plot_graphics_h__ */
