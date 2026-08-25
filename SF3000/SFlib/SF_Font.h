/* File : SF_Font header file */

#ifndef __SF_FONT
#define __SF_FONT

// Includes

#include "SF_Message.h"

#include "displayutils.h"
#include "fontlib.h"
#include "graphics.h"
#include "textlib.h"

// Definitions

#define MENU_FONT 0
#define MESSAGE_FONT 0

// Function Prototypes

long font_loadin(void);           // Load in all fonts & return handles
void font_initialise(TextCel **); // Initialise text cels
void font_terminate(void);        // Unloads all fonts
void font_paint(long, long, long, long, long, long,
                char *); // Paint text to screen

/* Variables in SF_Font.c */
extern TextCel *cel_text[FONT_MAXMENU];

#endif
