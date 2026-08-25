#ifndef __sflib_plot_land_h__
#define __sflib_plot_land_h__

#include <stdint.h>

/* Variables in Plot_Land.c/.s */
extern int32_t wave_counter;
extern int32_t wave_counter2;
extern int32_t wave_counter3;
extern int32_t land_sort_offset;

extern void plot_land_constants(void *);
extern void fast_rotation(void *, int32_t);
extern void machine_code_land_plot(void);
extern void machine_code_flat_land_plot(void);


#endif /* __sflib_plot_land_h__ */
