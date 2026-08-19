#ifndef __3do_types_tag_h__
#define __3do_types_tag_h__

#include <stdint.h>

/* TagArgs - use to pass a list of arguments to functions */
typedef void *TagData;

typedef struct TagArg
{
  uint32_t  ta_Tag;
  TagData ta_Arg;
} TagArg, *TagArgP;

#define TAG_END  0

#endif /* __3do_types_tag_h__ */
