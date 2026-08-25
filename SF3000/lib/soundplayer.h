#ifndef __3do_soundplayer_h__
#define __3do_soundplayer_h__

#include <stdint.h>

#include "types.h"

/* -------------------- Typedefs */

/*
  typedefs for handles to player data structures.
  The internal workings of these are private.
*/
typedef struct SPPlayer SPPlayer;
typedef struct SPSound SPSound;

/* -------------------- Special marker names */

/*
  Special marker names.
  Use these constants to refer to these special markers.
*/
#define SP_MARKER_NAME_BEGIN         sp_markerNameBegin


/*
  Internal names stored in library to avoid string replication.
  Use the #defines above instead of these names directly.
*/
extern const char sp_markerNameBegin[];


/* -------------------- Status flags returned by spGetPlayerStatus() */

#define SP_STATUS_F_BUFFER_ACTIVE   0x01    /* Indicates that there's something
                                               in the sound buffers waiting to
                                               be played. Set or cleared by
                                               spStartReading(), spService().
                                               Cleared by spStop(). This going
                                               false after starting is the best
                                               indicator of when playback is
                                               complete. */

#define SP_STATUS_F_READING         0x02    /* Indicates there's more data to
                                               read. Set by spStartReading().
                                               Cleared when no more to read (by
                                               spStartReading() or spService())
                                               or manually by spStop(). */

#define SP_STATUS_F_PLAYING         0x04    /* Indicates that playback has
                                               been started (but might be
                                               paused). Set by
                                               spStartPlaying(). Cleared by
                                               spStop(). */

#define SP_STATUS_F_PAUSED          0x08    /* Indicates that player has been
                                               paused. Set by spPause(). Cleared
                                               by spResume(), spStop(),
                                               spStartPlaying(). This flag is
                                               only meaningful when
                                               SP_STATUS_F_PLAYING is set. */

/* -------------------- Functions */

/* SPPlayer create, deletion, set attributes */
Err spCreatePlayer (SPPlayer **resultPlayer, Item samplerIns, uint32_t numBuffers, uint32_t bufSize, void * const buffers[]);
Err spDeletePlayer (SPPlayer *);
int32_t spGetPlayerSignalMask (const SPPlayer *);

/* SPPlayer control */
Err spStartReading (SPSound *startSound, const char *startMarkerName);
Err spStartPlaying (SPPlayer *, const TagArg *samplerTags);
Err spStop (SPPlayer *);
Err spPause (SPPlayer *);
Err spResume (SPPlayer *);
int32_t spService (SPPlayer *, int32_t signals);
int32_t spGetPlayerStatus (const SPPlayer *);

/* SPSound add, remove, status */
Err spAddSoundFile (SPSound **resultSound, SPPlayer *, const char *fileName);
Err spRemoveSound (SPSound *);

#endif /* __3do_soundplayer_h__ */

