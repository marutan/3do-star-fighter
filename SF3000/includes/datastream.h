#ifndef __3do_datastream_h__
#define __3do_datastream_h__

#include <stdint.h>

#include "types.h"
#include "io.h"
#include "mempool.h"
#include "haltchunk.h"
#include "operror.h"


/* The following constant is the maximum number of subscribers allowed for
 * a stream. The number should be kept small to minimize the search needed
 * on a per chunk basis.
 */
#define DS_MAX_SUBSCRIBERS 16


/***************/
/* Basic types */
/***************/
typedef unsigned long DSDataType;
typedef unsigned long *DSChunkPtr;

/*******************************************************************************************
 *              Data buffer structures
 *******************************************************************************************/

/* This is the basic data buffer structure managed by the stream parser. Each
 * buffer is obtained from the stream's data acquisition component and must PHYSICALLY
 * look exactly like the following. The first part of every physical data buffer
 * must contain the header information described by this struct. The actual data
 * component of a DSDataBuf can be a different length for each stream. However, buffer
 * sizes are fixed within a given stream.
 */
  struct DSStreamCB;

struct DSDataBuf
{
  struct DSDataBuf*  permanentNext; /* ptr for keeping permanent global buffer list ... */
  /* ... for debugging, etc. (not used by streamer) */
  struct DSDataBuf*  next;      /* ptr for linking buffers into lists (free, in use, etc.) */
  long               useCount;  /* count of subscribers using this buffer */
  struct DSStreamCB* streamCBPtr; /* ptr to the context block of the owning stream */

  /* NOTE: The following two fields are filled in by    */
  /* data acquisition at "opening" time.                                */

  Item   ioreqItem;             /* I/O request item for queuing reads for this buffer */
  IOReq* ioreqItemPtr;          /* pointer to the Item in system space */

  char streamData[4];   /* start of (variable length) stream data */
};
typedef struct DSDataBuf DSDataBuf, *DSDataBufPtr;

/* The following preamble is used for all types of messages sent
 * by DSH. This enables a couple of utility routines to perform general
 * operations on lists.
 */
#define DS_MSG_HEADER                                                   \
  long  whatToDo;       /* opcode determining msg contents */           \
  Item  msgItem;        /* message item for sending this buffer */      \
  void* privatePtr;     /* ptr to sender's private data */              \
  void* link            /* user defined -- for linking msg into lists */

/*******************************************************************************************
 *              Subscriber Interface (DSH to subscriber)
 *******************************************************************************************/
/**************************************/
/* Messages sent by DS to subscribers */
/**************************************/
typedef struct SubscriberMsg
{
  DS_MSG_HEADER;

  union {
    struct {                                                            /* kStreamOpData */
      void*                     buffer;                         /* ptr to the data */
    } data;

    struct {                                                            /* kStreamOpGetChan, kStreamOpSetChan */
      long                      number;                         /* channel number to operate upon */
      long                      status;                         /* channel status (bits 31-16 subscriber defined) */
    } channel;

    struct {                                                            /* kStreamOpControl */
      long                      controlArg1;            /* subscriber defined */
      void*                     controlArg2;            /* subscriber defined */
    } control;

    struct {                                                            /* kStreamOpSync */
      unsigned long     clock;                          /* current time */
    } sync;

    struct {                                                            /* kStreamOpStart */
      unsigned long     options;                        /* start options */
    } start;

    struct {                                                            /* kStreamOpStop */
      unsigned long     options;                        /* stop options */
    } stop;

  } msg;

} SubscriberMsg, *SubscriberMsgPtr;


/* bits in status of 'channel' message above */

#define CHAN_ENABLED (1<<0)     /* R/W: '1 if channel enabled (allows data to flow) */
#define CHAN_ACTIVE  (1<<1)     /* R/O: '1 if channel data currently flowing */
#define CHAN_EOF     (1<<2)     /* R/O: '1 if channel finished */
#define CHAN_ABORTED (1<<3)     /* R/O: '1 if channel aborted (error) */
#define CHAN_SYSBITS (0x0000FFFE) /* Mask of reserved bits, rest subscriber defined */
/* NOTE: least significant bit is R/W !!! */

