#include <stdint.h>
#include "cpaksubscriber.h"
#include "Star3000.h"

int32_t
InitCPakSubscriber(void)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
CloseCPakSubscriber(void)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
NewCPakSubscriber(CPakContextPtr *pCtx, int32_t numChannels, int32_t priority)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DisposeCPakSubscriber(CPakContextPtr ctx)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
InitCPakCel(DSStreamCBPtr   streamCBPtr,
            CPakContextPtr  ctx,
            CPakRecPtr     *pCPRecPtr,
            int32_t           channel,
            boolean         flushOnSync)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
DestroyCPakCel(CPakContextPtr ctx, CPakRecPtr cpRecPtr, int32_t channel)
{
  UNIMPLEMENTED;

  return 0;
}

void
DrawCPakToBuffer(CPakContextPtr ctx, CPakRecPtr cpRecPtr, Bitmap *bitmap)
{
  UNIMPLEMENTED;
}

void
FlushCPakChannel(CPakContextPtr ctx, CPakRecPtr cpRecPtr, int32_t channel)
{
  UNIMPLEMENTED;
}

int32_t
SendFreeCPakSignal(CPakContextPtr ctx)
{
  UNIMPLEMENTED;

  return 0;
}

