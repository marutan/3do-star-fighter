#ifndef __3do_preparestream_h__
#define __3do_preparestream_h__

#include "types.h"
#include "datastreamlib.h"
#include "dsstreamheader.h"

#define CTRL_CHUNK_TYPE CHAR4LITERAL('C','T','R','L') /* chunk type for this subscriber */
#define SNDS_CHUNK_TYPE CHAR4LITERAL('S','N','D','S') /* chunk type for this subscriber */

/***************/
/* Error codes */
/***************/
enum
  {
   kPSVersionErr        = -2001,
   kPSMemFullErr        = -2002,
   kPSUnknownSubscriber = -2003,
   kPSHeaderNotFound    = -2004
  };

/*****************************/
/* Public routine prototypes */
/*****************************/

int32        FindAndLoadStreamHeader(DSHeaderChunkPtr headerPtr, char *streamFileName);
DSDataBufPtr CreateBufferList(long numBuffers, long bufferSize);
int32        UseDefaultStreamHeader(DSHeaderChunkPtr headerPtr);

#endif /* __3do_preparestream_h__ */
