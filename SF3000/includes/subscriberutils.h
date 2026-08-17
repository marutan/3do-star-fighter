#ifndef __3do_subscriberutils_h__
#define __3do_subscriberutils_h__

#include "datastreamlib.h"

#include "subschunkcommon.h"

typedef struct SubsQueue {
  SubscriberMsgPtr      head;                   /* head of message queue */
  SubscriberMsgPtr      tail;                   /* tail of message queue */
} SubsQueue, *SubsQueuePtr;


typedef struct SubsChannel {
  unsigned long         status;                 /* state bits */
  SubsQueue                     msgQueue;               /* queue of subscriber messages */
} SubsChannel, *SubsChannelPtr;


#endif /* __3do_subscriberutils_h__ */
