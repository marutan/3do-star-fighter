#ifndef __star3000_h__
#define __star3000_h__

#include "SFlib/SF_Status.h"
#include "SFlib/SF_CelUtils.h"
#include "SFlib/SF_Parameters.h"

/* All the variables defined in Star3000.c */
extern char *cel_game;                 // Pointer to game textures list
extern char *cel_list32;               // Pointer to 32x32 texture sprites
extern char *cel_list16;               // Pointer to 16x16 ground sprites
extern char *cel_creation;             // Pointer to created 16x16 land cels
extern char *cel_palette;              // Pointer to palette entries
extern char *cel_codedpalette;         // Pointer to coded6 palette entries
extern char *cel_plutdata;             // Pointer to general plut data
extern CCB *cel_plut;                  // Pointer to plut initialising CCB
extern CCB *cel_plotlist[CEL_MAXTEMP]; // Temp cel plotting list
extern cel_celdata cel_quad;           // Cel adder description block
extern zsort_list plot_list;           // Graphic ZSort plot table

// Cache tables for creation cels
// ------------------------------

extern char cache_lookup[64 * 64 * 2];   // Created cels lookup block
extern char cache_free[CEL_MAXCREATION]; // Created cels free list

// Planet information / maps
// -------------------------

extern planet_data planet_info; // Planet type information

extern char sprite_map[256][256]; // Map [sprite] data
extern char height_map[256][256]; // Map [height] data
extern char poly_map[128][128];   // Map [polygon] data

extern char *map512;                // Low res map (512 x 512) - Coded6
extern char *map128;                // Low res map (128 x 128) - Coded6
extern char *map32;                 // Low res map (32  x 32) - Coded6
extern char cels4x4[16 * CEL_MAX4]; // Pointer to 4x4 compacted land cels
extern char animate_poly[1024];     // Pointer to texture animations file

// System Variables
// ----------------

extern int32_t configure_waiting; // Initial configure load ? Decides language / main menu
extern ScreenContext *screen;  // Screen

extern Item VRAMIOReq;
extern Item VBLIOReq;
extern Item parent_taskref; // Task ref of parent

// Game status declarations
// ------------------------

extern game_configuration configuration; // Current game configuration
extern game_status status;               // Mission status
extern game_parameters parameters;       // Game Parameters
extern mission_data mission;             // Mission data

extern int32_t cheat_feature1;
extern int32_t cheat_feature2;
extern int32_t cheat_feature3;
extern int32_t cheat_feature4;

// Performance datablocks for players ship
// ---------------------------------------

extern performance_data player_performance;       // Players performance data
extern performance_data player_resetperformance;  // Players performance reset data
extern performance_data player_megaperformance;   // Players mega performance data

extern char *pilot_names[16];

//extern long keypad;
//extern long keypad_constant;





#endif /* __star3000_h__ */
