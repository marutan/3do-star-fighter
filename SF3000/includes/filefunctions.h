#ifndef __3do_filefunctions_h__
#define __3do_filefunctions_h__

//extern Item  __swi(FILEFOLIOSWI+0) OpenDiskFile(char *path);
extern Item  OpenDiskFile(char *path);
//extern int32 __swi(FILEFOLIOSWI+1) CloseDiskFile(Item fileItem);
extern int32 CloseDiskFile(Item fileItem);
//extern Item  __swi(FILEFOLIOSWI+9) CreateFile(char *path);
extern Item  CreateFile(char *path);
//extern Err   __swi(FILEFOLIOSWI+10) DeleteFile(char *path);
extern Err   DeleteFile(char *path);


#endif /* __3do_filefunctions_h__ */
