#ifndef __3do_displayutils_h__
#define __3do_displayutils_h__

#include "types.h"
#include "graphics.h"

#define MAXSCREENS 6

/* briefly describes a display */
typedef struct ScreenContext
{
  Item   sc_ScreenGroup;        /* associated screen group    */
  uint32 sc_DisplayType;        /* DI_TYPE_* from graphics.h  */

  uint32  sc_NumScreens;        /* # of screens created       */
  uint32  sc_CurrentScreen;     /* displayed screen           */
  Item    sc_ScreenItems[MAXSCREENS]; /* item for the screen        */
  Item    sc_BitmapItems[MAXSCREENS]; /* bitmap item for the screen */
  Bitmap *sc_Bitmaps[MAXSCREENS]; /* structure itself           */

  uint32 sc_NumBitmapPages;     /* # pages of memory for each bitmap */
  uint32 sc_NumBitmapBytes;     /* # bytes of memory for each bitmap */
  uint32 sc_BitmapBank;         /* bank of memory for all bitmaps    */
  uint32 sc_BitmapWidth;        /* pixel width of each bitmap        */
  uint32 sc_BitmapHeight;       /* pixel height of each bitmap       */
} ScreenContext;

Item    sc_BitmapItems[MAXSCREENS]; /* bitmap item for the screen */


Item     CreateBasicDisplay(ScreenContext *sc, uint32 displayType, uint32 numScreens);
Err      DeleteBasicDisplay(ScreenContext *sc);
void     FadeToBlack(ScreenContext *sc, int32 nFrames);
void     FadeFromBlack(ScreenContext *sc, int32 frameCount);

/* for compatibility only, do not use in new code */
/* PJH: is commented out in 3do-devkit */
#define OpenGraphics(sc,n) (CreateBasicDisplay(sc,DI_TYPE_DEFAULT,n) >= 0 ? TRUE : FALSE)
#define CloseGraphics(sc)  DeleteBasicDisplay(sc)



#endif /* __3do_displayutils_h__ */
