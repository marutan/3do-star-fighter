#include <stdint.h>
#include "blockfile.h"
#include "Star3000.h"

Item
CreateBlockFileIOReq(Item deviceItem, Item iodoneReplyPort)
{
  Item retval = CreateSizedItem(0, NULL, sizeof(int32_t));

  PASS;

  return retval;
}

Err
OpenBlockFile(char *name, BlockFilePtr bf)
{
  PASS;

  ASSERT(name);
  ASSERT(bf->fDevice == 0);

  bf->fDevice = CreateSizedItem(0, NULL, sizeof(FILE **));
  if(bf->fDevice < 0) {
    return -1;
  }

  FILE **pBlockFile = LookupItem(bf->fDevice);

  *pBlockFile = fopen(name, "rb");
  if(NULL == *pBlockFile) {
    fprintf(stderr, "OpenBlockFile: Failed to open '%s'", name);
    exit(EXIT_FAILURE);
  }

  // BlockFilePtr also needs filesize
  fseek(*pBlockFile, 0, SEEK_END);
  bf->fStatus.fs_ByteCount = ftell(*pBlockFile);
  rewind(*pBlockFile);

  // And the 'blocksize', which is just 1 byte on sensible OSes :D
  bf->fStatus.fs.ds_DeviceBlockSize = 1;

  fprintf(stderr, "OpenBlockFile: %p '%s' %d bytes\n", *pBlockFile, name, bf->fStatus.fs_ByteCount);

  return 0;
}

void
CloseBlockFile(BlockFilePtr bf)
{
  ASSERT(bf);

  PASS;

  if(0 != bf->fDevice) {
    FILE **pBlockFile = LookupItem(bf->fDevice);

    if(NULL != *pBlockFile) {
      fclose(*pBlockFile);
    }

   DeleteItem(bf->fDevice);
  }
}

Err
AsynchReadBlockFile(BlockFilePtr bf, Item ioreqItem, void* buffer,
                    int32_t count, int32_t offset)
{
  ASSERT(bf);
  ASSERT(buffer);
  ASSERT(count > 0);

  PASS;

  // At the moment this is entirely synchronous

  FILE **pBlockFile = LookupItem(bf->fDevice);
  ASSERT(*pBlockFile); // Must have previosuly been opened

  fprintf(stderr, "%p %d %d\n", *pBlockFile, count, offset); 

  fseek(*pBlockFile, offset, SEEK_SET);

  size_t retval = fread(buffer, count, 1, *pBlockFile);
  if(retval != 1) {
    fprintf(stderr, "AsynchReadBlockFile: Unable to read full %d bytes from file\n", count);
    exit(EXIT_FAILURE);
  }

  return 0;
}

Err
WaitReadDoneBlockFile(Item ioreqItem)
{
  PASS;

  // At the moment this is entirely synchronous and the file
  // will have been fully read in AsynchReadBlockFile()

  return 0;
}

