#ifndef __3do_graphics_h__
#define __3do_graphics_h__

#include "types.h"
#include "list.h"

#include "graphics_ccb.h"
#include "graphics_celdata.h"
#include "graphics_coord.h"


/* Currently available values for DI_TYPE */
/* This will never be found in the structure, but is a dummy value that can be */
/* passed into Screen and VDL creation routines to get the default display type */
#define DI_TYPE_DEFAULT      0


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



Err EnableHAVG(Item screenItem);
Err EnableVAVG(Item screenItem);
Err SetCEControl(Item bitmapItem, int32 controlWord, int32 controlMask);

Item GetVRAMIOReq(void);

Item GetVBLIOReq(void);
Err WaitVBL(Item ioreq, uint32 numfields);


#endif /* __3do_graphics_h */
