#ifndef __3do_fontlib_h__
#define __3do_fontlib_h__

typedef struct FontDescriptor
{
  uint32  fd_fontFlags;         /* Flags describing the font */
  uint32  fd_charHeight;        /* Height of character (ascent+descent) */
  uint32  fd_charWidth;         /* Max width of character (pixels) */
  uint32  fd_bitsPerPixel;      /* Pixel depth of each character, as stored in >
  uint32  fd_firstChar;         /* First char defined in character set */
  uint32  fd_lastChar;          /* Last char defined in character set */
  uint32  fd_charExtra;         /* Spacing between characters */
  uint32  fd_ascent;            /* Distance from baseline to ascentline */
  uint32  fd_descent;           /* Distance from baseline to descentline */
  uint32  fd_leading;           /* Distance from descent line to next ascent li>
  uint32  fd_reserved[4];       /* Reserved values from font file header. */
  void   *fd_userData;          /* Client code can store a value here. */
  void   *fd_fontHeader;        /* Font header information */
  void   *fd_charInfo;          /* Per-character data table */
  void   *fd_charData;          /* The character data */
} FontDescriptor;

#endif /* __3do_fontlib_h__ */
