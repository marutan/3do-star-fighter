#ifndef __3do_debug3do_h__
#define __3do_debug3do_h__

#include "io.h"

/*----------------------------------------------------------------------------
 * if DEBUG is TRUE, define public-interface reporting macros.
 *--------------------------------------------------------------------------*/

#if DEBUG

#define PRT(x)  { printf x; }
#define ERR(x)  PRT(x)


#else

#define PRT(x)
#define ERR(x)

#endif

#endif /* __3do_debug3do_h__ */
