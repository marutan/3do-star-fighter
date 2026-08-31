#include <stdint.h>
#include "task.h"
#include "Star3000.h"

/**
 * This procedure creates a thread. The resulting thread belongs to the
 * calling task.
 *
 * @param name The name of the thread to be created (see "Notes").
 * @param pri The priority of the thread. This can be a value from 11 to 199
 *            (0 to 10 and 200 to 255 can only be assigned by system software).
 *            A larger number specifies a higher priority. For all tasks,
 *            including threads, the highest priority task - if there is only
 *            one task with that priority - is always the task that is
 *            executed. If more than one task in the ready queue has the
 *            highest priority, the kernel divides the available CPU time
 *            among the tasks by providing each task with a time quantum.
 * @param code A pointer to the code that the thread executes.
 * @param stacksize The size of the thread's stack, in bytes (see "Notes").
 * @returns The procedure returns the item number of the thread or an error
 *          code if an error occurs.
 */
Item
CreateThread(const char *name, uint8_t pri, void (*code)(), int32_t stacksize)
{
  ASSERT(name);
  ASSERT(pri == 101);
  ASSERT(code);
  ASSERT(stacksize <= 4096);

  Item retval = CreateSizedItem(0, NULL, sizeof(int32_t));

  PASS;

  return retval;
}


/**
 * This procedure puts the calling task into wait state until any of the
 * signal(s) specified in the sigMask have been received. When a task is in
 * wait state, it uses no CPU time.
 *
 * When WaitSignal() returns, bits set in the result indicate which of the
 * signal(s) the task was waiting for were received since the last call to
 * WaitSignal(). (The SIGF_ABORTED bit is also set if that signal was
 * received, even if it is not in the signal mask.) If the task was not
 * waiting for certain signals, the bits for those signals remain set in the
 * task's signal word, and all other bits in the signal word are cleared.
 *
 * See AllocSignal() for a description of the implementation of signals.
 *
 * @param sigMask A mask in which bits are set to specify the signals the task
 *                wants to wait for.
 * @returns The procedure returns a mask that specifies which of the signal(s)
 *          a task was waiting for have been received or an error code (a negative value) if an error occurs.
 */
int32_t
WaitSignal(uint32_t sigMask)
{
  PASS;

  return 0;
}

Err
SendSignal(Item task, uint32_t sigMask)
{
  UNIMPLEMENTED;

  return 0;
}


int32_t
AllocSignal(uint32_t sigMask)
{
  PASS;

  return 0;
}

/**
 * This procedure frees one or more signal bits allocated by AllocSignal().
 * The freed bits can then be reallocated.
 *
 * For information about signals, see the description of the AllocSignal()
 * procedure and the "Communicating Among Tasks" chapter in the 3DO Portfolio
 * Programmer's Guide.
 *
 * @param sigMask A 32-bit value in which any signal bits to deallocate are
 *                set. The bits are numbered from 0 (the least-significant bit)
 *                to 31 (the most-significant bit). Bits 0 through 7 and bit 31
 *                cannot be freed.
 * @returns The procedure returns 0 if the signal(s) were freed successfully
 *          or an error code if an error occurs.
 */
Err
FreeSignal(uint32_t sigMask)
{
  PASS;

  return 0;
}


