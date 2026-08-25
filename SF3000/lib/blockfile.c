#include <stdint.h>
#include "blockfile.h"
#include "Star3000.h"

Item
CreateBlockFileIOReq(Item deviceItem, Item iodoneReplyPort)
{
  UNIMPLEMENTED;

  return 0;
}

Err
OpenBlockFile(char *name, BlockFilePtr bf)
{
  UNIMPLEMENTED;

  return 0;
}

void
CloseBlockFile(BlockFilePtr bf)
{
  UNIMPLEMENTED;
}

Err
AsynchReadBlockFile(BlockFilePtr bf, Item ioreqItem, void* buffer, int32_t count, int32_t offset)
{
  UNIMPLEMENTED;

  return 0;
}

Err
WaitReadDoneBlockFile(Item ioreqItem)
{
  UNIMPLEMENTED;

  return 0;
}

