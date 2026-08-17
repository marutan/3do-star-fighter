#ifndef __3do_textlib_h__
#define __3do_textlib_h__

#include "fontlib.h"
#include "graphics.h"

typedef struct TextCel
{
  CCB            *tc_CCB;       /* pointer to CCB containing the text */
  void           *tc_userData;  /* client code can store a value here */
  FontDescriptor *tc_fontDesc;  /* everything from here down is internal-use-only */
  int32           tc_fontAdjustSpacing;
  int32           tc_fontAdjustLeading;
  uint32          tc_formatFlags;
  char           *tc_formatBuffer;
  uint32          tc_formatBufferSize;
  int32           tc_XPosInCel;
  int32           tc_YPosInCel;
  int32           tc_leftMargin;
  int32           tc_topMargin;
  int32           tc_penNumber;
  int32           tc_celRowBytes;
  uint32          tc_bgColor;
  uint32          tc_fgColor[4];
  uint16          tc_tabStops[16];
} TextCel;


#endif /* __3do_textlib_h__ */
