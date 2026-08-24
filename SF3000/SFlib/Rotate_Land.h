#ifndef __sflib_rotate_land_h__
#define __sflib_rotate_land_h__

#include <stdint.h>
#include "Global_2.h"

/* Setup data tables for quick reference look up */
extern int32_t cosine_table[2048];
extern int32_t *sine_table;
extern char polymap[128][128];

/* Setup data tables for the maps etc. */

extern long silly_x;
extern long silly_y;

void rotate_land(void);

#endif /* __sflib_rotate_land_h__ */
