/* File : SF_CONTROL -> Game control header file */

#ifndef __SF_CONTROL
#define __SF_CONTROL

// Includes

#include "Ship_Struct.h"

// Variables in SF_Control.c
extern long player_crashed_xpos;
extern long player_crashed_ypos;
extern long player_crashed_zpos;

// Definitions

#define BRIEF_CONTINUE 1 // Continue with mission briefing
#define BRIEF_START 2    // Start from mission briefing
#define BRIEF_QUIT 4     // Quit from mission briefing

// Function Prototypes

void control_initialisecameras(void); // Initialise all game stuff on startup
void control_startgame(long);         // Initialise a new game
void control_startmission(long);      // Initialise a new mission

void control_registerdeath(ship_stack *); // A ship has died ! Do something
void control_searchcamera(long,
                          long); // Set camera to an instance of a shiptype
void control_changecamera(long); // Change current camera
void
control_recheckcamera(ship_stack *); // Recheck cameras when a ship is added
void control_selectweapon(void);     // Select a new weapon for the player
void control_gameover(void);         // Set gameover - display message etc.
void control_retrack(void); // Reset nearest / tracking objects if free format

void control_setupfromconfigure(void); // Sets up game from configuration file
long control_saveconfigure(void);      // Saves configuration to NVRAM

long control_showmission(long, long); // Setup / Display mission brief
void control_newlife(void);           // Adds a new life (checks for < 7 first)

#endif
