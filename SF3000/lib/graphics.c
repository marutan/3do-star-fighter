#include <stdint.h>

#include "graphics.h"
#include "Star3000.h"
#include "item.h"

Err
DisplayScreen(Item screenItem0, Item screenItem1)
{
  UNIMPLEMENTED;

  return 0;
}

Err
EnableHAVG(Item screenItem)
{
  PASS;

  return 0;
}

Err
EnableVAVG(Item screenItem)
{
  PASS;

  return 0;
}

Err
FillRect(Item bitmapItem, GrafCon *gc, struct Rect *r)
{
  UNIMPLEMENTED;

  return 0;
}


/**
 * This call sets the cel engine control word of the bitmap specified by the
 * bitmapItem argument. After this call, the newly modified control word is
 * used whenever the bitmap renders cels. The controlMask argument controls
 * the bits of the bitmap's control word that are modified by a call to
 * SetCEControl().
 *
 * @param bitmapItem Item number of a bitmap structure
 * @param controlWord Value of the new control word for the bitmap.
 * @param controlMask Bit mask that controls whether the corresponding bit in
 *                    controlWord is transferred to the CEControl word. If the
 *                    controlMask bit is set, the corresponding bit in
 *                    controlWord is transferred to the CEControl word; if the
 *                    controlMask bit is clear, the corresponding bit in
 *                    controlWord is ignored.
 * @returns The call returns 0 if successful or an error code (a negative
 *          value) if an error occurs.
 */
Err
SetCEControl(Item bitmapItem, int32_t controlWord, int32_t controlMask)
{
  Bitmap *bitmap = LookupItem(bitmapItem);

  if(bitmap) {
    bitmap->bm_CEControl &= (controlWord & controlMask);
    return 0;
  }

  return -1;
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
}

/**
 * This call is a convenience call for SPORT device transfers. It creates and
 * returns an I/O request that is suitable for use with the SPORT transfer
 * calls.
 *
 * @returns This call returns the item number of the I/O request or an error
 *          code (a negative value) if an error occurs.
 */
Item
GetVRAMIOReq(void)
{
  PASS;

  // I suspect this function will be largely completely pointless in not
  // 3do land

  // No idea of the struct used
  Item retval = CreateSizedItem(0, NULL, sizeof(int32_t));
  if(retval >= 0) {
    return retval;
  }

  return -1;
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

/**
 * GetVBLIOReq() creates and returns an I/O request that is suitable for use
 * with the WaitVBL() and WaitVBLDefer() calls.
 *
 * @returns This call returns the item number of the I/O request or an error
 *          code (a negative value) if an error occurs.
 */
Item
GetVBLIOReq(void)
{
  PASS;

  // No idea of the struct used
  Item retval = CreateSizedItem(0, NULL, sizeof(int32_t));
  if(retval >= 0) {
    return retval;
  }

  return -1;
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

