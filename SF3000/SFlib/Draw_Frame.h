#ifndef __sflib_draw_frame_h__
#define __sflib_draw_frame_h__

#include <stdint.h>

#include "Global_2.h"
#include "Camera_Struct.h"
#include "SF_CelUtils.h"
#include "SF_Mission.h"
#include "SF_Status.h"
#include "Ship_Control.h"
#include "Ship_Struct.h"
#include "graphics.h"

#include "Misc_Struct.h"

/* External Definitions */

extern void rotate_node_from_c(void *);

/* Local Function prototypes */

void draw_frame(long);

#endif /* __sflib_draw_frame_h__ */
