#ifndef __star3000_h__
#define __star3000_h__

#include "SFlib/SF_Status.h"

/* All the variables defined in Star3000.c */
extern game_status status;

extern mission_data mission;

extern char *cel_game;                 // Pointer to game textures list
extern char *cel_list32;               // Pointer to 32x32 texture sprites
extern char *cel_list16;               // Pointer to 16x16 ground sprites
extern char *cel_creation;             // Pointer to created 16x16 land cels
extern char *cel_palette;              // Pointer to palette entries
extern char *cel_codedpalette;         // Pointer to coded6 palette entries
extern char *cel_plutdata;             // Pointer to general plut data


#endif /* __star3000_h__ */
