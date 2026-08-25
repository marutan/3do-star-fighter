#include <stdint.h>
#include "displayutils.h"
#include "Star3000.h"

Item    sc_BitmapItems[MAXSCREENS]; /* bitmap item for the screen */


Item
CreateBasicDisplay(ScreenContext *sc, uint32_t displayType, uint32_t numScreens)
{
  UNIMPLEMENTED;

  return 0;
}

Err
DeleteBasicDisplay(ScreenContext *sc)
{
  UNIMPLEMENTED;

  return 0;
}

void *
LoadImage( char *filename, uint8_t *dest, VdlChunk **rawVDLPtr, ScreenContext *sc )
{
  UNIMPLEMENTED;

  return NULL;
}

void
FadeToBlack(ScreenContext *sc, int32_t nFrames)
{
  UNIMPLEMENTED;
}

void
FadeFromBlack(ScreenContext *sc, int32_t frameCount)
{
  UNIMPLEMENTED;
}

