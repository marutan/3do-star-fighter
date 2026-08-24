#include <stdint.h>

#include "SF_CelUtils.h"
// #include "graphics.h"
#include "Camera_Struct.h"
#include "SF_Status.h"

#include "SF_Joystick.h"
extern stick_struct pro_stick;

/* External Definitions */

extern void rotate_node_from_c(void *);

extern long keypad_iomap[8];

// Shitty get it ready for another show fix
extern long plot_clouds_or_wot;

/* Local Function prototypes */

void update_frame(long);
