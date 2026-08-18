#ifndef __3do_directoryfunctions_h__
#define __3do_directoryfunctions_h__

#include "types.h"

Directory *OpenDirectoryItem(Item openFileItem);
int32      ReadDirectory (Directory *dir, DirectoryEntry *de);
void       CloseDirectory (Directory *dir);

#endif /*  __3do_directoryfunctions_h__ */
