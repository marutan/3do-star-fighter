#ifndef __3do_datastreamlib_h__
#define __3do_datastreamlib_h__

#include <stdint.h>

#include "datastream.h"

int32_t DSSubscribe( Item       msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                     DSDataType dataType, Item subscriberPort );

int32_t DSStartStream( Item          msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                       unsigned long startOptions );

int32_t DSStopStream( Item          msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                      unsigned long stopOptions );

int32_t DSSetChannel( Item       msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                      DSDataType streamType, long channelNumber, long channelStatus );

int32_t DSControl( Item       msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                   DSDataType streamType, long userDefinedOpcode,
                   void*      userDefinedArgPtr );

int32_t DSConnect( Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                   Item acquirePort );

int32_t DSSetClock( DSStreamCBPtr streamCBPtr, uint32_t newStreamClock );

int32_t DSWaitEndOfStream( Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr );


#endif /* __3do_datastreamlib_h__ */
