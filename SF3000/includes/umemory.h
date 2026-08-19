#ifndef __3do_umemory_h__
#define __3do_umemory_h__

#include <stdint.h>
#include "mem.h"

void *Malloc(uint32_t size, uint32_t memtype);
void *Free(void *ptr);

#define NewPtr  Malloc
#define FreePtr Free



#endif /* __3do_umemory_h__ */
