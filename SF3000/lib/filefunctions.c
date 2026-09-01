#include <stdint.h>
#include "types.h"
#include "filefunctions.h"
#include "Star3000.h"

/**
 * This function opens a disk file, given an absolute or relative pathname,
 * and returns its item number.
 *
 * @param path An absolute or relative pathname (a null- terminated text
 *             string) for the file to open, or an alias for the pathname.
 * @returns The function returns the item number of the opened file (which can
 *          be used later to refer to the file), or a negative error code if
 *          an error occurs.
 */
Item
OpenDiskFile(char *path)
{
  PASS;
  ASSERT(path);
  ASSERT(*path);

  // This func seems to handle opening directories as well as files
  // not sure how that'll map onto ansi/posix yet

  Item retval = CreateSizedItem(0, NULL, sizeof(FILE **));
  if(retval < 0) {
    return -1;
  }

  FILE **pFile = LookupItem(retval);
  *pFile = fopen(path, "rb");
  if(NULL == *pFile) {
    fprintf(stderr, "OpenDiskFile: Failed to open '%s'\n", path);
    DeleteItem(retval);
    return -1;
  }

  return retval;
}

/**
 * Closes a disk file that was opened with a call to OpenDiskFile() or
 * OpenDiskFileInDir(). The specified item may not be used after successful
 * completion of this call.
 *
 * @param fileItem The item number of the disk file to close.
 * @returns The function returns a value greater than or equal to 0 if successful or a negative error code if an error occurs. 
 */
int32_t
CloseDiskFile(Item fileItem)
{
  PASS;

  FILE **pFile = LookupItem(fileItem);
  if(NULL == *pFile) {
    fprintf(stderr, "CloseDiskFile: Item is null\n");
    exit(EXIT_FAILURE);
  }
  fclose(*pFile);
  DeleteItem(fileItem);

  return 0;
}

Item
CreateFile(char *path)
{
  UNIMPLEMENTED;

  return 0;
}

Err
DeleteFile(char *path)
{
  UNIMPLEMENTED;

  return 0;
}

