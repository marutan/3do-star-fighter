/* File : Screen_Utils header file */

#ifndef __SF_SCREENUTILS
#define __SF_SCREENUTILS

// Includes

#include <stdint.h>

#include "SF_CelUtils.h"
#include "SF_Menu.h"
#include "SF_Message.h"
#include "graphics.h"
#include "utils3do.h"

// Defines

#define DISPLAY_WIDTH 320 // Global Screen Sizes
#define DISPLAY_HEIGHT 240

#define S_CEL 1 // Screen update options
#define S_BANK 2
#define S_IMAGE 4
#define S_MENU 8
#define S_INFO 16
#define S_WAIT 32
#define S_FLASH 64
#define S_WAITFRAME 128
#define S_DEMO 256
#define S_WAITSPACE 512

#define SCR_UPDATE 0 // Screen bank specifiers
#define SCR_DISPLAY 1

/* External Variables */

extern ScreenContext *screen;
extern Item VBLIOReq;
extern Item VRAMIOReq;
extern cel_celdata cel_quad;
extern menu_info menu_status;
extern menu menus[MAX_MENUS];
extern CCB *cel_plotlist[CEL_MAXTEMP];
extern message messages[FONT_MAXMESSAGE];
extern long info;

/* Function Prototypes */

void screen_base(int32_t updateflags);     // Draw base screen backdrops
void screen_update(int32_t);               // Draw rest of screen, flip etc.
void screen_intercept(void);               // Draw temp plotting list if full
void screen_clear(int32_t, int32_t, int32_t, int32_t); // Clear screen
void screen_swap(int32_t);                 // Fade screenbanks
void screen_postswap(int32_t);             // Fade screenbanks after flip
void screen_setswap(int32_t);              // Set next type of screen swap
void screenswap_zoominbox(void);           // SCREENSWAP ROUTINE 1
void screenswap_blurscreen(void);          // SCREENSWAP ROUTINE 2

#endif
