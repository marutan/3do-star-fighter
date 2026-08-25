#include <stdint.h>
#include "io.h"
#include "Star3000.h"

 /* sync   */
Err
DoIO(Item ior, const IOInfo *ioiP)
{
  UNIMPLEMENTED;

  return 0;
}

 /* wait for io completion */
Err
WaitIO(Item ior)
{
  UNIMPLEMENTED;

  return 0;
}

/* mp can be 0 */
Item
CreateIOReq(const char *name, uint8_t pri, Item dev, Item mp)
{
  UNIMPLEMENTED;

  return 0;
}
