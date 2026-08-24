#ifndef __sflib_draw_land_h__
#define __sflib_draw_land_h__

#include "SF_CelUtils.h"
#include "SF_Mission.h"
#include "Ship_Struct.h"

extern void plot_stars(void);
extern void setup_rotations(void);
extern void machine_code_land_plot(void);
extern void rotate_sky(void *);
extern void plot_ship_graphic(void *);

extern char height_map[256][256];

void draw_land(void);

#endif /* __sflib_draw_land_h__ */

