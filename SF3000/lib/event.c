#include "Star3000.h"
#include <stdint.h>
#include "event.h"

Err
InitEventUtility(int32_t numControlPads, int32_t numMice,
                     int32_t focusListener)
{
  // Only support the subset of options that SF3000 uses
  ASSERT(numControlPads == 1);
  ASSERT(numMice == 0);
  ASSERT(focusListener == LC_Observer);

  PASS;

  return 0;
}

Err
GetControlPad(int32_t padNumber, int32_t wait, ControlPadEventData *data)
{
  UNIMPLEMENTED;

  return 0;
}

Err KillEventUtility(void)
{
  UNIMPLEMENTED;

  return 0;
}
