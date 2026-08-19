#ifndef __3do_kernel_h__
#define __3do_kernel_h__

#include <stdint.h>

#include "types.h"
#include "item.h"
#include "list.h"
#include "item.h"
#include "folio.h"
#include "task.h"

#include <setjmp.h>

struct KernelBase
{
  Folio       kb;
  List       *kb_RomTags;
  List       *kb_MemFreeLists;
  List       *kb_MemHdrList;
  List       *kb_FolioList;     /* Libraries */
  List       *kb_Drivers;
  List       *kb_Devices;
  List       *kb_TaskWaitQ;     /* Tasks waiting for some event */
  List       *kb_TaskReadyQ;    /* Tasks waiting for CPU time */
  List       *kb_MsgPorts;      /* will we be message based? */
  List       *kb_Semaphores;    /* will we be message based? */
  Task       *kb_CurrentTask;   /* Currently executing Task */
  Node      **kb_InterruptHandlers;
  uint32_t    kb_TimerBits;     /* allocated timers/ctrs */
  uint32_t    kb_ElapsedQuanta; /* timerticks for current task */
  uint32_t   *kb_VRAMHack;
  ItemEntry **kb_ItemTable;     /* table of ptrs to ItemEntries */
  int32_t     kb_MaxItem;
  uint32_t    kb_CPUFlags;      /* various flags for operation */
  uint8_t     kb_MaxInterrupts;
  uint8_t     kb_Forbid;        /* software lockout for task swapping */
  uint8_t     kb_FolioTableSize;
  uint8_t     kb_PleaseReschedule;
  uint32_t   *kb_MacPkt;
  uint32_t    kb_Flags;
  uint32_t    kb_Reserved;
  uint32_t    kb_numticks;      /* convert secs to ticks numerator */
  uint32_t    kb_denomticks;    /* convert secs to ticks denominator */
  uint32_t    kb_Obsolete;      /* shadow copy of Madam->Msysbits */
  uint8_t     kb_FolioTaskDataCnt; /* lwords */
  uint8_t     kb_FolioTaskDataSize; /* lwords */
  uint8_t     kb_DRAMSetSize;
  uint8_t     kb_VRAMSetSize;
  Folio     **kb_DataFolios;
  jmp_buf    *kb_CatchDataAborts; /* setjmp buf */
  uint32_t    kb_QuietAborts;   /* no messages for these bits */
  uint32_t   *kb_RamDiskAddr;   /* kernel needs to help RamDevice */
  int32_t     kb_RamDiskSize;
  List       *kb_ExtendedErrors; /* list of extended err tables */
  uint8_t     kb_MadamRev;
  uint8_t     kb_ClioRev;
  uint8_t     kb_Resbyte0;
  uint8_t     kb_Resbyte1;
  Item        kb_DevSemaphore;  /* Device List Semaphore */
  List       *kb_SystemStackList; /* List of System stacks available */
  uint32_t    kb_NumTaskSwitches; /* total # of switch since bootup  */
  uint32_t   *kb_VRAM0;         /* memory reserved by kernel */
  uint32_t    kb_VRAM0Size;
  uint32_t   *kb_VRAM1;
  uint32_t    kb_VRAM1Size;
  char       *kb_BootVolumeName;
  List       *kb_Tasks;
  uint32_t    kb_MemEnd;        /* Address of end-of-memory */
};

extern struct KernelBase *KernelBase;

#define CURRENTTASK            (KernelBase->kb_CurrentTask)

#endif /* __3do_kernel_h__ */
