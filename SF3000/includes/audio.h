#ifndef __3do_audio_h__
#define __3do_audio_h__

#include "nodes.h"
#include "types.h"

Err OpenAudioFolio( void );
Err CloseAudioFolio( void );

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


/* Modified user routines as of 3/15/93 ********************************/
Item  LoadInstrument( char *Name, Item AudioDevice, uint8 Priority);


#endif /* __3do_audio_h__ */
