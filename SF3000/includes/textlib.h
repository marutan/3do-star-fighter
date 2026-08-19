#ifndef __3do_textlib_h__
#define __3do_textlib_h__

#include <stdint.h>

#include "fontlib.h"
#include "graphics.h"

typedef struct TextCel
{
  CCB            *tc_CCB;       /* pointer to CCB containing the text */
  void           *tc_userData;  /* client code can store a value here */
  FontDescriptor *tc_fontDesc;  /* everything from here down is internal-use-only */
  int32_t         tc_fontAdjustSpacing;
  int32_t         tc_fontAdjustLeading;
  uint32_t        tc_formatFlags;
  char           *tc_formatBuffer;
  uint32_t        tc_formatBufferSize;
  int32_t         tc_XPosInCel;
  int32_t         tc_YPosInCel;
  int32_t         tc_leftMargin;
  int32_t         tc_topMargin;
  int32_t         tc_penNumber;
  int32_t         tc_celRowBytes;
  uint32_t        tc_bgColor;
  uint32_t        tc_fgColor[4];
  uint16_t        tc_tabStops[16];
} TextCel;


/*----------------------------------------------------------------------------
 * prototypes for text-in-a-cel routines
 *--------------------------------------------------------------------------*/

TextCel *CreateTextCel(const FontDescriptor *fDesc, uint32_t formatFlags, int32_t width, int32_t height);
void       DeleteTextCel(TextCel *tCel);

void SetTextCelColor(TextCel *tCel, int32_t bgColor, int32_t fgColor0);
void SetTextCelCoords(TextCel *tCel, Coord ccbX, Coord ccbY);
Err  SetTextCelSize(TextCel *tCel, int32_t width, int32_t height);

void   GetTextCelSize(TextCel *tCel, int32_t *width, int32_t *height);

Err UpdateTextInCel(TextCel *tCel, boolean replaceExisting, const char *fmtString, ...);

/*----------------------------------------------------------------------------
 * prototypes for render-direct-to-screen routines
 *--------------------------------------------------------------------------*/

void DrawTextString(FontDescriptor *fDesc, GrafCon *gcon, Item bitmapItem, const char *text, ...);


#endif /* __3do_textlib_h__ */
