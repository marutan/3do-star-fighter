#ifndef __sflib_laser_control_h__
#define __sflib_laser_control_h__

#include <stdint.h>
#include "Graphic_Struct.h"
#include "Laser_Struct.h"
#include "Ship_Struct.h"

void laser_update(void);

void add_laser(long, long, long, long, long, long, long, long, long, long,
               long);

void aim_laser(long, long, long, long, long, long, long, long, long, long, long,
               long, long, long);

void start_beam_lasers(void);
void stop_beam_lasers(void);
void update_beam_lasers(void);
void small_fighter_lasers(ship_stack *);
void add_small_fighter_laser(laser_details *, ship_stack *, long);

#define LASER_POWER_1 1
#define LASER_POWER_2 2
#define LASER_POWER_3 3
#define LASER_POWER_4 4
#define LASER_POWER_5 5
#define LASER_POWER_6 6
#define BEAM_LASER 7

#define LASER_TYPE_SMALL_SHIP 0
#define LASER_TYPE_GUN_BASE 1

#endif /* __sflib_laser_control_h__ */
