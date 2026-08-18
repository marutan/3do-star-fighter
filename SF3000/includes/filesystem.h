#ifndef __3do_filesystem_h__
#define __3do_filesystem_h__

#include "types.h"
#include "io.h"
#include "discdata.h"
#include "driver.h"

#define FILECMD_ALLOCBLOCKS  6
#define FILECMD_SETEOF       7


typedef struct FileStatus {
  DeviceStatus fs;
  uint32       fs_ByteCount;
} FileStatus;


#endif /* __3do_filesystem_h__ */
