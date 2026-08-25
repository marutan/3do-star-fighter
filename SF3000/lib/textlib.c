#include <stdint.h>
#include "textlib.h"
#include "Star3000.h"

TextCel *
CreateTextCel(const FontDescriptor *fDesc, uint32_t formatFlags, int32_t width, int32_t height)
{
  UNIMPLEMENTED;

  return NULL;
}

void
DeleteTextCel(TextCel *tCel)
{
  UNIMPLEMENTED;
}

void
SetTextCelColor(TextCel *tCel, int32_t bgColor, int32_t fgColor0)
{
  UNIMPLEMENTED;
}

void
SetTextCelCoords(TextCel *tCel, Coord ccbX, Coord ccbY)
{
  UNIMPLEMENTED;
}

Err
SetTextCelSize(TextCel *tCel, int32_t width, int32_t height)
{
  UNIMPLEMENTED;

  return 0;
}

void
GetTextCelSize(TextCel *tCel, int32_t *width, int32_t *height)
{
  UNIMPLEMENTED;
}

Err
UpdateTextInCel(TextCel *tCel, boolean replaceExisting, const char *fmtString, ...)
{
  UNIMPLEMENTED;

  return 0;
}

void
DrawTextString(FontDescriptor *fDesc, GrafCon *gcon, Item bitmapItem, const char *text, ...)
{
  UNIMPLEMENTED;
}
