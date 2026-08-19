#ifndef __3do_driver_h__
#define __3do_driver_h__

#include <stdint.h>

#include "types.h"
#include "nodes.h"
#include "msgport.h"

typedef struct DeviceStatus
{
  uint8_t  ds_DriverIdentity;
  uint8_t  ds_DriverStatusVersion;
  uint8_t  ds_FamilyCode;
  uint8_t  ds_headerPad;
  uint32_t ds_MaximumStatusSize;
  uint32_t ds_DeviceBlockSize;
  uint32_t ds_DeviceBlockCount;
  uint32_t ds_DeviceFlagWord;
  uint32_t ds_DeviceUsageFlags;
  uint32_t ds_DeviceLastErrorCode;
  uint32_t ds_DeviceMediaChangeCntr;
  uint32_t ds_Reserved;
} DeviceStatus;


#endif /* __3do_driver_h__ */
