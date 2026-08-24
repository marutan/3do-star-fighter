#ifndef __sflib_bit_control_h__
#define __sflib_bit_control_h__

#include <stdint.h>
#include "Bit_Struct.h"

#define ROT_LIMIT ((1024 * 1024) - 1)

void bit_update(void);

void add_bit(long, long, long, long, long, long, long, long, long, long, long,
             long);

#endif /* __sflib_bit_control_h__ */
