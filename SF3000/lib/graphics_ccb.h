#ifndef __3do_graphics_ccb_h__
#define __3do_graphics_ccb_h__

#include <stdint.h>

#include "graphics_celdata.h"
#include "graphics_coord.h"
#include "types.h"

typedef struct CCB CCB;
struct CCB
{
  uint32_t ccb_Flags;

  CCB     *ccb_NextPtr;
  CelData *ccb_SourcePtr;
  void    *ccb_PLUTPtr;

  Coord    ccb_XPos;
  Coord    ccb_YPos;
  int32_t  ccb_HDX;
  int32_t  ccb_HDY;
  int32_t  ccb_VDX;
  int32_t  ccb_VDY;
  int32_t  ccb_HDDX;
  int32_t  ccb_HDDY;
  uint32_t ccb_PIXC;
  uint32_t ccb_PRE0;
  uint32_t ccb_PRE1;

  /* These are special fields, tacked on to support some of the
   * rendering functions.
   */
  int32_t ccb_Width;
  int32_t ccb_Height;
};


#endif /* __3do_graphics_ccb_h__ */
