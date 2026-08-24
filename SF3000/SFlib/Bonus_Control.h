#ifndef __sflib_bonus_control_h__
#define __sflib_bonus_control_h__

#include <stdint.h>
#include "Ship_Struct.h"

void bonus_control(ship_stack *);

void add_bonus(long, long, long, long, long, long, long);
void add_crystal_from_static(long, long, long);

void start_bonus_crystal_adder(long, long);
void update_bonus_crystal_adder(void);

void add_bonus_from_collision_box(long, long);

#endif /* __sflib_bonus_control_h__ */
