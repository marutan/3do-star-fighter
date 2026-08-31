#include <stdlib.h>
#include <stdint.h>
#include "displayutils.h"
#include "Star3000.h"

Item    sc_BitmapItems[MAXSCREENS]; /* bitmap item for the screen */


Item
CreateBasicDisplay(ScreenContext *sc, uint32_t displayType, uint32_t numScreens)
{
  ASSERT(sc);

  // Only support the subset that SF3000 uses
  ASSERT(numScreens == 2);
  ASSERT(displayType == DI_TYPE_DEFAULT);

  // Set some values in the struct
  sc->sc_ScreenGroup = -1; // Hope this is unused
  sc->sc_DisplayType = DI_TYPE_DEFAULT;
  sc->sc_NumScreens = numScreens;
  sc->sc_CurrentScreen = 0;
  sc->sc_NumBitmapPages = 0; // Hope this is unused
  sc->sc_NumBitmapBytes = 0; // Hope this is unused
  sc->sc_BitmapBank = 0;
  sc->sc_BitmapWidth = 320;
  sc->sc_BitmapHeight = 240;

  // Create the entries in the sc_ScreenItems[] array ?
  // These two entries seem to only be used in the EnableHAVG
  // and EnableVAVG funcs, that are pretty much unused atm
  // Don't know what type or size they're meant to be
  sc->sc_ScreenItems[0] = CreateSizedItem(0, 0, sizeof(int32_t));
  sc->sc_ScreenItems[1] = CreateSizedItem(0, 0, sizeof(int32_t));

  // Create the entries in the sc_BitmapItems[] array ?
  sc->sc_BitmapItems[0] = CreateSizedItem(0, 0, sizeof(Bitmap));
  sc->sc_BitmapItems[1] = CreateSizedItem(0, 0, sizeof(Bitmap));

  // Create the entries in the sc_Bitmaps[] array ?
  sc->sc_Bitmaps[0] = LookupItem(sc->sc_BitmapItems[0]);
  sc->sc_Bitmaps[1] = LookupItem(sc->sc_BitmapItems[1]);

  // Create the raw frame buffers inside the bitmap struct ?
  // 16 bit graphics
  sc->sc_Bitmaps[0]->bm_Buffer = calloc(1, 320 * 240 * sizeof(uint16_t));
  sc->sc_Bitmaps[1]->bm_Buffer = calloc(1, 320 * 240 * sizeof(uint16_t));

  // Set some values in the Bitmap struct
  sc->sc_Bitmaps[0]->bm_Width = 320;
  sc->sc_Bitmaps[1]->bm_Width = 320;
  sc->sc_Bitmaps[0]->bm_Height = 240;
  sc->sc_Bitmaps[1]->bm_Height = 240;

  // OK at this point we've rather pretended to be a 3do enough, let's
  // try and make something appear on the screen in SDL land

  PASS;

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

