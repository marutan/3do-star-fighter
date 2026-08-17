#ifndef __3do_satemplates_h__
#define __3do_satemplates_h__

#include "types.h"

typedef struct TemplateRec {
  long          templateTag;            /* used to match caller input value */
  Item          templateItem;           /* item for the template or zero */
  char*         instrumentName;         /* ptr to string of filename */
} TemplateRec, *TemplateRecPtr;


#endif /* __3do_satemplates_h__ */
