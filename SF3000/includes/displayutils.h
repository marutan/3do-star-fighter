#ifndef __3do_displayutils_h__
#define __3do_displayutils_h__

#include <stdint.h>

#include "types.h"
#include "graphics.h"
#include "form3do.h"

#define MAXSCREENS 6

/* briefly describes a display */
typedef struct ScreenContext
{
  Item     sc_ScreenGroup;        /* associated screen group    */
  uint32_t sc_DisplayType;        /* DI_TYPE_* from graphics.h  */

  uint32_t  sc_NumScreens;        /* # of screens created       */
  uint32_t  sc_CurrentScreen;     /* displayed screen           */
  Item      sc_ScreenItems[MAXSCREENS]; /* item for the screen        */
  Item      sc_BitmapItems[MAXSCREENS]; /* bitmap item for the screen */
  Bitmap   *sc_Bitmaps[MAXSCREENS]; /* structure itself           */

  uint32_t  sc_NumBitmapPages;     /* # pages of memory for each bitmap */
  uint32_t  sc_NumBitmapBytes;     /* # bytes of memory for each bitmap */
  uint32_t  sc_BitmapBank;         /* bank of memory for all bitmaps    */
  uint32_t  sc_BitmapWidth;        /* pixel width of each bitmap        */
  uint32_t  sc_BitmapHeight;       /* pixel height of each bitmap       */
} ScreenContext;

Item    sc_BitmapItems[MAXSCREENS]; /* bitmap item for the screen */


Item     CreateBasicDisplay(ScreenContext *sc, uint32_t displayType, uint32_t numScreens);
Err      DeleteBasicDisplay(ScreenContext *sc);
void    *LoadImage( char *filename, uint8_t *dest, VdlChunk **rawVDLPtr, ScreenContext *sc );
void     FadeToBlack(ScreenContext *sc, int32_t nFrames);
void     FadeFromBlack(ScreenContext *sc, int32_t frameCount);

/* for compatibility only, do not use in new code */
/* PJH: is commented out in 3do-devkit */
#define OpenGraphics(sc,n) (CreateBasicDisplay(sc,DI_TYPE_DEFAULT,n) >= 0 ? TRUE : FALSE)
#define CloseGraphics(sc)  DeleteBasicDisplay(sc)



#endif /* __3do_displayutils_h__ */
