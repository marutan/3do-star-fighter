#ifndef __sflib_ship_control_h__
#define __sflib_ship_control_h__

#include <stdint.h>

#include "Ship_Struct.h"

#define C_LEFT 1
#define C_RIGHT 2
#define C_UP 4
#define C_DOWN 8
#define C_THRUST 16
#define C_FIRE 32
#define ROT_LIMIT ((1024 * 1024) - 1)

// Get these for the satellite update
extern int32_t ground_laser_type;
extern int32_t ground_laser_rate;

extern ship_sdb pleb_special_data;

void ship_control(ship_stack *ship);

void big_ship_control(ship_stack *ship);

void satellite_control(ship_stack *satellite);

void parachute_control(ship_stack *parachute);

void car_control(ship_stack *car);

void check_shippy_collision(ship_stack *ship);

void update_docking(ship_stack *ship);

ship_stack *add_ship(int32_t x_pos, int32_t y_pos, int32_t z_pos,
                     int32_t x_rot, int32_t type,
                     ship_sdb *special_data, performance_data *performance);

// command_override for big ships
#define BIG_SHIP_COMMAND_NORMAL 0
#define BIG_SHIP_COMMAND_ROTATE_Z 1
#define BIG_SHIP_COMMAND_ROTATE_X 2
#define BIG_SHIP_COMMAND_STATIC 3

#define BIG_SHIP_COMMAND_STATIC_FREE 4

#endif /* __sflib_ship_control_h__ */
