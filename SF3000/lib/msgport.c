#include <stdint.h>

#include "msgport.h"
#include "Star3000.h"

Item
CreateMsgPort(const char *name, uint8_t pri, uint32_t signal)
{
  UNIMPLEMENTED;

  return 0;
}

Item
CreateMsg(const char *name, uint8_t pri, Item mp)
{
  UNIMPLEMENTED;

  return 0;
}

Err
SendMsg(Item mp,Item msg, const void *dataptr, int32_t datasize)
{
  UNIMPLEMENTED;

  return 0;
}

Item
GetMsg(Item mp)
{
  UNIMPLEMENTED;

  return 0;
}

Item
WaitPort(Item mp,Item msg)
{
  UNIMPLEMENTED;

  return 0;
}

Err
ReplyMsg(Item msg, int32_t result, const void *dataptr, int32_t datasize)
{
  UNIMPLEMENTED;

  return 0;
}


/* PJH These five are the possibly deprecated API in use in PlayCPakStream.c */
int32_t
PollForMsg(Item, void *, void *, void *, int32_t*)
{
  UNIMPLEMENTED;

  return 0;
}

Item
NewMsgPort(void *)
{
  UNIMPLEMENTED;

  return 0;
}

Item
CreateMsgItem(Item)
{
  UNIMPLEMENTED;

  return 0;
}

void
RemoveMsgItem(Item)
{
  UNIMPLEMENTED;
}

void
RemoveMsgPort(Item)
{
  UNIMPLEMENTED;
}

