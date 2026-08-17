#ifndef __3do_filesystem_h__
#define __3do_filesystem_h__

#include "types.h"
#include "io.h"
#include "driver.h"

typedef struct FileStatus {
  DeviceStatus fs;
  uint32       fs_ByteCount;
} FileStatus;


#endif /* __3do_filesystem_h__ */
