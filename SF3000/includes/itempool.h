#ifndef __3do_itempool_h__
#define __3do_itempool_h__

#include "types.h"

/*************************************************************/
/* Data structures for managing a pool of preallocated items */
/*************************************************************/
typedef struct ItemDesc {
  struct ItemDesc* next;        /* pointer to next in the list */
  Item             item;        /* item number of a free item */

} ItemDesc, *ItemDescPtr;

typedef struct ItemPool {
  long        numItemsInPool;   /* (not currently used) number allocated */
  void*       itemDescBlockPtr; /* ptr to block of allocated descriptors */
  ItemDescPtr availList;        /* ptr to first available item descriptor */
  ItemDescPtr inUseList;        /* ptr to first in-use item descriptor */
} ItemPool, *ItemPoolPtr;


#endif /* __3do_itempool_h__ */
