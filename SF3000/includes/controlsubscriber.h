#ifndef __3do_controlsubscriber_h__
#define __3do_controlsubscriber_h__

#include "types.h"
#include "subscriberutils.h"
#include "itempool.h"
#include "datastreamlib.h"

#define CTRL_MAX_CHANNELS      1 /* max # of logical channels per subscription */

typedef struct CtrlContext
{
  Item          creatorTask;    /* who to signal when we're done initializing */
  uint32        creatorSignal;  /* signal to send for synchronous completion */
  int32         creatorStatus;  /* result code for creator */
  DSStreamCBPtr streamCBPtr;    /* Ptr to the stream's context block */

  Item  threadItem;             /* subscriber thread item */
  void* threadStackBlock;       /* pointer to thread's stack memory block */

  Item   requestPort;           /* message port item for subscriber requests */
  uint32 requestPortSignal;     /* signal to detect request port messages */

  Item       dsReqReplyPort;    /* reply port for requests to streamer */
  uint32     dsReqReplyPortSignal; /* signal for replies to streamer requests */
  MemPoolPtr dsReqMsgPool;      /* pool of message blocks for requests to streamer */

  Item       subsReplyPort;     /* reply port for subscriber broadcasts */
  uint32     subsReplyPortSignal; /* signal for subscriber reply port */
  MemPoolPtr subsMsgPool;       /* pool of subscriber message blocks */

  Item    cueItem;              /* audio cue item for scheduling output */
  uint32  cueSignal;            /* signal associated with cueItem */
  boolean fTimerRunning;        /* flag: timer currently running */
  uint32  timerOwner;           /* subchunk processing that is using the timer */

  uint32 newClockTime;          /* set stream clock to this when we wake from timer */

  int32       numChannels;
  SubsChannel channel[CTRL_MAX_CHANNELS]; /* an array of channels */
} CtrlContext, *CtrlContextPtr;


int32 InitCtrlSubscriber(void);
int32 CloseCtrlSubscriber(void);

int32 NewCtrlSubscriber(CtrlContextPtr *pCtx, DSStreamCBPtr     streamCBPtr, int32 priority);
int32 DisposeCtrlSubscriber(CtrlContextPtr ctx);

#endif /* __3do_controlsubscriber_h__ */

