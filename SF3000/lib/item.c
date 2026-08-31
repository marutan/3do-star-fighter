#include <stdlib.h>
#include <stdint.h>

#include "item.h"
#include "Star3000.h"

#define MAXITEMS 64
#define MINITEMNUM 1 // It seems some things use 0, for a 'not set' sort of Item value (blockfile fDevice item)

typedef struct
{
  int32_t isSet;
  Item itemIdx;
  void *data;
} ItemToPointer;

static ItemToPointer ItemArray[MAXITEMS]; // Static should init all IsSet to false

//static currentHighestItemAllocated = 0;

Item
CreateSizedItem(int32_t ctype, TagArg *p, int32_t size)
{
  int i;

  ASSERT(size > 0);

  for(i = MINITEMNUM; i < MAXITEMS; i++) {
    if(false == ItemArray[i].isSet) {
      ItemArray[i].data = calloc(1, size);

      if(NULL == ItemArray[i].data) {
        fprintf(stderr, "OOM allocating %d\n", size);
        return -1;
      }
      ItemArray[i].isSet = true;
      ItemArray[i].itemIdx = i;

      return i;
    }
  }

  fprintf(stderr, "Not enough entries in the ItemArray\n");
  exit(EXIT_FAILURE);
}

Err
DeleteItem(Item item)
{
  int i;

  for(i = MINITEMNUM; i < MAXITEMS; i++) {
    if(item == ItemArray[i].itemIdx
       && ItemArray[i].isSet)
    {
      free(ItemArray[i].data);
      ItemArray[i].itemIdx = 0;
      ItemArray[i].isSet = false;

      return 0;
    }
  }

  fprintf(stderr, "Attempt to DeleteItem %d that isn't set\n", item);
  return 0; // Should this return an error?
}

void *
LookupItem(Item item)
{
  int i;

  for(i = MINITEMNUM; i < MAXITEMS; i++) {
    if(item == ItemArray[i].itemIdx
       && ItemArray[i].isSet)
    {
      return ItemArray[i].data;
    }
  }

  fprintf(stderr, "Attempt to LookupItem %d that isn't set\n", item);
  return NULL;
}


Item
FindNamedItem(int32_t ctype, const char *name)
{
  UNIMPLEMENTED;

  return 0;
}


