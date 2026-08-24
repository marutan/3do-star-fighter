#ifndef __sflib_global_2_h__
#define __sflib_global_2_h__

#include <stdint.h>

// Setup various structures
#include "Ship_Struct.h"
extern ship_list ships;
extern ship_stack *players_ship;

#include "Smoke_Struct.h"
extern smoke_list smokes;

#include "Camera_Struct.h"
extern camera_data camera[MAX_CAMERAS];

#include "Laser_Struct.h"
extern laser_list lasers;

extern laser_stack *beam_lasers[32];
extern beam_laser_data beam_laser;

#include "Bit_Struct.h"
extern bit_list bits;

#include "Explosion_Struct.h"
extern explosion_list explosions;

#include "Misc_Struct.h"

// Docking stuff for the players ship
extern docking_struct docked;

// Bonus crystal stuff
extern bonus_crystal_adder_struct bonus_crystal_adder;
extern bonus_crystal_hill_struct bonus_crystal_hill;
extern bonus_crystal_object_struct bonus_crystal_object;
extern int32_t bonus_collision_this_frame;

// Players control rates
extern int32_t players_x_control;
extern int32_t players_y_control;
extern int32_t players_z_control;
extern int32_t players_thrust_control;

// ########### bug fix for sound_conteol
extern int32_t laser_sound_counter;

// Two nearest ships of this type make engine sounds
extern ship_stack *sound_big_ship;
extern ship_stack *sound_small_ship;
extern int32_t sound_channel_small_ship;
extern int32_t sound_channel_big_ship;
extern int32_t sound_sample_small_ship;
extern int32_t sound_channel_shields_low;
extern int32_t sound_channel_beam_laser;
extern int32_t engine_sounds_on_or_wot;

extern ship_stack *ship_being_viewed;

// Rate of fire for ground objects - chances in 1024
extern int32_t ground_laser_rate;
extern int32_t ground_sam_rate;
extern int32_t ground_ship_rate;

extern int32_t ground_laser_type;
extern int32_t ground_ship_type;
extern int32_t air_ship_type;

// Toggle for the ground lasers
extern int32_t laser_counter;

extern int32_t test_mode;

// Misc counters etc.
extern int32_t pod_counter;

extern int32_t which_graphics_set;

extern int32_t ship_viewed_last_frame_x_rot;
extern ship_stack *ship_viewed_last_frame;

// Setup data tables for quick reference look up
extern int32_t cosine_table[2048];
extern int32_t *sine_table;
extern int32_t pex_table[16384];
extern int32_t pex_table_near[2048];
extern int32_t quick_height_table[256][4];
extern char tangent_table[4100];

// Collision table for static ground obejcts
extern char collision_map[128][128];

// Setup data tables for the stars
extern int32_t star_coords[128][4];

// Setup temp workspace for rotated coords and screen coords

// For use by the landscape rotator
extern int32_t rotated_coords[3200][3];
extern int32_t screen_coords[3200][2];

// For use by the graphics - ships , static objects , explosion bits etc.
extern long graphic_rotated_coords[256][4];
extern int32_t graphic_screen_coords[256][2];

// Temp store for misc use
extern long *temp_store;

// General store for all polygon graphics - ships , static objects , explosion
// bits This contains all coord data + polygon link data All explosion data and
// collision data Misc items such as score / hits counter etc.
extern int32_t graphics_data[19000];

// Global pointers to items in the graphics table
extern long *static_graphics_adr;
extern long *ships_adr;
extern long *explosion_bits_adr;

// Is the 3DO quicker than the arm tests
// mat33f16 matrix ;
// vec3f16 pre_rot [ 128 ] ;
// vec3f16 post_rot [ 128 ] ;

#endif /* __sflib_global_2_h__ */
