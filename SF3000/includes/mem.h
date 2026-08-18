#ifndef __3do_mem_h__
#define __3do_mem_h__

#include "types.h"
#include "list.h"
#include "item.h"
#include "kernel.h"

/* Memory Headers provide information on the type of memory they contain */
typedef struct MemHdr
{
  Node     memh_n;
  uint32   memh_Types;            /* MEMTYPE BITS              */
  int32    memh_PageSize;         /* basic page size           */
  uint32   memh_PageMask;
  int32    memh_VRAMPageSize;     /* basic page size           */
  uint32   memh_VRAMPageMask;
  uint32  *memh_FreePageBits;     /* bit per block             */
  uint8   *memh_MemBase;          /* range in these two values */
  uint8   *memh_MemTop;
  uint8    memh_FreePageBitsSize; /* in units (uint32s)        */
  uint8    memh_PageShift;
  uint8    memh_VRAMPageShift;
} MemHdr;


/****************************************************************************/


/* define location, size flags */
#define MEMTYPE_ANY             (uint32)0

/* memory type bits */
#define MEMTYPE_CEL             (uint32)0x00040000 /* accessable by cel engine  */


typedef struct MemList
{
  Node    meml_n;           /* need to link these together */
  uint32  meml_Types;       /* copy of meml_mh->memh_Types */
  uint32 *meml_OwnBits;     /* memory we own               */
  uint32 *meml_WriteBits;   /* memory we can write to      */
  MemHdr *meml_MemHdr;
  List   *meml_l;
  Item    meml_Sema4;
  uint8   meml_OwnBitsSize; /* in uint32s (fd_set)         */
  uint8   meml_Reserved[3];
  List   *meml_AlignedTrackSize;
} MemList;


#ifdef MEMDEBUG

#define AllocMemFromMemLists(l,s,t) AllocMemFromMemListsDebug(l,s,t,__FILE__,__LINE__,MEMDEBUG_CALL_ALLOCMEMFROMMEMLISTS)
#define FreeMemToMemLists(l,p,s)    FreeMemToMemListsDebug(l,p,s,__FILE__,__LINE__,MEMDEBUG_CALL_FREEMEMTOMEMLISTS)

#else

void *AllocMemFromMemLists(List *l, int32 size, uint32 typebits);
void FreeMemToMemLists(List *l, void *p, int32 size);

#endif


/****************************************************************************/

/* Useful macros */

#define AllocMem(s,t)   AllocMemFromMemLists(CURRENTTASK->t_FreeMemoryLists,s,t)
#define FreeMem(p,s)    FreeMemToMemLists(CURRENTTASK->t_FreeMemoryLists,p,s)
#define ALLOCMEM(s,t)   AllocMemFromMemLists(CURRENTTASK->t_FreeMemoryLists,s,t)

#endif /* __3do_mem_h__ */
