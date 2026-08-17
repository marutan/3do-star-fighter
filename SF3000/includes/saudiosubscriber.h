#ifndef __3do_saudiosubscriber_h__
#define __3do_saudiosubscriber_h__

#include "datastream.h"
#include "subscriberutils.h"
#include "sachannel.h"
#include "satemplates.h"
#include "sacontrolmsgs.h"

typedef struct SAudioContext {
  Item           creatorTask;   /* who to signal when we're done initializing */
  ulong          creatorSignal; /* signal to send for synchronous completion */
  long           creatorStatus; /* result code for creator */
  Item           threadItem;    /* subscriber thread item */
  void*          threadStackBlock; /* pointer to thread's stack memory block */
  Item           requestPort;   /* message port item for subscriber requests */
  ulong          requestPortSignal; /* signal to detect request port messages */
  DSStreamCBPtr  streamCBPtr;   /* stream this subscriber belongs to */
  TemplateRecPtr templateArray; /* ptr to array of template records */
  ulong          allBufferSignals; /* or's signals for all instruments on all channels */
  Item           outputTemplateItem; /* template item for making channel's output instrument */
  Item           envelopeTemplateItem; /* template item for making channel's envelope instrument(s) */
  Item           decodeADPCMIns; /* Support for playing ADPCM data */
  long           clockChannel;  /* which logical channel to use for clock */
  SAudioChannel  channel[SA_SUBS_MAX_CHANNELS]; /* an array of channels */
} SAudioContext, *SAudioContextPtr;

long InitSAudioSubscriber(void);
long CloseSAudioSubscriber(void);


long NewSAudioSubscriber(SAudioContextPtr *pCtx, DSStreamCBPtr streamCBPtr, long deltaPriority);
long DisposeSAudioSubscriber(SAudioContextPtr ctx);

#endif /* __3do_saudiosubscriber_h__ */
