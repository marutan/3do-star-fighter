#ifndef __sflib_bit_control_h__
#define __sflib_bit_control_h__

#include <stdint.h>
#include "Bit_Struct.h"

extern int32_t cosine_table[2048];
extern int32_t *sine_table;

extern bit_list bits;
#define ROT_LIMIT ((1024 * 1024) - 1)

extern long which_graphics_set;

void bit_update(void);

void add_bit(long, long, long, long, long, long, long, long, long, long, long,
             long);

#endif /* __sflib_bit_control_h__ */
