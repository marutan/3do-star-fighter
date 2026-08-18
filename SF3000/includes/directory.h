#ifndef __3do_directory_h__
#define __3do_directory_h__

#include "filesystem.h"
#include "io.h"
#include "types.h"

typedef struct Directory Directory;
struct Directory
{
  Item    dir_OpenFileItem;
  Item    dir_IOReqItem;
  IOReq  *dir_IOReq;
  uint32  dir_Flags;
  uint32  dir_BlockSize;
  uint32  dir_BlockCount;
  int32   dir_BlockNumber;
  uint32  dir_BlockOffset;
  uint32  dir_EntryNum;
  char   *dir_BlockBuf;
};

typedef struct DirectoryEntry DirectoryEntry;
struct DirectoryEntry
{
  uint32 de_Flags;
  uint32 de_UniqueIdentifier;
  uint32 de_Type;
  uint32 de_BlockSize;
  uint32 de_ByteCount;
  uint32 de_BlockCount;
  uint32 de_Burst;
  uint32 de_Gap;
  uint32 de_AvatarCount;
  char   de_FileName[FILESYSTEM_MAX_NAME_LEN];
  uint32 de_Location;
};



#endif /* __3do_directory_h__ */

