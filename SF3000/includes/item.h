#ifndef __3do_item_h__
#define __3do_item_h__

/*
**  Kernel item management definitions
**
**  The programmer interface is done via Items, which are passed to the system
**  instead of direct pointers. The system keeps a database of Items and their
**  associated structures
*
*/

//Err   __swi(KERNELSWI+3)  DeleteItem(Item i);
Err   DeleteItem(Item i);

/* learn more about an item */
void *LookupItem(Item i);

typedef struct ItemEntry ItemEntry;
struct ItemEntry
{
  void   *ie_ItemAddr;
  uint32  ie_ItemInfo;
};

#endif /* __3do_item_h__ */

