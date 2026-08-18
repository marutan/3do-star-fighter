#ifndef __3do_graphics_h__
#define __3do_graphics_h__

#include "types.h"
#include "folio.h"
#include "list.h"
#include "hardware.h"

#include "graphics_ccb.h"
#include "graphics_celdata.h"
#include "graphics_coord.h"
#include "graphics_rect.h"

/* Currently available values for DI_TYPE */
/* This will never be found in the structure, but is a dummy value that can be */
/* passed into Screen and VDL creation routines to get the default display type */
#define DI_TYPE_DEFAULT      0

typedef uint32  Color;

typedef struct Bitmap
{
  ItemNode bm;

  ubyte *bm_Buffer;

  int32 bm_Width;
  int32 bm_Height;
  int32 bm_VerticalOffset;
  int32 bm_Flags;

  int32 bm_ClipWidth;
  int32 bm_ClipHeight;
  int32 bm_ClipX;
  int32 bm_ClipY;
  int32 bm_WatchDogCtr;  /* JCR */
  int32 bm_SysMalloc;  /* If set, CreateScreenGroup MALLOCED for bm. JCR */

  /* List of tasks that have share access to this Bitmap */
  List bm_SharedList;

  int32 bm_CEControl;
  int32 bm_REGCTL0;
  int32 bm_REGCTL1;
  int32 bm_REGCTL2;
  int32 bm_REGCTL3;
} Bitmap;

/* Graphics Context structure */
typedef struct GrafCon
{
  Node  gc;
  Color gc_FGPen;
  Color gc_BGPen;
  Coord gc_PenX;
  Coord gc_PenY;
  uint32 gc_Flags;
} GrafCon;

#define MakeRGB15(r,g,b) (((uint32)(r)<<10)|((uint32)(g)<<5)|(uint32)(b))

#define MakeCLUTColorEntry(index,r,g,b) ((((uint32)(index)<<24)|VDL_FULLRGB \
                                          |((uint32)(r)<<16)|((uint32)(g)<<8)|((uint32)(b))))

Err DisplayScreen(Item screenItem0, Item screenItem1);
Err EnableHAVG(Item screenItem);
Err EnableVAVG(Item screenItem);
Err FillRect(Item bitmapItem, GrafCon *gc, struct Rect *r);
Err SetCEControl(Item bitmapItem, int32 controlWord, int32 controlMask);
Err SetScreenColor(Item screenItem, uint32 colorEntry);
void SetFGPen(GrafCon *gc, Color c);

Item GetVRAMIOReq(void);
Err SetVRAMPages(Item ioreq, void *dest, int32 val, int32 numpages, int32 mask);
Err CopyVRAMPages(Item ioreq, void *dest, void *src, uint32 numpages, uint32 mask);


Item GetVBLIOReq(void);
Err WaitVBL(Item ioreq, uint32 numfields);
Err WaitVBLDefer(Item ioreq, uint32 numfields);

/***************************************************************************
 * Documented graphics SWI's.
 */
//__swi(_DRAWCELS) Err DrawCels(Item bitmapItem, CCB *ccb);
Err DrawCels(Item bitmapItem, CCB *ccb);


#endif /* __3do_graphics_h */
