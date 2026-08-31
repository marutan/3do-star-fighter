#include <stdio.h>
#include "kernel.h"

struct KernelBase theKernel =
{
  {
    {
      NULL,
      NULL,
      0,
      0, 0, 0, 0,
      NULL,
      0, 0, 0, 0,
      0, 0,
      NULL
    },
    0,
    0,
    0,
    0,
    0,
    0
  },          //  kb;
  NULL,       // kb_RomTags;
  NULL,       // kb_MemFreeLists;
  NULL,       // *kb_MemHdrList;
  NULL,       // *kb_FolioList;     /* Libraries */
  NULL,       // *kb_Drivers;
  NULL,       // *kb_Devices;
  NULL,       // *kb_TaskWaitQ;     /* Tasks waiting for some event */
  NULL,       // *kb_TaskReadyQ;    /* Tasks waiting for CPU time */
  NULL,       // *kb_MsgPorts;      /* will we be message based? */
  NULL,       // *kb_Semaphores;    /* will we be message based? */
  NULL,       // *kb_CurrentTask;   /* Currently executing Task */
  NULL,       // **kb_InterruptHandlers;
  0,          // kb_TimerBits;     /* allocated timers/ctrs */
  0,          // kb_ElapsedQuanta; /* timerticks for current task */
  NULL,       // *kb_VRAMHack;
  NULL,       // **kb_ItemTable;     /* table of ptrs to ItemEntries */
  0,          // kb_MaxItem;
  0,          // kb_CPUFlags;      /* various flags for operation */
  0,          // kb_MaxInterrupts;
  0,          // kb_Forbid;        /* software lockout for task swapping */
  0,          // kb_FolioTableSize;
  0,          // kb_PleaseReschedule;
  NULL,       //  *kb_MacPkt;
  0,          // kb_Flags;
  0,          // kb_Reserved;
  0,          // kb_numticks;      /* convert secs to ticks numerator */
  0,          // kb_denomticks;    /* convert secs to ticks denominator */
  0,          // kb_Obsolete;      /* shadow copy of Madam->Msysbits */
  0,          // kb_FolioTaskDataCnt; /* lwords */
  0,          // kb_FolioTaskDataSize; /* lwords */
  0,          // kb_DRAMSetSize;
  0,          // kb_VRAMSetSize;
  NULL,       // **kb_DataFolios;
  NULL,       // *kb_CatchDataAborts; /* setjmp buf */
  0,          // kb_QuietAborts;   /* no messages for these bits */
  NULL,       // *kb_RamDiskAddr;   /* kernel needs to help RamDevice */
  0,          // kb_RamDiskSize;
  NULL,       // *kb_ExtendedErrors; /* list of extended err tables */
  0,          // kb_MadamRev;
  0,          // kb_ClioRev;
  0,          // kb_Resbyte0;
  0,          // kb_Resbyte1;
  0,          // kb_DevSemaphore;  /* Device List Semaphore */
  NULL,       // *kb_SystemStackList; /* List of System stacks available */
};

struct KernelBase *KernelBase = &theKernel;

