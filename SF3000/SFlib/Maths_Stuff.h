#ifndef __sflib_maths_stuff_h__
#define __sflib_maths_stuff_h__

#include <stdint.h>

extern void rotate_2d_node(void *);
extern void rotate_node_from_c(void *);
extern void rotate_land_node_from_c(void *);
extern long find_rotation(long, long);
extern long find_2d_distance(long, long);
extern void target_finder(void *);
extern void mc_smoke_mover(void *);
extern void scan_poly_map(long, long, void *);
extern void scan_poly_map_2(long, long, void *);
extern void oppo_rotate_node_from_c(void *);
extern void rotate_node_x_y_z_camera(int32_t *x, int32_t *y, int32_t *z);

#endif /* __sflib_maths_stuff_h__ */