/* bits in options of start and stop messages above */

#define SOPT_NOFLUSH (0)        /* for readability */
#define SOPT_FLUSH   (1<<0)     /* '1 if flush on start or stop request */


/*******************************************************************************************
 *              Data Acquisition Interface (DSH to application)
 *******************************************************************************************/

/*******************************************/
/* Messages sent by DS to data acquisition */
/*******************************************/

typedef struct DataAcqMsg
{
  DS_MSG_HEADER;

  union {
    struct {                                                            /* kAcqOpGetData */
      DSDataBufPtr      bufferPtr;                      /* ptr to DatBuf struct */
      long                      bufferSize;                     /* size of buffer in BYTES */
    } data;

    struct {                                                            /* kAcqOpGoMarker */
      unsigned long     value;                          /* the marker value (interpreted by data proc) */
      unsigned long     options;                        /* options for the branch */
    } marker;

    struct {                                                            /* kAcqOpConnect */
      struct DSStreamCB*        streamCBPtr;    /* ptr to stream control block we are connecting to */
    } connect;

  } msg;
} DataAcqMsg, *DataAcqMsgPtr;

/*******************************************************************************************
 *              Stream Control Data Structures
 *******************************************************************************************/

/***********************/
/* Messages sent to DS */
/***********************/

typedef struct DSRequestMsg
{
  DS_MSG_HEADER;

  union {
    struct {                                                            /* kDSOpSubscribe */
      DSDataType                dataType;                       /* 4 byte ASCII data type identifier */
      Item                      subscriberPort;         /* message port to send data to */
    } subscribe;

    struct {                                                            /* kDSOpClockSync */
      DSDataType                exemptStream;           /* stream to *not* send sync message to */
      unsigned long     nowTime;                        /* time value to propagate to everyone */
    } clockSync;

    struct {                                                            /* kDSOpGoMarker */
      unsigned long     markerValue;            /* place to "branch" to in the stream */
      unsigned long     options;                        /* options for the branch */
    } goMarker;

    struct {                                                            /* kDSOpGetChannel */
      DSDataType                streamType;                     /* which subscriber */
      long                      channelNumber;          /* logical data channel */
      long*                     channelStatusPtr;       /* place to return channel status */
    } getChannel;

    struct {                                                            /* kDSOpSetChannel */
      DSDataType                streamType;                     /* which subscriber */
      long                      channelNumber;          /* logical data channel */
      long                      channelStatus;          /* channel status bits to set */
    } setChannel;

    struct {                                                            /* kDSOpControl */
      DSDataType                streamType;                     /* subscriber to send control msg to */
      long                      userDefinedOpcode;      /* subscriber defined action code */
      void*                     userDefinedArgPtr;      /* subscriber defined argument */
    } control;

    struct {                                                            /* kDSOpConnect */
      Item                      acquirePort;            /* connect this data port to stream */
    } connect;

    struct {                                                            /* kDSOpStartStream */
      unsigned long     options;                        /* start options */
    } start;

    struct {                                                            /* kDSOpStopStream */
      unsigned long     options;                        /* stop options */
    } stop;

  } msg;

} DSRequestMsg, *DSRequestMsgPtr;


/* This data structure describes a subscriber. The 'dataType' field is used to match
 * logical data chunks in incoming data blocks in the stream. Each matching data
 * block is delivered to the registered subscriber for that type of data. When the
 * subscriber is finished with the data, it calls the 'buffer release' proc, which
 * eventually frees the whole data block when all subscribers are finished with
 * their individual logical data chunks.
 */
