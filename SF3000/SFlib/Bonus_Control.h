#ifndef __sflib_bonus_control_h__
#define __sflib_bonus_control_h__

#include <stdint.h>
#include "Ship_Struct.h"

void bonus_control(ship_stack *bonus);

void add_bonus(int32_t x_pos, int32_t y_pos, int32_t z_pos, int32_t x_vel, int32_t y_vel,
          int32_t z_vel, int32_t type);

void add_crystal_from_static(int32_t x_grid, int32_t y_grid, int32_t chance);

void start_bonus_crystal_adder(int32_t x_grid, int32_t y_grid);
void update_bonus_crystal_adder(void);

void add_bonus_from_collision_box(int32_t ref, int32_t grid_ref);

#endif /* __sflib_bonus_control_h__ */
