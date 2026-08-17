#ifndef __3do_subschunkcommon_h__
#define __3do_subschunkcommon_h__

#ifndef RELATIVE_BRANCHING
#       define  RELATIVE_BRANCHING      0
#endif


#if RELATIVE_BRANCHING
#define SUBS_CHUNK_COMMON                                               \
  long          chunkType;              /* chunk type */                \
  long          chunkSize;              /* chunk size including header */ \
  long          time;                   /* position in stream time */   \
  short         chunkFlags;             /* reserved for flags            */ \
  short         channel;                /* logical channel number */    \
  long          subChunkType    /* data sub-type */

typedef struct SubsChunkHeader {
  SUBS_CHUNK_COMMON;
} SubsChunkHeader, *SubsChunkHeaderPtr;
#else
#define SUBS_CHUNK_COMMON                                               \
  long          chunkType;              /* chunk type */                \
  long          chunkSize;              /* chunk size including header */ \
  long          time;                   /* position in stream time */   \
  long          channel;                /* logical channel number */    \
  long          subChunkType    /* data sub-type */

#endif  /* RELATIVE_BRANCHING  */

#endif /* __3do_subschunkcommon_h__ */
