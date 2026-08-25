#ifndef __sflib_setup_tables_h__
#define __sflib_setup_tables_h__

// THIS WILL CHANGE ALL THE MISSION SAM RATINGS

// SET THE SAM RATE - E.G.	1024 IS NORMAL
// 							512 = HALF THE NUMBER OF
// SAMS 							2048 = DOUBLE THE FIRE RATE

#include <stdint.h>

// I HAVE SET THIS LOWER BECAUSE HAVING PLAYED IT I FELT THERE WERE TOO MANY

#define SAM_FIRE_RATE 650

// NORMAL - 1024 I HAVE ALSO SET THIS SLIGHTLY LOWER

#define LASER_FIRE_RATE 800

// NOTE THESE SETTING WILL ONLY CHANGE THE FIRE RATE FOR ALL GROUND OBJECTS ON
// ALL MISSIONS

#define COLL_UP_RIGHT 248
#define COLL_UP 249
#define COLL_UP_LEFT 250
#define COLL_LEFT 251
#define COLL_DOWN_LEFT 252
#define COLL_DOWN 253
#define COLL_DOWN_RIGHT 254
#define COLL_RIGHT 255


extern void machine_code_constants(void *);
extern void plot_land_constants(void *);

void setup_tables(void);

#endif /* __sflib_setup_tables_h__ */
