#ifndef __3do_datastreamdebug_h__
#define __3do_datastreamdebug_h__

#if DEBUG

#include <stdint>
#include "stdlib.h"             /* for exit() */
#include "stdio.h"              /* for printf() */

#define CHECK_DS_RESULT( name, dsResult )                               \
  if ( ((int32_t) dsResult) < 0 )                                         \
    {                                                                   \
      printf( "Failure in %s: $%lx\n", name, ((int32_t) dsResult) );      \
      PrintfDSError( ((int32_t) dsResult) );                              \
      exit( 0 );                                                        \
    }
#else
#define CHECK_DS_RESULT( name, dsResult )
#endif


#endif /* __3do_datastreamdebug_h__ */
