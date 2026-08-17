#ifndef __3do_sachannel_h__
#define __3do_sachannel_h__

#include "types.h"
#include "mempool.h"
#include "subscriberutils.h"

#define SA_SUBS_MAX_CHANNELS 8

typedef struct SAudioOutput
{
  Item    instrument;           /* instrument item */
  long    numChannels;          /* is instrument mono or stereo or ? */
  Item    leftEnv;              /* envelope instruments for channel amplitude ramping */
  Item    leftEnvTargetKnob;    /* knob to set target envelope value */
  Item    rightEnv;
  Item    rightEnvTargetKnob;   /* knob to set target envelope value */
  long    currentAmp;
  long    savedAmp;             /* previous amplitude to restore, used for muting */
  boolean muted;                /* is channel in mute mode */
  boolean externalMute;         /* Should channel be unmuted by StartSAudioChannel()? */
  long    currentPan;
} SAudioOutput, *SAudioOutputPtr;


typedef struct SAudioChannel
{
  unsigned long        status;  /* state bits (see below) */
  long                 numBuffers; /* how many buffers to use for this channel */
  MemPoolPtr           bufferPool; /* pool of pre initalized attachments, cues, signals, and samples */
  Item                 channelInstrument; /* DSP instrument to play channel's data chunks */
  boolean              instStarted; /* flag to know if instrument is started */
  boolean              instPaused; /* flag to know if instrument is paused */
  ulong                pauseTime; /* stream clock value when pause was initiated */
  boolean              attachmentsRunning; /* flag to know if attachments are running */
  ulong                signalMask; /* the ORd signals for all the current cues on this channel */
  SubsQueue            dataQueue; /* waiting data chunks */
  long                 inuseCount; /* number of buffers currently in the in use queue */
  struct SAudioBuffer* inuseQueueHead; /* pointer to head of buffers queued to the audio folio */
  struct SAudioBuffer* inuseQueueTail; /* pointer to tail of buffers queued to the audio folio */
  SAudioOutput         channelOutput; /* contains output instrument and control knobs */
} SAudioChannel, *SAudioChannelPtr;


#endif /* __3do_sachannel_h__ */
