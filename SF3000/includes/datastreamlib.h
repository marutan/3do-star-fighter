#ifndef __3do_datastreamlib_h__
#define __3do_datastreamlib_h__


#include "datastream.h"

int32   DSSubscribe( Item       msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                     DSDataType dataType, Item subscriberPort );

int32   DSStartStream( Item          msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                       unsigned long startOptions );

int32   DSStopStream( Item          msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                      unsigned long stopOptions );

int32   DSSetChannel( Item       msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                      DSDataType streamType, long channelNumber, long channelStatus );

int32   DSControl( Item       msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                   DSDataType streamType, long userDefinedOpcode,
                   void*      userDefinedArgPtr );

int32   DSConnect( Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr,
                   Item acquirePort );

int32   DSSetClock( DSStreamCBPtr streamCBPtr, uint32 newStreamClock );

int32   DSWaitEndOfStream( Item msgItem, DSRequestMsgPtr reqMsg, DSStreamCBPtr streamCBPtr );


#endif /* __3do_datastreamlib_h__ */
