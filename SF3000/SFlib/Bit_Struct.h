#ifndef __BIT_SET_H
#define __BIT_SET_H

#include <stdint.h>
#include "SF_ARMLink.h"

#define MAX_BITS 64

typedef struct bit_stack {
  link_header header;
  int32_t x_pos;
  int32_t y_pos;
  int32_t z_pos; // 0-8
  int32_t x_rot;
  int32_t y_rot;
  int32_t z_rot; // 12-20
  int32_t type;  // 24
  int32_t colour1;
  long who_owns_me; // 28-32
  int32_t x_vel;
  int32_t y_vel;
  int32_t z_vel; // 36-44
  int32_t x_r_vel;
  int32_t y_r_vel;
  int32_t z_r_vel; // 48-56
  int32_t style;
  int32_t counter; // 60-64
} bit_stack;

typedef struct bit_list {
  linked_list info;
  bit_stack bit_item[MAX_BITS];
} bit_list;

#endif
