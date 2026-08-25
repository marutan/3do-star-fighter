#include <stdint.h>

#include "graphics.h"
#include "Star3000.h"

Err
DisplayScreen(Item screenItem0, Item screenItem1)
{
  UNIMPLEMENTED;

  return 0;
}

Err
EnableHAVG(Item screenItem)
{
  UNIMPLEMENTED;

  return 0;
}

Err
EnableVAVG(Item screenItem)
{
  UNIMPLEMENTED;

  return 0;
}

Err
FillRect(Item bitmapItem, GrafCon *gc, struct Rect *r)
{
  UNIMPLEMENTED;

  return 0;
}

Err
SetCEControl(Item bitmapItem, int32_t controlWord, int32_t controlMask)
{
  UNIMPLEMENTED;

  return 0;
}

Err
SetScreenColor(Item screenItem, uint32_t colorEntry)
{
  UNIMPLEMENTED;

  return 0;
}

void
SetFGPen(GrafCon *gc, Color c)
{
  UNIMPLEMENTED;

  return 0;
}

Item
GetVRAMIOReq(void)
{
  UNIMPLEMENTED;

  return 0;
}

Err
SetVRAMPages(Item ioreq, void *dest, int32_t val, int32_t numpages, int32_t mask)
{
  UNIMPLEMENTED;

  return 0;
}

Err
CopyVRAMPages(Item ioreq, void *dest, void *src, uint32_t numpages, uint32_t mask)
{
  UNIMPLEMENTED;

  return 0;
}

Item
GetVBLIOReq(void)
{
  UNIMPLEMENTED;

  return 0;
}

Err
WaitVBL(Item ioreq, uint32_t numfields)
{
  UNIMPLEMENTED;

  return 0;
}

Err
WaitVBLDefer(Item ioreq, uint32_t numfields)
{
  UNIMPLEMENTED;

  return 0;
}

Err
DrawCels(Item bitmapItem, CCB *ccb)
{
  UNIMPLEMENTED;

  return 0;
}

