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


/*----------------------------------------------------------------------------
 * prototypes for text-in-a-cel routines
 *--------------------------------------------------------------------------*/

TextCel *CreateTextCel(const FontDescriptor *fDesc, uint32 formatFlags, int32 width, int32 height);
void       DeleteTextCel(TextCel *tCel);

void SetTextCelColor(TextCel *tCel, int32 bgColor, int32 fgColor0);
void SetTextCelCoords(TextCel *tCel, Coord ccbX, Coord ccbY);
Err  SetTextCelSize(TextCel *tCel, int32 width, int32 height);

void   GetTextCelSize(TextCel *tCel, int32 *width, int32 *height);

Err UpdateTextInCel(TextCel *tCel, boolean replaceExisting, const char *fmtString, ...);

/*----------------------------------------------------------------------------
 * prototypes for render-direct-to-screen routines
 *--------------------------------------------------------------------------*/

void DrawTextString(FontDescriptor *fDesc, GrafCon *gcon, Item bitmapItem, const char *text, ...);


#endif /* __3do_textlib_h__ */
