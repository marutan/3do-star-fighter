#ifndef __CAMERA_SET_H
#define __CAMERA_SET_H

#include <stdint.h>

#define MAX_CAMERAS 3

#define CAMERA_NORMAL 0
#define CAMERA_INTERNAL 1
#define CAMERA_TRACKING 2
#define CAMERA_FLYBY 3

typedef struct camera_data {
  struct ship_stack *view_ship;
  int32_t x_rot;
  int32_t y_rot;
  int32_t zoom;
  int32_t type;
  int32_t view;
  int32_t instance;
  int32_t x_pos;
  int32_t y_pos;
  int32_t z_pos;
  int32_t x_pos2;
  int32_t y_pos2;
  int32_t counter2;
  int32_t counter;
} camera_data;

#endif
