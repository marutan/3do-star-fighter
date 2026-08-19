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

//Item  __swi(KERNELSWI+0)  CreateSizedItem(int32_t ctype, TagArg *p, int32_t size);
Item  CreateSizedItem(int32_t ctype, TagArg *p, int32_t size);
//Err   __swi(KERNELSWI+3)  DeleteItem(Item i);
Err   DeleteItem(Item i);

/* learn more about an item */
void *LookupItem(Item i);

/* convenience routines */
Item FindNamedItem(int32_t ctype, const char *name);

#define CreateItem(ct,p) CreateSizedItem((ct),(p),0)

/* Common tags for all Items, useful when creating any type of item. */
enum item_tags
{
 TAG_ITEM_END = TAG_END,        /* 0 */
 TAG_ITEM_NAME,                 /* 1 */
 TAG_ITEM_PRI,                  /* 2 */
 TAG_ITEM_VERSION,              /* 3 */
 TAG_ITEM_REVISION,             /* 4 */
 TAG_ITEM_CONSTANT_NAME,        /* 5 */
 TAG_ITEM_UNIQUE_NAME,          /* 6 */
 TAG_ITEM_RESERVED7,
 TAG_ITEM_RESERVED8,
 TAG_ITEM_RESERVED9,
 TAG_ITEM_LAST = TAG_ITEM_RESERVED9
};

typedef struct ItemEntry ItemEntry;
struct ItemEntry
{
  void     *ie_ItemAddr;
  uint32_t  ie_ItemInfo;
};

#endif /* __3do_item_h__ */

