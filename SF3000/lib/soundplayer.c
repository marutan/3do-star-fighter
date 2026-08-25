#include <stdint.h>
#include "soundplayer.h"
#include "Star3000.h"

const char sp_markerNameBegin[];

Err
spCreatePlayer (SPPlayer **resultPlayer, Item samplerIns, uint32_t numBuffers, uint32_t bufSize, void * const buffers[])
{
  UNIMPLEMENTED;

  return 0;
}

Err
spDeletePlayer (SPPlayer *)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
spGetPlayerSignalMask (const SPPlayer *)
{
  UNIMPLEMENTED;

  return 0;
}

Err
spStartReading (SPSound *startSound, const char *startMarkerName)
{
  UNIMPLEMENTED;

  return 0;
}

Err
spStartPlaying (SPPlayer *, const TagArg *samplerTags)
{
  UNIMPLEMENTED;

  return 0;
}

Err
spStop (SPPlayer *)
{
  UNIMPLEMENTED;

  return 0;
}

Err
spPause (SPPlayer *)
{
  UNIMPLEMENTED;

  return 0;
}

Err
spResume (SPPlayer *)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
spService(SPPlayer *, int32_t signals)
{
  UNIMPLEMENTED;

  return 0;
}

int32_t
spGetPlayerStatus (const SPPlayer *)
{
  UNIMPLEMENTED;

  return 0;
}

Err
spAddSoundFile(SPSound **resultSound, SPPlayer *, const char *fileName)
{
  UNIMPLEMENTED;

  return 0;
}

Err
spRemoveSound(SPSound *)
{
  UNIMPLEMENTED;

  return 0;
}

