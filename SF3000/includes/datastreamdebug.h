#ifndef __3do_datastreamdebug_h__
#define __3do_datastreamdebug_h__

#if DEBUG

#include "stdlib.h"             /* for exit() */
#include "stdio.h"              /* for printf() */

#define CHECK_DS_RESULT( name, dsResult )                               \
  if ( ((int32) dsResult) < 0 )                                         \
    {                                                                   \
      printf( "Failure in %s: $%lx\n", name, ((int32) dsResult) );      \
      PrintfDSError( ((int32) dsResult) );                              \
      exit( 0 );                                                        \
    }
#else
#define CHECK_DS_RESULT( name, dsResult )
#endif


#endif /* __3do_datastreamdebug_h__ */
