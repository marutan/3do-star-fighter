#ifndef __3do_dsstreamheader_h__
#define __3do_dsstreamheader_h__

#include "subschunkcommon.h"

/**********************/
/* Internal constants */
/**********************/

#define HEADER_CHUNK_TYPE (0x53484452) /* 'SHDR' */

#define DS_STREAM_VERSION 2     /* Stream header version number */


/********************************************************/
/* Each subscriber entry in the header consists of a    */
/* data type for the subscriber and a delta priority at */
/* which the subscriber is instantiated.                                */
/********************************************************/
typedef struct DSHeaderSubs
{
  long subscriberType;          /* data type for subscriber */
  long deltaPriority;           /* its delta priority */
} DSHeaderSubs, *DSHeaderSubsPtr;

/************************************/
/* Format of a stream header chunk       */
/************************************/
#define DS_HDR_MAX_PRELOADINST  16
#define DS_HDR_MAX_SUBSCRIBER   16

typedef struct DSHeaderChunk
{
  SUBS_CHUNK_COMMON;            /* from SubscriberUtils.h */

  long headerVersion;           /* version of header data */

  long streamBlockSize;         /* size of stream buffers in this stream */
  long streamBuffers;           /* suggested number of stream buffers to use */
  long streamerDeltaPri;        /* delta priority for streamer thread */
  long dataAcqDeltaPri;         /* delta priority for data acquisition thread */
  long numSubsMsgs;             /* number of subscriber messages to allocate */

  long audioClockChan;          /* logical channel number of audio clock channel */
  long enableAudioChan;         /* mask of audio channels to enable */

  long preloadInstList[DS_HDR_MAX_PRELOADINST];
  /* NULL terminated preloaded instrument list */

  DSHeaderSubs subscriberList[DS_HDR_MAX_SUBSCRIBER];
  /* NULL terminated list of subscriber tags */
} DSHeaderChunk, *DSHeaderChunkPtr;

#endif /* __3do_dsstreamheader_h__ */
