#ifndef __3do_mem_h__
#define __3do_mem_h__

#include <stdlib.h>
#include <stdint.h>

#include "types.h"
#include "list.h"
#include "item.h"
#include "kernel.h"

/* Memory Headers provide information on the type of memory they contain */
typedef struct MemHdr
{
  Node       memh_n;
  uint32_t   memh_Types;            /* MEMTYPE BITS              */
  int32_t    memh_PageSize;         /* basic page size           */
  uint32_t   memh_PageMask;
  int32_t    memh_VRAMPageSize;     /* basic page size           */
  uint32_t   memh_VRAMPageMask;
  uint32_t  *memh_FreePageBits;     /* bit per block             */
  uint8_t   *memh_MemBase;          /* range in these two values */
  uint8_t   *memh_MemTop;
  uint8_t    memh_FreePageBitsSize; /* in units (uint32_t's)        */
  uint8_t    memh_PageShift;
  uint8_t    memh_VRAMPageShift;
} MemHdr;


/****************************************************************************/


/* define location, size flags */
#define MEMTYPE_ANY             (uint32_t)0

/* memory type bits */
#define MEMTYPE_CEL             (uint32_t)0x00040000 /* accessable by cel engine  */


typedef struct MemList
{
  Node      meml_n;           /* need to link these together */
  uint32_t  meml_Types;       /* copy of meml_mh->memh_Types */
  uint32_t *meml_OwnBits;     /* memory we own               */
  uint32_t *meml_WriteBits;   /* memory we can write to      */
  MemHdr   *meml_MemHdr;
  List     *meml_l;
  Item      meml_Sema4;
  uint8_t   meml_OwnBitsSize; /* in uint32_t's (fd_set)         */
  uint8_t   meml_Reserved[3];
  List     *meml_AlignedTrackSize;
} MemList;


#ifdef MEMDEBUG

#define AllocMemFromMemLists(l,s,t) AllocMemFromMemListsDebug(l,s,t,__FILE__,__LINE__,MEMDEBUG_CALL_ALLOCMEMFROMMEMLISTS)
#define FreeMemToMemLists(l,p,s)    FreeMemToMemListsDebug(l,p,s,__FILE__,__LINE__,MEMDEBUG_CALL_FREEMEMTOMEMLISTS)

#else

//void *AllocMemFromMemLists(List *l, int32_t size, uint32_t typebits);
//void FreeMemToMemLists(List *l, void *p, int32_t size);

#endif


/****************************************************************************/

/* Useful macros */

//#define AllocMem(s,t)   AllocMemFromMemLists(CURRENTTASK->t_FreeMemoryLists,s,t)
//#define FreeMem(p,s)    FreeMemToMemLists(CURRENTTASK->t_FreeMemoryLists,p,s)
//#define ALLOCMEM(s,t)   AllocMemFromMemLists(CURRENTTASK->t_FreeMemoryLists,s,t)

#define AllocMem(s,t) calloc(1, (s))
#define FreeMem(p,s)  free((p))
#define ALLOCMEM(s,t) calloc(1, (s))

#endif /* __3do_mem_h__ */
