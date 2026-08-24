#ifndef __sflib_setup_tables_h__
#define __sflib_setup_tables_h__

// THIS WILL CHANGE ALL THE MISSION SAM RATINGS

// SET THE SAM RATE - E.G.	1024 IS NORMAL
// 							512 = HALF THE NUMBER OF
// SAMS 							2048 = DOUBLE THE FIRE RATE

#include <stdint.h>

// I HAVE SET THIS LOWER BECAUSE HAVING PLAYED IT I FELT THERE WERE TOO MANY

#define SAM_FIRE_RATE 650

// NORMAL - 1024 I HAVE ALSO SET THIS SLIGHTLY LOWER

#define LASER_FIRE_RATE 800

// NOTE THESE SETTING WILL ONLY CHANGE THE FIRE RATE FOR ALL GROUND OBJECTS ON
// ALL MISSIONS

#include "Camera_Struct.h"
#include "SF_CelUtils.h"
#include "SF_Mission.h"
#include "Ship_Struct.h"

#define COLL_UP_RIGHT 248
#define COLL_UP 249
#define COLL_UP_LEFT 250
#define COLL_LEFT 251
#define COLL_DOWN_LEFT 252
#define COLL_DOWN 253
#define COLL_DOWN_RIGHT 254
#define COLL_RIGHT 255

extern char height_map[256][256];
extern char sprite_map[256][256];
extern char poly_map[128][128];

// Camera Stuff
extern ship_stack *ship_viewed_last_frame;

extern long camera_x_velocity;
extern long camera_y_velocity;
extern long camera_z_velocity;

#include "SF_Mission.h"
extern mission_data mission;

#include "SF_Status.h"
extern game_status status;

extern cel_celdata cel_quad;
extern char skyfile[1024];

extern void machine_code_constants(void *);
extern void plot_land_constants(void *);

void setup_tables(void);

extern planet_data planet_info;

extern long are_we_in_space_or_wot;

extern long planet_1_x_pos;
extern long planet_1_y_pos;
extern long planet_1_z_pos;

extern long planet_2_x_pos;
extern long planet_2_y_pos;
extern long planet_2_z_pos;

extern bonus_crystal_object_struct bonus_crystal_object;

#endif /* __sflib_setup_tables_h__ */
