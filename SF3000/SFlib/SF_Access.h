/* File : SF_ACCESS -> File access header file */

#ifndef __SF_ACCESS
#define __SF_ACCESS

// Includes

#include <stdint.h>

#include "SF_Allocation.h"
#include "SF_CelUtils.h"
#include "SF_Mission.h"
#include "SF_Parameters.h"

#include "blockfile.h"
#include "operror.h"
#include "stdio.h"
#include "umemory.h"

// Definitions

#define ACCESS_LOADMISSION 1 // Load mission file ?
#define ACCESS_INITMISSION 2 // Init other files from mission file ?

#define DATA_CONFIGURE 1 // Load configure file flag
#define DATA_FILES 2     // Load game files flag

// Variables in SF_Access.c
extern uint8_t *backdrop;

// External Definitions

extern char animate[2052];               // Pointer to map [animations] data
extern char skyfile[1024];               // Skyfile
extern char tangent_table[4100];         // Tangent Data

/* Function Prototypes */

long load_mission(long, long);    // Load in a mission
long load_missionfiles(void);     // Load in associated mission files
long load_gamedata(long);         // Load in fixed game cels, cosine table etc.
long load_gamecels(char *);       // Load in a set of game cels
void load_backdrop(char *, long); // Load in a backdrop image
void *load_fileat(void *, char *, ...); // Load file at specified address

#endif
