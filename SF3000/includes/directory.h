#ifndef __3do_directory_h__
#define __3do_directory_h__

#include <stdint.h>

#include "filesystem.h"
#include "io.h"
#include "types.h"

typedef struct Directory Directory;
struct Directory
{
  Item      dir_OpenFileItem;
  Item      dir_IOReqItem;
  IOReq    *dir_IOReq;
  uint32_t  dir_Flags;
  uint32_t  dir_BlockSize;
  uint32_t  dir_BlockCount;
  int32_t   dir_BlockNumber;
  uint32_t  dir_BlockOffset;
  uint32_t  dir_EntryNum;
  char     *dir_BlockBuf;
};

typedef struct DirectoryEntry DirectoryEntry;
struct DirectoryEntry
{
  uint32_t de_Flags;
  uint32_t de_UniqueIdentifier;
  uint32_t de_Type;
  uint32_t de_BlockSize;
  uint32_t de_ByteCount;
  uint32_t de_BlockCount;
  uint32_t de_Burst;
  uint32_t de_Gap;
  uint32_t de_AvatarCount;
  char     de_FileName[FILESYSTEM_MAX_NAME_LEN];
  uint32_t de_Location;
};



#endif /* __3do_directory_h__ */

