#ifndef __sflib_collision_h__
#define __sflib_collision_h__

#include "Ship_Struct.h"
extern long check_collision(long, long, long);
extern void setup_collision_constants(long);
extern long find_ground_height(long, long);
extern long big_ship_collision_check(ship_stack *, ship_stack *);

/* Contained in Collision.c/.s */
extern long bonus_collision_ref;

#endif /* __sflib_collision_h__ */
