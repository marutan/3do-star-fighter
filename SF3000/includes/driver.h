#ifndef __3do_driver_h__
#define __3do_driver_h__

#include "types.h"

typedef struct DeviceStatus
{
  uint8  ds_DriverIdentity;
  uint8  ds_DriverStatusVersion;
  uint8  ds_FamilyCode;
  uint8  ds_headerPad;
  uint32 ds_MaximumStatusSize;
  uint32 ds_DeviceBlockSize;
  uint32 ds_DeviceBlockCount;
  uint32 ds_DeviceFlagWord;
  uint32 ds_DeviceUsageFlags;
  uint32 ds_DeviceLastErrorCode;
  uint32 ds_DeviceMediaChangeCntr;
  uint32 ds_Reserved;
} DeviceStatus;


#endif /* __3do_driver_h__ */
