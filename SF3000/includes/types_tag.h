#ifndef __3do_types_tag_h__
#define __3do_types_tag_h__

/* TagArgs - use to pass a list of arguments to functions */
typedef void *TagData;

typedef struct TagArg
{
  uint32  ta_Tag;
  TagData ta_Arg;
} TagArg, *TagArgP;


#endif /* __3do_types_tag_h__ */
