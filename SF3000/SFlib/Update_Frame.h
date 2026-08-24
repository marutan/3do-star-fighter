#include <stdint.h>

#include "SF_CelUtils.h"
#include "Ship_Control.h"
#include "Ship_Struct.h"
// #include "graphics.h"
#include "Camera_Struct.h"
#include "SF_Status.h"

#include "SF_Parameters.h"
extern game_configuration configuration;

#include "SF_Joystick.h"
extern stick_struct pro_stick;

/* External Definitions */

// bugggggg fix
extern int32_t laser_sound_counter;

extern void rotate_node_from_c(void *);
extern long wave_counter;
extern long wave_counter2;
extern long wave_counter3;
extern long test_grid_flip;
extern struct camera_data camera[3];

extern game_status status;
extern int32_t pod_counter;
extern long *temp_store;

extern int32_t laser_counter;

#include "SF_Mission.h"
extern planet_data planet_info;


extern long keypad_iomap[8];

// Shitty get it ready for another show fix
extern long plot_clouds_or_wot;

extern ship_stack *players_ship;

/* Local Function prototypes */

void update_frame(long);
