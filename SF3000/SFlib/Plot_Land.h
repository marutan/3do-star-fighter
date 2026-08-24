#ifndef __sflib_plot_land_h__
#define __sflib_plot_land_h__

#include <stdint.h>

extern int32_t wave_counter;
extern int32_t wave_counter2;
extern int32_t wave_counter3;

extern void plot_land_constants(void *);
extern void fast_rotation(void *, int32_t);
extern void machine_code_land_plot(void);
extern void machine_code_flat_land_plot(void);

extern int32_t land_sort_offset;

#endif /* __sflib_plot_land_h__ */
