#include <stdint.h>
#include "datastream.h"
#include "Star3000.h"

int32_t
InitDataStreaming(long maxNumberOfStreams)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
CloseDataStreaming(void)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
NewDataStream(DSStreamCBPtr *pCtx,
              void*          bufferListPtr,
              long           bufferSize,
              long           deltaPriority,
              long           numSubsMsgs)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DisposeDataStream(Item          msgItem,
                  DSStreamCBPtr streamCBPtr)
{
  UNIMPLEMENTED;

  return 0;
}
