#include <stdint.h>

#include "graphics.h"
#include "Star3000.h"
#include "item.h"


/**
 * This call displays the bitmap(s) of the specified screen (or screens). The
 * screenItem0 argument specifies the screen to be added to the display. For a
 * stereoscopic or interlaced display, the screenItem1 argument can specify a
 * second screen structure to be displayed in the odd field of the video frame.
 *
 * The second argument can be NULL, or the same as the first, to specify a
 * simple single-screen display.
 *
 * @param screenItem0 Item number of the screen that is to be added to the
 *                    display.
 * @param screenItem1 Optional item number of the screen that is to be added
 *                    to the second (the odd) field of the display frame.
 * @returns The call returns 0 if successful or an error code (a negative
 *          value) if an error occurs.
 */
Err
DisplayScreen(Item screenItem0, Item screenItem1)
{
  PASS;
  ASSERT(screenItem0 > 0);
  ASSERT(screenItem1 == 0);

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


/**
 * FillRect() draws a rectangle to the display.
 *
 * The right and bottom edges of the rectangle are not drawn, to allow
 * multiple rectangles to be rendered without unnecessary overstriking of the
 * boundary pixels (cel engine emulation).
 *
 * @param bitmapItem The item number of the bitmap.
 * @param gc Pointer to a GrafCon structure.
 * @param r Pointer to a Rect structure that describes the rectangle to be
 *          rendered.
 * @returns The call returns 0 if successful or an error code (a negative
 *          value) if an error occurs.
 */
Err
FillRect(Item bitmapItem, GrafCon *gc, struct Rect *r)
{
  PASS;

  ASSERT(gc);
  ASSERT(r);

  // Should we clip the rectangle to make sure it's on the bitmap?

  Bitmap *bitmap = LookupItem(bitmapItem);
  ASSERT(bitmap);

  // Actually do some plotting ...

  // Insert SDL cleverness here

  // Colour is in gc->gc_FGPen

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

/**
 * This call sets the foreground pen of the specified GrafCon to the specified
 * color. The color value is a coded 15-bit RGB format value, with each 5-bit
 * value acting as an index into the CLUT color registers. After this call,
 * the imagery part of the text (and other graphics elements that use the
 * foreground pen, including line drawing, rectangle and ellipse rendering) is
 * rendered in the new foreground color.
 *
 * The color values produced are different from the color values produced by
 * MakeCLUTColorEntry().
 *
 * @param gc Pointer to a GrafCon structure.
 *
 * @param c Value to be stored as the new foreground pen color.
 */
void
SetFGPen(GrafCon *gc, Color c)
{
  ASSERT(gc);

  gc->gc_FGPen = c;
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

