#ifndef __3do_filefunctions_h__
#define __3do_filefunctions_h__

#include <stdint.h>

//extern Item  __swi(FILEFOLIOSWI+0) OpenDiskFile(char *path);
extern Item  OpenDiskFile(char *path);
//extern int32_t __swi(FILEFOLIOSWI+1) CloseDiskFile(Item fileItem);
extern int32_t CloseDiskFile(Item fileItem);
//extern Item  __swi(FILEFOLIOSWI+9) CreateFile(char *path);
extern Item  CreateFile(char *path);
//extern Err   __swi(FILEFOLIOSWI+10) DeleteFile(char *path);
extern Err   DeleteFile(char *path);


#endif /* __3do_filefunctions_h__ */
