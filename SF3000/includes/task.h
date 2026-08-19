#ifndef __3do_task_h__
#define __3do_task_h__

#include "types.h"
#include "nodes.h"
#include "kernelnodes.h"
#include "item.h"
#include "list.h"
#include <sys/time.h>

typedef struct Task
{
  ItemNode        t;
  struct Task    *t_ThreadTask; /* Am I a thread of what task? */
  uint32          t_Private0[2];
  uint32          t_WaitBits;   /* What will wake us up */
  uint32          t_SigBits;
  uint32          t_AllocatedSigs;
  uint32         *t_StackBase;  /* ptr to Base of stack */
  int32           t_StackSize;
  uint32          t_Private1[22];
  int32           t_SuperStackSize;
  uint32         *t_SuperStackBase;
  Item            t_WaitItem;   /* Item this task is waiting on */
  List           *t_FreeMemoryLists; /* task free memory pool */
  uint32          t_Private2[2];
  struct timeval  t_ElapsedTime;
  uint32          t_MaxTicks;   /* max tics b4 task switch */
  uint32          t_MaxUSecs;   /* Equivalent in usecs */
  uint32          t_Private3[2];
  uint32          t_NumTaskLaunch; /* # of times this task has been launched */
  uint32          t_Flags;      /* more task specific flags */
  MinNode         t_TasksLinkNode; /* Link to the list of all tasks */
} Task, *TaskP;



extern Item CreateThread(const char *name, uint8 pri, void (*code)(),int32 stacksize);

//extern int32 __swi(KERNELSWI+1)  WaitSignal(uint32 sigMask);
extern int32 WaitSignal(uint32 sigMask);
//extern Err   __swi(KERNELSWI+2)  SendSignal(Item task,uint32 sigMask);
extern Err   SendSignal(Item task,uint32 sigMask);
//extern int32 __swi(KERNELSWI+21) AllocSignal(uint32 sigMask);
extern int32 AllocSignal(uint32 sigMask);
//extern Err   __swi(KERNELSWI+22) FreeSignal(uint32 sigMask);
extern Err   FreeSignal(uint32 sigMask);


#endif /* __3do_task_h__ */
