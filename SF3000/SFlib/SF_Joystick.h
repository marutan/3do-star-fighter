/* File : Joystick reader header file */

#ifndef __SF_JOYSTICK
#define __SF_JOYSTICK

// Includes

#include "broker_shell.h"
#include "types.h"

// Definitions

#define JOYSTICK_MAXJOYSTICKS                                                  \
  16 // Max number of joysticks that can be connected

// Structure for proportional joystick

typedef struct stick_struct {
  long x;
  long y;
  long z;
  long b;
} stick_struct;

// Variables in SF_Joystick.c
extern stick_struct pro_stick;
extern BS_StickData joystick; // Data block for our joystick

// Function Prototypes

long joystick_initialise(void); // Initialise joystick reader
void joystick_terminate(void);  // Kill joystick reader

// INTERNAL CONTROL ROUTINES

void joystick_thread(void);  // Joystick reading task
void joystick_command(long); // INTERNAL - Execute command
long joystick_registerports(
    void); // INTERNAL - Sets up watches for joysticks, returns # connected


#endif
