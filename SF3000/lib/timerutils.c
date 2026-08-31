#include "timerutils.h"
#include "Star3000.h"
#include "item.h"


Item
GetTimerIOReq(void)
{
  PASS;

  // No idea of the struct used
  Item retval = CreateSizedItem(0, NULL, sizeof(int32_t));
  if(retval >= 0) {
    return retval;
  }

  return -1;
}

