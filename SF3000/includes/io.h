#ifndef __3do_io_h__
#define __3do_io_h__

#include <stdint.h>

#include "types.h"
#include "nodes.h"
#include "msgport.h"

typedef struct IOBuf
{
  void    *iob_Buffer;            /* ptr to users buffer */
  int32_t  iob_Len;               /* len of this buffer, or transfer size */
} IOBuf;

/* User portion of IOReq data structure supplied by user*/
typedef struct IOInfo
{
  uint8_t  ioi_Command;           /* Command to be executed */
  uint8_t  ioi_Flags;             /* misc flags */
  uint8_t  ioi_Unit;              /* unit of this device */
  uint8_t  ioi_Flags2;            /* more flags, should be set to zero */
  uint32_t ioi_CmdOptions;        /* device dependent options */
  uint32_t ioi_User;              /* back ptr for user use */
  int32_t  ioi_Offset;            /* offset into device for transfer to begin */
  IOBuf    ioi_Send;              /* copy out information */
  IOBuf    ioi_Recv;              /* copy in info, (address validated) */
} IOInfo;

/* common commands */
#define CMD_WRITE       0
#define CMD_READ        1
#define CMD_STATUS      2


/* System Portion of IoReq */
#ifndef IOReq_typedef
#define IOReq_typedef
typedef struct IOReq IOReq;
#endif

struct IOReq {
  ItemNode       io;
  MinNode        io_Link;
  struct Device *io_Dev;
  struct IOReq  *(*io_CallBack)(struct IOReq *iorP); /* call, donot ReplyMsg */
  IOInfo         io_Info;
  int32_t        io_Actual;     /* actual size of request completed */
  uint32_t       io_Flags;      /* internal to device driver */
  int32_t        io_Error;      /* any errors from request? */
  int32_t        io_Extension[2]; /* extra space if needed */
  Item           io_MsgItem;
  uint32_t       io_Private0;
};


//Err __swi(KERNELSWI+37) DoIO(Item ior, const IOInfo *ioiP); /* sync   */
Err DoIO(Item ior, const IOInfo *ioiP); /* sync   */
//Err __swi(KERNELSWI+41) WaitIO(Item ior); /* wait for io completion */
Err WaitIO(Item ior); /* wait for io completion */



Item  CreateIOReq(const char *name, uint8_t pri, Item dev, Item mp); /* mp can be 0 */


#define DeleteIOReq(x)  DeleteItem(x)

#endif /* __3do_io_h__ */
