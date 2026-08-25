#ifndef __3do_fontlib_h__
#define __3do_fontlib_h__

#include <stdint.h>

#include "types.h"

/*----------------------------------------------------------------------------
 * Font internal datatypes
 *      Client code should not count on these things remaining as they are now.
 *--------------------------------------------------------------------------*/

#ifndef CHAR4LITERAL
#define CHAR4LITERAL(a,b,c,d)   ((unsigned long) (a<<24)|(b<<16)|(c<<8)|d)
#endif

typedef struct FontDescriptor
{
  uint32_t  fd_fontFlags;         /* Flags describing the font */
  uint32_t  fd_charHeight;        /* Height of character (ascent+descent) */
  uint32_t  fd_charWidth;         /* Max width of character (pixels) */
  uint32_t  fd_bitsPerPixel;      /* Pixel depth of each character, as stored in */
  uint32_t  fd_firstChar;         /* First char defined in character set */
  uint32_t  fd_lastChar;          /* Last char defined in character set */
  uint32_t  fd_charExtra;         /* Spacing between characters */
  uint32_t  fd_ascent;            /* Distance from baseline to ascentline */
  uint32_t  fd_descent;           /* Distance from baseline to descentline */
  uint32_t  fd_leading;           /* Distance from descent line to next ascent li */
  uint32_t  fd_reserved[4];       /* Reserved values from font file header. */
  void     *fd_userData;          /* Client code can store a value here. */
  void     *fd_fontHeader;        /* Font header information */
  void     *fd_charInfo;          /* Per-character data table */
  void     *fd_charData;          /* The character data */
} FontDescriptor;

/*----------------------------------------------------------------------------
 * Font file API
 *--------------------------------------------------------------------------*/

FontDescriptor *LoadFont(const char *fontFileName, uint32_t memTypeBits);
void            UnloadFont(FontDescriptor *fDesc);

#endif /* __3do_fontlib_h__ */
