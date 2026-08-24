#ifndef __sflib_collision_update_h__
#define __sflib_collision_update_h__

extern void collision_update(void);
extern void bonus_collision(ship_stack *);
extern void small_ship_collision(ship_stack *);
extern void parachute_collision(ship_stack *);
extern void missile_collision(ship_stack *);

#endif /*  __sflib_collision_update_h__ */
