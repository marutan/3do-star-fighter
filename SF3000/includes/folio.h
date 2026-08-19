#ifndef __3do_folio_h__
#define __3do_folio_h__

#include <stdint.h>

#include "types.h"
#include "nodes.h"
#include "item.h"
#include "task.h"

typedef struct Folio Folio;
struct Folio
{
  ItemNode fn;
  int32_t  f_OpenCount;
  uint8_t  f_TaskDataIndex;
  uint8_t  f_MaxSwiFunctions;
  uint8_t  f_MaxUserFunctions;
  uint8_t  f_MaxNodeType;
  int32_t  f_Private[17];
};


#endif /* __3do_folio_h__ */
