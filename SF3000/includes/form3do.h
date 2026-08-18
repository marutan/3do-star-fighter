#ifndef __3do_form3do_h
#define __3do_form3do_h

#include "types.h"
#include "graphics.h"

#define kCLUTWords 32

/***************************************/
/* NOTE:  VDL_REC will probably change */
/***************************************/
typedef struct VDL_REC
{
  uint32 controlword;           /*      VDL display control word (+ number of int32words in this entry - 4) */
                                /*      (+ number of lines that this vdl is in effect -1) */
  uint32 curLineBuffer;         /*      1st byte of frame buffer */
  uint32 prevLineBuffer;        /*      1st byte of frame buffer */
  uint32 nextVDLEntry;          /*      GrafBase->gf_VDLPostDisplay for last VDL Entry */
  uint32 displayControl;        /*      Setup control info: DEFAULT_DISPCTRL */
  uint32 CLUTEntry[kCLUTWords]; /*      32 Clut entries for each R, G, and B */
  uint32 backgroundEntry;       /*      RGB 000 will use this entry */
  uint32 filler1;               /*      need 40 entries for now, hardware bug */
  uint32 filler2;
} VDL_REC;

typedef struct VDLCHUNK         /* used for a standard 33 entry vdl list */
{
  int32   chunk_ID;             /* 'VDL ' Magic number to identify VDL chunk */
  int32   chunk_size;           /*      size in bytes of chunk including chunk_size */
  int32   vdlcount;             /*      count of number of vdls following */
  VDL_REC vdl[1];               /*      VDL control words and entries  */
} VdlChunk;


#endif /* __3do_form3do_h */
