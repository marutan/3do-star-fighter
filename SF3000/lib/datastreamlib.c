#include <stdint.h>
#include "datastreamlib.h"
#include "Star3000.h"

int32_t
DSSubscribe(Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
            DSDataType dataType, Item subscriberPort )
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DSStartStream(Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
              unsigned long startOptions )
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DSStopStream(Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
             unsigned long stopOptions)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DSSetChannel(Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
             DSDataType streamType, long channelNumber, long channelStatus )
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DSControl(Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
          DSDataType streamType, long userDefinedOpcode,
           void* userDefinedArgPtr )
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DSConnect(Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
          Item acquirePort)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DSSetClock(DSStreamCBPtr streamCBPtr, uint32_t newStreamClock)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DSWaitEndOfStream(Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr)
{
  UNIMPLEMENTED;

  return 0;
}

