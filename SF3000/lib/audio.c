#include <stdint.h>
#include "audio.h"
#include "Star3000.h"

Err
OpenAudioFolio( void )
{
  UNIMPLEMENTED;

  return 0;
}

Err
CloseAudioFolio( void )
{
  UNIMPLEMENTED;

  return 0;
}

Err
TweakKnob( Item KnobItem, int32_t Value )
{
  UNIMPLEMENTED;

  return 0;
}

Err
StartInstrument( Item Instrument, TagArg *TagList)
{
  UNIMPLEMENTED;

  return 0;
}

Err
StopInstrument( Item Instrument, TagArg *TagList)
{
  UNIMPLEMENTED;

  return 0;
}

Err
ConnectInstruments( Item SrcIns, char *SrcName, Item DstIns, char *DstName)
{
  UNIMPLEMENTED;

  return 0;
}

Err
DisconnectInstruments( Item SrcIns, char *SrcName,Item DstIns, char *DstName)
{
  UNIMPLEMENTED;

  return 0;
}

Err
UnloadInstrument( Item Instrument )
{
  UNIMPLEMENTED;

  return 0;
}

Item
GrabKnob ( Item Instrument, char *Name )
{
  UNIMPLEMENTED;

  return 0;
}

Err
ReleaseKnob ( Item KnobItem )
{
  UNIMPLEMENTED;

  return 0;
}

Item
LoadSample ( char *Name )
{
  UNIMPLEMENTED;

  return 0;
}

Err
UnloadSample ( Item SampleItem )
{
  UNIMPLEMENTED;

  return 0;
}

Item
LoadInstrument( char *Name, Item AudioDevice, uint8_t Priority)
{
  UNIMPLEMENTED;

  return 0;
}

Err
GetAudioItemInfo( Item AnyItem, TagArg *tp )
{
  UNIMPLEMENTED;

  return 0;
}

Err
SetAudioItemInfo( Item AnyItem, TagArg *tp )
{
  UNIMPLEMENTED;

  return 0;
}

Item
AttachSample( Item Instrument, Item Sample, char *FIFOName )
{
  UNIMPLEMENTED;

  return 0;
}

Err
DetachSample( Item Attachment )
{
  UNIMPLEMENTED;

  return 0;
}

Err
BendInstrumentPitch( Item Instrument, frac16 BendFrac )
{
  UNIMPLEMENTED;

  return 0;
}

