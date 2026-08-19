#ifndef __3do_types_h__
#define __3do_types_h__

typedef unsigned char boolean;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef __cplusplus
typedef boolean bool;

#ifndef true
#define true TRUE
#endif

#ifndef false
#define false FALSE
#endif
#endif

#include "types_tag.h"

typedef int32_t Item;
typedef int32_t Err;

#endif /* __3do_types_h__ */
