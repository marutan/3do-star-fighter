#ifndef __3do_msgport_h__
#define __3do_msgport_h__

#include <stdint.h>

#include "types.h"
#include "nodes.h"
#include "kernelnodes.h"
#include "list.h"
#include "item.h"

typedef struct MsgPort
{
  ItemNode  mp;
  uint32_t  mp_Signal;          /* what Owner needs to wake up */
  List      mp_Msgs;            /* Messages waiting for Owner */
  void     *mp_UserData;        /* User data pointer */
  uint32_t  mp_Reserved;        /* Kernel use only */
} MsgPort;

typedef struct Message
{
  ItemNode  msg;
  Item      msg_ReplyPort;
  uint32_t  msg_Result;         /* result from ReplyMsg */
  void     *msg_DataPtr;        /* ptr to beginning of data */
  int32_t   msg_DataSize;       /* size of data field */
  Item      msg_MsgPort;        /* MsgPort currently queued on */
  uint32_t  msg_DataPtrSize;    /* size of allocated data area */
  Item      msg_SigItem;        /* Designated Signal Receiver */
  uint32_t  msg_Waiters;        /* number of tasks waiting on this msg */
} Message;

enum message_tags
  {
   CREATEMSG_TAG_REPLYPORT      = TAG_ITEM_LAST+1,
   CREATEMSG_TAG_MSG_IS_SMALL,
   CREATEMSG_TAG_DATA_SIZE                      /* data area for pass by value */
  };

extern Item CreateMsgPort(const char *name, uint8_t pri, uint32_t signal);

extern Item CreateMsg(const char *name, uint8_t pri, Item mp);

//extern Err __swi(KERNELSWI+16)  SendMsg(Item mp,Item msg,
//                                        const void *dataptr, int32_t datasize);
extern Err SendMsg(Item mp,Item msg,
                                        const void *dataptr, int32_t datasize);
//extern Item __swi(KERNELSWI+19) GetMsg(Item mp);
extern Item GetMsg(Item mp);
//extern Item __swi(KERNELSWI+40) WaitPort(Item mp,Item msg);
extern Item WaitPort(Item mp,Item msg);
//extern Err __swi(KERNELSWI+18)  ReplyMsg(Item msg, int32_t result,
//                                         const void *dataptr, int32_t datasize);
extern Err ReplyMsg(Item msg, int32_t result,
                                         const void *dataptr, int32_t datasize);

#define DeleteMsgPort(x) DeleteItem(x)
#define DeleteMsg(x)     DeleteItem(x)

// PJH hack, for some reason these funcs are called from PlayCPakStream in sf3000
// but not in the

int32_t PollForMsg(Item, void *, void *, void *, int32_t*);
Item NewMsgPort(void *);
Item CreateMsgItem(Item);
void RemoveMsgItem(Item);
void RemoveMsgPort(Item);

#endif /* __3do_msgport_h__ */
