#ifndef __3do_dataacq_h__
#define __3do_dataacq_h__

#include <stdint.h>

#include "blockfile.h"
#include "datastream.h"
#include "itempool.h"

/********************************************************/
/* Acquisition context, one per open acquisition stream */
/********************************************************/
typedef struct AcqContext
{
  Item     creatorTask;           /* who to signal when we're done initializing */
  uint32_t creatorSignal;         /* signal to send for synchronous completion */
  int32_t  creatorStatus;         /* result code for creator */
  char*    fileName;              /* pointer to file name string at init time */

  ItemPoolPtr ioReqItemPoolPtr; /* a pool of ioReqItems for the DataBufs to use */

  Item  threadItem;             /* The thread Item for the server process */
  void* threadStackBlock;       /* pointer to thread's stack memory block */

  Item     requestPort;           /* message port for data acquisition requests */
  uint32_t requestPortSignal;     /* signal associated with requestPort */

  Item     ioDoneReplyPort;       /* message port for I/O completion messages */
  uint32_t ioDoneReplyPortSignal; /* signal associated with ioDoneReplyPort */

  DataAcqMsgPtr requestQueue;   /* list of outstanding I/O request messages */

  DataAcqMsgPtr abortQueue;     /* list of outstanding I/O request messages ... */
  /* ... that are considered 'aborted' */

#if ALLOW_REQUEST_OVERLOADING
  DataAcqMsgPtr dataQueueHead;  /* head of requests waiting for ioreqitems */
  DataAcqMsgPtr dataQueueTail;  /* tail of requests waiting for ioreqitems */
#endif

  boolean   fEOFWasSent;        /* true if we sent an EOF to the parser */
  long      offset;             /* file position offset */
  BlockFile blockFile;          /* block file associated with this context */

#if TIME_BASED_BRANCHING
  Item     dsReqReplyPort;        /* reply port for requests to streamer */
  uint32_t dsReqReplyPortSignal;  /* signal for replies to streamer requests */

  uint32_t subscriberPortSignal;  /* signal for receipt of subscriber messages */
  Item     subscriberPort;        /* message port for our data type */

  DSStreamCBPtr streamCBPtr;    /* stream control block of stream we are connected to */

  MarkerChunkPtr markerChunk;   /* pointer to copy of most recent tranlation table */
#endif

} AcqContext, *AcqContextPtr;

int32_t InitDataAcq(int32_t dataAcqCount);
int32_t CloseDataAcq(void);

int32_t NewDataAcq(AcqContextPtr *pCtx, char* fileName, long deltaPriority);
void  DisposeDataAcq(AcqContextPtr ctx);

#endif /* __3do_dataacq_h__ */
