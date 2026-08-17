#ifndef __3do_umemory_h__
#define __3do_umemory_h__

#include "mem.h"

void *Malloc(uint32 size, uint32 memtype);
void *Free(void *ptr);

#define NewPtr  Malloc
#define FreePtr Free



#endif /* __3do_umemory_h__ */
