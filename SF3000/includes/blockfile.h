#ifndef __3do_blockfile_h__
#define __3do_blockfile_h__

#include <stdint.h>

#include "types.h"
#include "filesystem.h"

/*----------------------------------------------------------------------------
 * Datatypes.
 *--------------------------------------------------------------------------*/

typedef struct BlockFile {
  Item       fDevice;           /* file device Item */
  FileStatus fStatus;           /* status record */
} BlockFile, *BlockFilePtr;


/*----------------------------------------------------------------------------
 * low-level block IO routines
 *--------------------------------------------------------------------------*/

Item    CreateBlockFileIOReq(Item deviceItem, Item iodoneReplyPort);
Err     OpenBlockFile(char *name, BlockFilePtr bf);
void    CloseBlockFile(BlockFilePtr bf);
Err     AsynchReadBlockFile(BlockFilePtr bf, Item ioreqItem, void* buffer, int32_t count, int32_t offset);
Err     WaitReadDoneBlockFile(Item ioreqItem);


#endif /* __3do_blockfile_h__ */