typedef struct DSSubscriber
{
  DSDataType dataType;          /* type of data owned by subscriber */
  int32_t    subscriberPort;    /* pointer to data subscriber proc */
} DSSubscriber, *DSSubscriberPtr;


/* This data structure contains all the context necessary to drive a stream, including
 * a description of all subscribers and the info necessary to manage all memory buffers.
 * One of these exists for each open stream.
 */
typedef struct DSStreamCB
{
  /**************************************/
  /* Thread overhead and communications */
  /**************************************/

  Item     creatorTask;           /* who to signal when we're done initializing */
  uint32_t creatorSignal;         /* signal to send for synchronous completion */
  int32_t  creatorStatus;         /* result code for creator */

  Item  threadItem;             /* The thread Item for the server process */
  void* threadStackBlock;       /* pointer to thread's stack memory block */

  /**********************/
  /* Creation arguments */
  /**********************/

  Item         acquirePort;     /* acquisition module message port */
  long         bufDataSize;     /* size of data buffers in BYTES */
  DSDataBufPtr freeBufHead;     /* pointer to list of free data buffers */
  long         numSubsMsgs;     /* number of subscriber messages to allocate */

  /*****************************/
  /* Dynamically created stuff */
  /*****************************/

  unsigned long streamFlags;    /* stream state flags */
  uint32_t      clockOffset;    /* offset to get relative stream clock */
  uint32_t      lastValidClock; /* set when stream stopped */
  uint32_t      branchDest;     /* marker we're branching to if STRM_GO_INPROGRESS true */

  Item     requestPort;           /* work request message port */
  uint32_t requestPortSignal;     /* signal for request port */

  Item       acqReplyPort;      /* reply port for data acquisition communications */
  uint32_t   acqReplyPortSignal; /* signal for data acquisition reply port */
  MemPoolPtr dataMsgPool;       /* pool of data message blocks */

  Item       subsReplyPort;     /* reply port for subscriber communication */
  uint32_t   subsReplyPortSignal; /* signal for subscriber reply port */
  MemPoolPtr subsMsgPool;       /* pool of subscriber message blocks */

  DSDataBufPtr filledBufHead;   /* pointer to list of filled data buffers */
  DSDataBufPtr filledBufTail;   /* pointer to end of list of filled data buffers */

  long            totalBufferCount;                     /* total number of buffers this stream owns */
  long            currentFreeBufferCount;               /* number of buffers currently available for filling */
  DSRequestMsgPtr endOfStreamMsg;                               /* reply to this request msg at end of stream */

  int32_t         repliesPending;                               /* # of replies needed before replying to request */
  DSRequestMsgPtr requestMsgHead;                               /* pointer to first request msg in queue */
  DSRequestMsgPtr requestMsgTail;                               /* pointer to last request msg in queue */

  boolean          fDiscardRcvdData;                    /* => discard buffers received from Data Acq
                                                         *    until kAcqOpGoMarker msg reply */
#if HALT_ENABLE                                                                 /* When in a halted state for syncronization */
  Item             haltChunkReplyPort;                  /* reply port for synchronizing the completion of
                                                         * of halt mode. */

  SubscriberMsgPtr halted_msg;  /* The HALT Message sent */
#endif /* HALT_ENABLE */

  /***********************************/
  /* array of subscriber descriptors */
  /***********************************/

  long         numSubscribers;  /* number of subscribers in the following table */
  DSSubscriber subscriber[DS_MAX_SUBSCRIBERS];

} DSStreamCB, *DSStreamCBPtr;

int32_t InitDataStreaming(long maxNumberOfStreams);
int32_t CloseDataStreaming(void);


int32_t NewDataStream(DSStreamCBPtr *pCtx,
                    void*          bufferListPtr,
                    long           bufferSize,
                    long           deltaPriority,
                    long           numSubsMsgs);
int32_t DisposeDataStream(Item          msgItem,
                        DSStreamCBPtr streamCBPtr);

#endif /* __3do_datastream_h__ */
