#ifndef __3do_form3do_h
#define __3do_form3do_h

#include <stdint.h>

#include "types.h"
#include "graphics.h"

#define kCLUTWords 32

/***************************************/
/* NOTE:  VDL_REC will probably change */
/***************************************/
typedef struct VDL_REC
{
  uint32_t controlword;           /*      VDL display control word (+ number of int32words in this entry - 4) */
                                  /*      (+ number of lines that this vdl is in effect -1) */
  uint32_t curLineBuffer;         /*      1st byte of frame buffer */
  uint32_t prevLineBuffer;        /*      1st byte of frame buffer */
  uint32_t nextVDLEntry;          /*      GrafBase->gf_VDLPostDisplay for last VDL Entry */
  uint32_t displayControl;        /*      Setup control info: DEFAULT_DISPCTRL */
  uint32_t CLUTEntry[kCLUTWords]; /*      32 Clut entries for each R, G, and B */
  uint32_t backgroundEntry;       /*      RGB 000 will use this entry */
  uint32_t filler1;               /*      need 40 entries for now, hardware bug */
  uint32_t filler2;
} VDL_REC;

typedef struct VDLCHUNK         /* used for a standard 33 entry vdl list */
{
  int32_t chunk_ID;             /* 'VDL ' Magic number to identify VDL chunk */
  int32_t chunk_size;           /*      size in bytes of chunk including chunk_size */
  int32_t vdlcount;             /*      count of number of vdls following */
  VDL_REC vdl[1];               /*      VDL control words and entries  */
} VdlChunk;


#endif /* __3do_form3do_h */
