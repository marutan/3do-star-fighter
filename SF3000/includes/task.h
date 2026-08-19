#ifndef __3do_task_h__
#define __3do_task_h__

#include <stdint.h>

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
  uint32_t        t_Private0[2];
  uint32_t        t_WaitBits;   /* What will wake us up */
  uint32_t        t_SigBits;
  uint32_t        t_AllocatedSigs;
  uint32_t       *t_StackBase;  /* ptr to Base of stack */
  int32_t         t_StackSize;
  uint32_t        t_Private1[22];
  int32_t         t_SuperStackSize;
  uint32_t       *t_SuperStackBase;
  Item            t_WaitItem;   /* Item this task is waiting on */
  List           *t_FreeMemoryLists; /* task free memory pool */
  uint32_t        t_Private2[2];
  struct timeval  t_ElapsedTime;
  uint32_t        t_MaxTicks;   /* max tics b4 task switch */
  uint32_t        t_MaxUSecs;   /* Equivalent in usecs */
  uint32_t        t_Private3[2];
  uint32_t        t_NumTaskLaunch; /* # of times this task has been launched */
  uint32_t        t_Flags;      /* more task specific flags */
  MinNode         t_TasksLinkNode; /* Link to the list of all tasks */
} Task, *TaskP;



extern Item CreateThread(const char *name, uint8_t pri, void (*code)(), int32_t stacksize);

//extern int32_t __swi(KERNELSWI+1)  WaitSignal(uint32_t sigMask);
extern int32_t WaitSignal(uint32_t sigMask);
//extern Err   __swi(KERNELSWI+2)  SendSignal(Item task,uint32_t sigMask);
extern Err     SendSignal(Item task, uint32_t sigMask);
//extern int32 __swi(KERNELSWI+21) AllocSignal(uint32_t sigMask);
extern int32_t AllocSignal(uint32_t sigMask);
//extern Err   __swi(KERNELSWI+22) FreeSignal(uint32_t sigMask);
extern Err     FreeSignal(uint32_t sigMask);


#endif /* __3do_task_h__ */
