#ifndef __3do_graphics_h__
#define __3do_graphics_h__

#include <stdint.h>

#include "types.h"
#include "folio.h"
#include "list.h"
#include "operror.h"
#include "hardware.h"

#include "graphics_ccb.h"
#include "graphics_celdata.h"
#include "graphics_coord.h"
#include "graphics_rect.h"

/* Currently available values for DI_TYPE */
/* This will never be found in the structure, but is a dummy value that can be */
/* passed into Screen and VDL creation routines to get the default display type */
#define DI_TYPE_DEFAULT      0

typedef uint32_t  Color;

typedef struct Bitmap
{
  ItemNode bm;

  uint8_t *bm_Buffer;

  int32_t bm_Width;
  int32_t bm_Height;
  int32_t bm_VerticalOffset;
  int32_t bm_Flags;

  int32_t bm_ClipWidth;
  int32_t bm_ClipHeight;
  int32_t bm_ClipX;
  int32_t bm_ClipY;
  int32_t bm_WatchDogCtr;  /* JCR */
  int32_t bm_SysMalloc;  /* If set, CreateScreenGroup MALLOCED for bm. JCR */

  /* List of tasks that have share access to this Bitmap */
  List bm_SharedList;

  int32_t bm_CEControl;
  int32_t bm_REGCTL0;
  int32_t bm_REGCTL1;
  int32_t bm_REGCTL2;
  int32_t bm_REGCTL3;
} Bitmap;

/* Graphics Context structure */
typedef struct GrafCon
{
  Node  gc;
  Color gc_FGPen;
  Color gc_BGPen;
  Coord gc_PenX;
  Coord gc_PenY;
  uint32_t gc_Flags;
} GrafCon;

#define MakeRGB15(r, g, b) (((uint32_t)(r) << 10) | ((uint32_t)(g) << 5) | (uint32_t)(b))

#define MakeCLUTColorEntry(index, r, g, b) ((((uint32_t)(index) << 24) | VDL_FULLRGB \
                                          | ((uint32_t)(r) << 16) | ((uint32_t)(g) << 8) | ((uint32_t)(b))))

Err DisplayScreen(Item screenItem0, Item screenItem1);
Err EnableHAVG(Item screenItem);
Err EnableVAVG(Item screenItem);
Err FillRect(Item bitmapItem, GrafCon *gc, struct Rect *r);
Err SetCEControl(Item bitmapItem, int32_t controlWord, int32_t controlMask);
Err SetScreenColor(Item screenItem, uint32_t colorEntry);
void SetFGPen(GrafCon *gc, Color c);

Item GetVRAMIOReq(void);
Err SetVRAMPages(Item ioreq, void *dest, int32_t val, int32_t numpages, int32_t mask);
Err CopyVRAMPages(Item ioreq, void *dest, void *src, uint32_t numpages, uint32_t mask);


Item GetVBLIOReq(void);
Err WaitVBL(Item ioreq, uint32_t numfields);
Err WaitVBLDefer(Item ioreq, uint32_t numfields);

/***************************************************************************
 * Documented graphics SWI's.
 */
//__swi(_DRAWCELS) Err DrawCels(Item bitmapItem, CCB *ccb);
Err DrawCels(Item bitmapItem, CCB *ccb);


#endif /* __3do_graphics_h */
