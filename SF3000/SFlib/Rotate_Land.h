#ifndef __sflib_rotate_land_h__
#define __sflib_rotate_land_h__

#include <stdint.h>

/* Setup data tables for quick reference look up */
extern int32_t cosine_table[2048];
extern long pex_table[16384];
extern int32_t *sine_table;
extern char polymap[128][128];
extern long quick_height_table[256][4];

/* Setup data tables for the maps etc. */
extern char landscape_heights[256][256];
extern long rotated_coords[3200][3];
extern long screen_coords[3200][2];
extern long graphics_data[19000];
extern long star_coords[128][4];

extern long silly_x;
extern long silly_y;

void rotate_land(void);

#endif /* __sflib_rotate_land_h__ */
