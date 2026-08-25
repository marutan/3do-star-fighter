#ifndef __3do_cpacksubscriber_h__
#define __3do_cpacksubscriber_h__

#include <stdint.h>

#include "graphics.h"
#include "subscriberutils.h"
#include "subscriberconstants.h"
#include "codec.h"
#include "datastreamlib.h"

#ifndef FILM_CHUNK_TYPE
#define FILM_CHUNK_TYPE CHAR4LITERAL('F','I','L','M') /* chunk data type for this subscriber */
#endif

/* FHDR_CHUNK_TYPE, FRME_CHUNK_TYPE, CPAK_MAX_SUBSCRIPTIONS,
 * CPAK_MAX_CHANNELS, CPAK_MAX_CHUNKS, BYTES_PER_PIXEL,
 * SCANLINES_PER_ROW and NO_FRAME_ITEM are shared with ezqsubscriber.h
 * and are defined in subscriberconstants.h. */


typedef struct ImageDesc
{
  int32_t baseAddr;
  int32_t rowBytes;
  int32_t baseAddrFrame;
  int32_t width;
  int32_t height;
  int32_t xPos;
  int32_t yPos;
} ImageDesc;

typedef ImageDesc *ImageDescPtr;

typedef struct CPakChannel CPakChannel;
typedef CPakChannel* CPakChannelPtr;
struct CPakChannel
{
  unsigned long status;         /* state bits (see below) */
  SubsQueue     dataQueue;      /* queue of waiting data chunks */
  Item          dataQueueSem;   /* semaphore to manage access to data list */
  boolean       fFlushOnSync;   /* flag: if true, flush all chunks from channel on sync */
  ImageDesc     imageData;      /* this structure contains the LR form buffer and
                                   dimension fields for the unpacked Cinepak data */
};

typedef struct CPakContext CPakContext;
typedef CPakContext* CPakContextPtr;
struct CPakContext
{
  Item     creatorTask;           /* who to signal when we're done initializing */
  uint32_t creatorSignal;         /* signal to send for synchronous completion */
  int32_t  creatorStatus;         /* result code for creator */

  Item  threadItem;             /* subscriber thread item */
  void* threadStackBlock;       /* pointer to thread's stack memory block */

  Item     requestPort;           /* message port item for subscriber requests */
  uint32_t requestPortSignal;     /* signal to detect request port messages */

  Item     replyPort;             /* message port item for subscriber requests */
  uint32_t replyPortSignal;       /* signal to detect request port messages */

  Item      cueItem;              /* audio cue item for scheduling output */
  uint32_t  cueSignal;            /* signal associated with cueItem */
  int32_t   localTimeOrigin;      /* local version of the time */
  boolean   fTimerRunning;        /* flag: timer currently running */

  codecHandler codecHndlr;      /* Should be an item - I don't really know what this is */
  codec        filmCodec;       /* a reference to the Cinepak decompressor code */

  boolean   freeListNotEmpty;   /* true if any entries in the freeList */
  SubsQueue freeList;           /* queue of freed data chunks */
  Item      freeQueueSem;       /* signal to send to have subscriber free chunks */
  Item      freeQueueSignal;    /* signal to send to have subscriber free chunks */
  Item      cpakTask;           /* who to signal when we want to free chunks */

  boolean   fTimeChanged;         /* flag: subscriber got sync msg */

  int32_t   numChannels;
  CPakChannel channel[CPAK_MAX_CHANNELS]; /* an array of channels */
};

typedef struct CinePakHeader
{
  SUBS_CHUNK_COMMON;
  int32_t version;                /*      0 for this version                      */
  int32_t cType;                  /*      video compression type          */
  int32_t height;                 /*      Height of each frame            */
  int32_t width;                  /*      Width of each frame                     */
  int32_t scale;                  /*      Timescale of Film                       */
  int32_t count;                  /*      Number of frames                        */
} CinePakHeader, *CinePakHeaderPtr;


typedef struct  CinePakFrame
{
  SUBS_CHUNK_COMMON;
  int32_t duration;               /*      Duration of this sample         */
  int32_t frameSize;              /*      Number of bytes in frame        */
  char  frameData[4];           /*      compressed frame data...        */
} CinePakFrame, *CinePakFramePtr;


typedef struct CPakRec
{
  DSStreamCBPtr        streamCBPtr;
  struct CinePakHeader cpHeader; /* Copy of the Header chunk for this cinepak film */
  CCB                  cpCCB;   /* The LRForm CCB chunk for this streamed anim */
  CinePakFramePtr      curFramePtr; /* the frame currently being displayed */
  int32_t              channel; /* The streamed anim channel to use with this record */
  SubscriberMsgPtr     curSubMsg; /* The msg containing the currently displayed frame */
  int32_t              lastCurTime;     /* Remember the previous Stream clock time to check for loop */
} CPakRec, *CPakRecPtr;

int32_t InitCPakSubscriber(void);
int32_t CloseCPakSubscriber(void);

int32_t NewCPakSubscriber(CPakContextPtr *pCtx, int32_t numChannels, int32_t priority);
int32_t DisposeCPakSubscriber(CPakContextPtr ctx);

int32_t InitCPakCel(DSStreamCBPtr   streamCBPtr,
                    CPakContextPtr  ctx,
                    CPakRecPtr     *pCPRecPtr,
                    int32_t           channel,
                    boolean         flushOnSync);
int32_t DestroyCPakCel(CPakContextPtr ctx, CPakRecPtr cpRecPtr, int32_t channel);
void    DrawCPakToBuffer(CPakContextPtr ctx, CPakRecPtr cpRecPtr, Bitmap *bitmap);
void    FlushCPakChannel(CPakContextPtr ctx, CPakRecPtr cpRecPtr, int32_t channel);
int32_t SendFreeCPakSignal(CPakContextPtr ctx);

#endif /* __3do_cpacksubscriber_h__ */
