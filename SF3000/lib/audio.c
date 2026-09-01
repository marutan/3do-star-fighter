#include <stdint.h>
#include "audio.h"
#include "Star3000.h"

Err
OpenAudioFolio( void )
{
  PASS;

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


/**
 * This function begins execution of an instrument. This typically starts a
 * sound but may have other results, depending on the nature of the
 * instrument. This call links the DSP code into the list of active
 * instruments. If the instrument has Samples or Envelopes attached, they will
 * also be started (unless the Attachments specify otherwise). This is
 * equivalent to a MIDI "Note On" event.
 *
 * The Amplitude and Frequency knobs, of instruments that have such, can be
 * tweaked by some of the tags listed below before the instrument is started.
 * When none of the tags for a particular know are specified, that knob is
 * left set to its previous value. At most one tag for each knob can be
 * specified. Tags are ignored for Instruments without the corresponding knob.
 * Knobs connected to the output of another Instrument (ConnectInstruments()),
 * cannot be set in this manner. A Knob that has been grabbed, can however be
 * set in this manner.
 *
 * This function puts the instrument in the AF_STARTED state. If the
 * instrument was previous running, it is first stopped and then restarted.
 * If the instrument has a sustain or release loop, it stays in the AF_STARTED
 * state until the state is explicitly changed (e.g. ReleaseInstrument(),
 * StopInstrument()).
 *
 * This function supersedes a call to PauseInstrument().
 *
 * @param Instrument The item number for the instrument.

*/
Err
StartInstrument( Item Instrument, TagArg *TagList)
{
  PASS;

  return 0;
}

Err
StopInstrument( Item Instrument, TagArg *TagList)
{
  UNIMPLEMENTED;

  return 0;
}

/**
 * This function connects an output from one instrument to an input of another
 * instrument. This allows construction of complex "patches" from existing
 * synthesis modules.
 *
 * An output can be connected to one or more inputs; only one output can be
 * connected to any given input. If you connect an output to a knob, it
 * disconnects that knob from any possible control by TweakKnob() or
 * TweakRawKnob(). Unlike Attachments, this kind of connection does not create
 * an Item.
 *
 * Call DisconnectInstruments() to break a connection set up by this function.
 *
 * You should call DisconnectInstruments() before deleting either instrument
 * to avoid undesirable noises.
 *
 * See the DSP Template pages for complete listings of each template's inputs,
 * outputs and knobs.
 *
 * @param SrcIns Item number of the source instrument.
 * @param SrcName Name of the output port of the source instrument to connect
 *                to.
 * @param DstIns Item number of the destination instrument.
 * @param DstNameName of the input port of the destination instrument to
 *                    connect to.
 * @returns The function returns a non-negative value if successful or an
 *          error code (a negative value) if an error occurs.
 */
Err
ConnectInstruments( Item SrcIns, char *SrcName, Item DstIns, char *DstName)
{
  PASS;

  return 0;
}

/**
 * This procedure breaks a connection made by ConnectInstruments() between two instruments. If the connection was to a knob of the second instrument, the knob is once again available for tweaking.
 *
 * @param SrcIns  Item number of the source instrument.
 * @param SrcName Name of the output port of the source instrument to break
 *                connection from.
 * @param DstIns  Item number of the destination instrument.
 * @param DstName Name of the input port of the destination instrument to
 *                break connection to.
 * @returns The procedure returns a non-negative value if successful or an
 *              error code (a negative value) if an error occurs.
 */
Err
DisconnectInstruments( Item SrcIns, char *SrcName,Item DstIns, char *DstName)
{
  PASS;

  return 0;
}

/**
 * This function frees the Instrument and unloads the Template loaded by
 * LoadInstrument().
 *
 * Do not confuse this function with DeleteInstrument(), which deletes an
 * Instrument created by CreateInstrument(). Calling DeleteInstrument() for an
 * instrument created by LoadInstrument() deletes the Instrument, but not the
 * Template, leaving you with an unaccessible Template Item that you can't
 * delete. Calling UnloadInstrument() for and Instrument created by
 * CreateInstrument() deletes Template for that Instrument along with all
 * other Instruments created from that Template.
 *
 * @param Item number of the instrument.
 * @returns The function returns 0 if successful or an error code (a negative
 *          value) if an error occurs.
 */
Err
UnloadInstrument( Item Instrument )
{
  PASS;

  DeleteItem(Instrument);

  return 0;
}

/**
 * This function creates a Knob item that provides a fast connection between a
 * task and one of an Instrument's parameters. You can then call TweakKnob()
 * or TweakRawKnob() to rapidly modify that parameter.
 *
 * See the Instrument Template pages for complete listings of each Instrument
 * Templates knobs.
 *
 * Call ReleaseKnob() to relinquish access to this knob. All Knob Items
 * grabbed for an Instrument are deleted when the Instrument is deleted. This
 * can save you a bunch of calls to ReleaseKnob().
 *
 * @param Instrument The item number of the instrument.
 * @param Name The name of the knob to grab. The knob name is matched
 * case-insensitively.
 * @returns The function returns the item number of the Knob (a positive value)
 *          if successful or an error code (a negative value) if an error
 *          occurs.
 */
Item
GrabKnob ( Item Instrument, char *Name )
{
  // Find out which struct applies here and use it
  Item retval = CreateSizedItem(0, NULL, sizeof(int32_t));

  PASS;

  return retval;
}

Err
ReleaseKnob ( Item KnobItem )
{
  UNIMPLEMENTED;

  return 0;
}

/**
 * This function allocates task memory and creates a sample item there that
 * contains the digital-audio recording from the specified file. The file must
 * be either an AIFF file or an AIFC file. These can be created using almost
 * any sound development tool including AudioMedia, Alchemy, CSound, and
 * SoundHack.
 *
 * AIFC files contain compressed audio data. These can be created from an AIFF
 * file using the SquashSound MPW tool from The 3DO Company.
 *
 * A single loop is supported for sustained repetitive waveforms.
 *
 * When you finish with the sample, you should call UnloadSample() to
 * deallocate the resources.
 *
 * @param Name The name of the AIFF or AIFC file.
 * @returns The function returns an item number if successful or an error code
 *          (a negative value) if an error occurs.
 */
Item
LoadSample ( char *Name )
{
  Item retval;

  ASSERT(Name);

  retval = CreateSizedItem(0, NULL, sizeof(int32_t));
  if(retval < 0) {
    fprintf(stderr, "LoadSample: Failed to create item\n");
    return retval;
  }

  FILE *sampleFile = fopen(Name, "rb");
  if(NULL == sampleFile) {
    fprintf(stderr, "LoadSample: Failed to open '%s'\n", Name);
    exit(EXIT_FAILURE);
  }

  // Actually parse the sample file here

  fclose(sampleFile);

  PASS;

  return retval;
}

Err
UnloadSample ( Item SampleItem )
{
  UNIMPLEMENTED;

  return 0;
}

/**
 * This functions combines the actions of LoadInsTemplate() and
 * CreateInstrument(), and returns the resulting Instrument item.
 *
 * Call UnloadInstrument() (not DeleteInstrument()) to free an Instrument
 * created by this function. Calling DeleteInstrument() deletes the Instrument,
 * but not the Template, leaving you with an unaccessible Template Item that
 * you can't delete.
 *
 * @param Name Name of the file containing the instrument template.
 * @param AudioDevice Audio device Item for instrument. 0 indicates the
 *                    default audio device, the DSP, which is the only valid
 *                    audio device item at the present time.
 * @param Priority Determines order of execution in DSP. Set from 0 to 200. A
 *                 typical value would be 100. This also determines the
 *                 priority over other instruments when voices are stolen for
 *                 dynamic voice allocation.
 * @returns The function returns an Instrument item number (a positive value)
 *          if successful or an error code (a negative value) if an error
 *          occurs.
 */
Item
LoadInstrument( char *Name, Item AudioDevice, uint8_t Priority)
{
  ASSERT(Name);
  ASSERT(Priority >= 0 && Priority <= 200);

//  Item item = LoadInsTemplate(Name, AudioDevice);
//  Item CreateInstrument (Item InsTemplate, const TagArg *tagList)

  // No idea of type here
  Item retval = CreateSizedItem(0, NULL, sizeof(int32_t));

  PASS;

  return retval;
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

