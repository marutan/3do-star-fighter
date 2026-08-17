#ifndef __3do_folio_h__
#define __3do_folio_h__

#include "types.h"
#include "nodes.h"

typedef struct Folio Folio;
struct Folio
{
  ItemNode fn;
  int32    f_OpenCount;
  uint8    f_TaskDataIndex;
  uint8    f_MaxSwiFunctions;
  uint8    f_MaxUserFunctions;
  uint8    f_MaxNodeType;
  int32    f_Private[17];
};


#endif /* __3do_folio_h__ */
