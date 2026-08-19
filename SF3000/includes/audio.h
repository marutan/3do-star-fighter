#ifndef __3do_audio_h__
#define __3do_audio_h__

#include "nodes.h"
#include "operamath.h"      /* frac16 */
#include "operror.h"
#include "types.h"

Err OpenAudioFolio( void );
Err CloseAudioFolio( void );

#define AF_STOPPED       (1)

enum audio_folio_tags
  {
   AF_TAG_AMPLITUDE = TAG_ITEM_LAST+1,   /* 10 */
   AF_TAG_RATE,
   AF_TAG_NAME,
   AF_TAG_DEVICE,
   AF_TAG_PITCH,
   AF_TAG_VELOCITY,
   AF_TAG_TEMPLATE,
   AF_TAG_INSTRUMENT,
   AF_TAG_FORMAT,
   AF_TAG_MIN,
   AF_TAG_MAX,           /* 20 */
   AF_TAG_DEFAULT,
   AF_TAG_WIDTH,
   AF_TAG_CHANNELS,
   AF_TAG_FRAMES,
   AF_TAG_BASENOTE,
   AF_TAG_DETUNE,
   AF_TAG_LOWNOTE,
   AF_TAG_HIGHNOTE,
   AF_TAG_LOWVELOCITY,
   AF_TAG_HIGHVELOCITY,  /* 30 */
   AF_TAG_SUSTAINBEGIN,
   AF_TAG_SUSTAINEND,
   AF_TAG_RELEASEBEGIN,
   AF_TAG_RELEASEEND,
   AF_TAG_NUMBYTES,
   AF_TAG_ADDRESS,
   AF_TAG_SAMPLE,
   AF_TAG_EXTERNAL,
   AF_TAG_PRIORITY,
   AF_TAG_SET_FLAGS,
   AF_TAG_CLEAR_FLAGS,
   /* New Tags as of 3/15/93 */
   AF_TAG_FREQUENCY,
   AF_TAG_ENVELOPE,
   AF_TAG_HOOKNAME,
   AF_TAG_START_AT,
   /* New Tags as of 5/4/93 */
   AF_TAG_SAMPLE_RATE,
   /* New Tags af of V1.1.18, 5/10/93 */
   AF_TAG_COMPRESSIONRATIO,
   AF_TAG_COMPRESSIONTYPE,
   AF_TAG_NUMBITS,
   /* New Tags af of V1.1.29, 6/7/93 */
   AF_TAG_NOTESPEROCTAVE,
   AF_TAG_BASEFREQ,
   /* New Tags as of V1.1.33, 6/12/93 */
   AF_TAG_SUSTAINTIME,
   AF_TAG_RELEASETIME,
   AF_TAG_MICROSPERUNIT,
   AF_TAG_DATA_OFFSET,
   AF_TAG_DATA_SIZE,
   /* New Tags as of V0.7.51, 7/21/93 */
   AF_TAG_DELAY_LINE,
   /* New Tags as of V20.01.58, 8/9/93 */
   AF_TAG_RELEASEJUMP,
   /* New Tags as of V20.16.62, 8/30/93 */
   AF_TAG_CURRENT,
   /* New Tags as of V20.16.66, 10/11/93 */
   AF_TAG_STATUS,
   /* New Tags as of V20.24.69, 11/19/93 */
   AF_TAG_TIME_SCALE,
   AF_TAG_START_TIME,
   /* New Tags as of V20.25.71, 12/15/93 */
   AF_TAG_IMAGE_ADDRESS,
   AF_TAG_IMAGE_LENGTH,
   AF_TAG_LEAVE_IN_PLACE,
   AF_TAG_ALLOC_FUNCTION,
   AF_TAG_FREE_FUNCTION,
   AF_TAG_SCAN,
   /* New Tags as of V76, 2/24/94 */
   AF_TAG_CLONE,
   /* New Tags as of 6/9/94 */
   AF_TAG_USED_BY,
   /* New Tags as of 6/14/94 */
   AF_TAG_INTERNAL_1,    /* For internal use only. */
   /* New Tags as of 8/15/94 */
   AF_TAG_CALCRATE_DIVIDE,  /* For reduced execution rate. */
   AF_TAG_SPECIAL    /* For internal use only. */
  };

/* Flags for Attachments */
//#define AF_ATTF_NOAUTOSTART    (0x0001)
#define AF_ATTF_FATLADYSINGS   (0x0002)
//#define AF_ATTF_LEGALFLAGS     (0x0003)


/* Declare SWIs */

//Err __swi(AUDIOSWI+0) TweakKnob( Item KnobItem, int32 Value );
Err TweakKnob( Item KnobItem, int32 Value );
//Err __swi(AUDIOSWI+1) StartInstrument( Item Instrument, TagArg *TagList);
Err StartInstrument( Item Instrument, TagArg *TagList);
//Err __swi(AUDIOSWI+8) ConnectInstruments( Item SrcIns, char *SrcName,
//                                          Item DstIns, char *DstName);
//Err __swi(AUDIOSWI+3) StopInstrument( Item Instrument, TagArg *TagList);
Err StopInstrument( Item Instrument, TagArg *TagList);
Err ConnectInstruments( Item SrcIns, char *SrcName,
                                          Item DstIns, char *DstName);
//Err __swi(AUDIOSWI+12) DisconnectInstruments( Item SrcIns, char *SrcName,
//                                              Item DstIns, char *DstName);
Err DisconnectInstruments( Item SrcIns, char *SrcName,
                                              Item DstIns, char *DstName);

/****************************************************************/
/******* Instruments ********************************************/
/****************************************************************/

Err UnloadInstrument( Item Instrument );

/****************************************************************/
/******* Knobs **************************************************/
/****************************************************************/
Item  GrabKnob ( Item Instrument, char *Name );
Err  ReleaseKnob ( Item KnobItem );

/****************************************************************/
/******* Samples ************************************************/
/****************************************************************/
Item   LoadSample ( char *Name );
Err  UnloadSample ( Item SampleItem );

/* Modified user routines as of 3/15/93 ********************************/
Item  LoadInstrument( char *Name, Item AudioDevice, uint8 Priority);

Err GetAudioItemInfo( Item AnyItem, TagArg *tp );

//Err __swi(AUDIOSWI+27) SetAudioItemInfo( Item AnyItem, TagArg *tp );
Err SetAudioItemInfo( Item AnyItem, TagArg *tp );

Item AttachSample( Item Instrument, Item Sample, char *FIFOName );
Err DetachSample( Item Attachment );

/* Added 9/15/93  */
//Err __swi(AUDIOSWI+32) BendInstrumentPitch( Item Instrument, frac16 BendFrac );
Err BendInstrumentPitch( Item Instrument, frac16 BendFrac );


#endif /* __3do_audio_h__ */
