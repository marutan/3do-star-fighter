#ifndef __sflib_bit_control_h__
#define __sflib_bit_control_h__

#include <stdint.h>
#include "Bit_Struct.h"

#define ROT_LIMIT ((1024 * 1024) - 1)

void bit_update(void);

void add_bit(int32_t x_pos, int32_t y_pos, int32_t z_pos, int32_t x_vel, int32_t y_vel, int32_t z_vel,
        int32_t colour1, int32_t colour2, int32_t type, int32_t explosion_velocity,
        int32_t owner, int32_t style);


#endif /* __sflib_bit_control_h__ */
