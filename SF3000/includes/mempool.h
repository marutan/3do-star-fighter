#ifndef __3do_mempool_h__
#define __3do_mempool_h__

/******************************************************************/
/* Data structures for managing a pool of preallocated structures */
/******************************************************************/
struct MemPoolEntry {
  struct MemPoolEntry* next;    /* pointer to next in the list */
  char                 data[4]; /* start of user data */
};
typedef struct MemPoolEntry MemPoolEntry, *MemPoolEntryPtr;

typedef struct MemPool {
  long            numItemsInPool; /* total number allocated */
  long            numFreeInPool; /* current number of free entries */
  MemPoolEntryPtr availList;    /* ptr to first available entry */
  char            data[4];      /* start of user data blocks */
} MemPool, *MemPoolPtr;

#endif /* __3do_mempool_h__ */
