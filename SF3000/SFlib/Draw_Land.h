#ifndef __sflib_draw_land_h__
#define __sflib_draw_land_h__

#include "SF_CelUtils.h"
#include "SF_Mission.h"
#include "Ship_Struct.h"

extern planet_data planet_info;

extern long camera_x_velocity;
extern long camera_y_velocity;
extern long camera_z_velocity;

extern ship_stack *ship_being_viewed;

extern long land_sort_offset;

extern long air_to_ground_scan_temp;
extern long air_to_ground_scan;
extern long air_to_ground_x;
extern long air_to_ground_y;
extern long air_to_ground_z;
extern long atg_selected;

extern long air_to_air_scan_temp;
extern long air_to_air_scan;
extern long air_to_air_x;
extern long air_to_air_y;
extern long air_to_air_z;
extern long ata_selected;

extern char sky[1024];
extern CCB *skycel;
extern cel_celdata cel_quad;

extern void plot_stars(void);
extern void setup_rotations(void);
extern void machine_code_land_plot(void);
extern void rotate_sky(void *);
extern void plot_ship_graphic(void *);

extern char height_map[256][256];

extern long *temp_store;
extern ship_list ships;

void draw_land(void);

#endif /* __sflib_draw_land_h__ */

