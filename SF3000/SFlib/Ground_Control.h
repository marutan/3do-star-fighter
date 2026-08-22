#ifndef __sflib_ground_control_h__
#define __sflib_ground_control_h__

#include <stdint.h>
#include "SF_Mission.h"

void ground_update(void);

extern int32_t ground_laser_rate;
extern int32_t ground_sam_rate;
extern int32_t ground_ship_rate;
extern int32_t ground_laser_type;
extern int32_t ground_ship_type;

extern long *temp_store;
extern mission_data mission;
extern int32_t laser_counter;

#endif /* __sflib_ground_control_h__ */
