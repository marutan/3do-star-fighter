#include <stdint.h>
#include "task.h"
#include "Star3000.h"

Item
CreateThread(const char *name, uint8_t pri, void (*code)(), int32_t stacksize)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
WaitSignal(uint32_t sigMask)
{
  UNIMPLEMENTED;

  return 0;
}

Err
SendSignal(Item task, uint32_t sigMask)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
AllocSignal(uint32_t sigMask)
{
  UNIMPLEMENTED;

  return 0;
}

Err
FreeSignal(uint32_t sigMask)
{
  UNIMPLEMENTED;

  return 0;
}


