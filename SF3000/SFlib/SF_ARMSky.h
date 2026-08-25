//	File : SF_ArmSky (Header file for sky drawing routines)

#ifndef __SF_ARMSKY
#define __SF_ARMSKY

/* Variables in SG_ArmSky.c/.s */
extern char skyfile[1024];

// Function Prototypes

extern void arm_rendersky(long, long); // Generate sky celdata for frame
extern void arm_plotsky(void *);       // Plot sky into temporary list

#endif
