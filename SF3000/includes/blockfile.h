#ifndef __3do_blockfile_h__
#define __3do_blockfile_h__

#include "types.h"
#include "filesystem.h"

/*----------------------------------------------------------------------------
 * Datatypes.
 *--------------------------------------------------------------------------*/

typedef struct BlockFile {
  Item       fDevice;           /* file device Item */
  FileStatus fStatus;           /* status record */
} BlockFile, *BlockFilePtr;


#endif /* __3do_blockfile_h__ */
