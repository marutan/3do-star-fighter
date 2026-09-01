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
NewMsgPort(void *arg)
{
  PASS;
  ASSERT(arg == NULL); // In SF3000 only NULL is passed

  Item retval = CreateSizedItem(0, NULL, sizeof(MsgPort));
  if(retval < 0) {
    fprintf(stderr, "NewMsgPort: Failed to allocate new MsgPort Item\n");
    return -1;
  }
//  MsgPort *pMsgPort = LookupItem(retval);

  // No idea ...

  return retval;
}

Item
CreateMsgItem(Item msgPort)
{
  PASS;

  ASSERT(msgPort >= 0);

  Item retval = CreateSizedItem(0, NULL, sizeof(Message));
  if(retval < 0) {
    fprintf(stderr, "CreateMsgItem: Failed to allocate new Message Item\n");
    return -1;
  }

  //  MsgPort *pMsgPort = LookupItem(msgPort);
  // There's a list of messages in MsgPort->mp_Msgs should we add to that?

  Message *pMessage = LookupItem(retval);
  pMessage->msg_MsgPort = msgPort; // MsgPort currently queued on (guesswork)

  return retval;
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

