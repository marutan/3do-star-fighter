#ifndef __3do_satemplates_h__
#define __3do_satemplates_h__

#include "types.h"

#define SA_COMPRESSION_SHIFT 24
#define SA_CHANNELS_SHIFT    16
#define SA_RATE_SHIFT        8
#define SA_SIZE_SHIFT        0

#define SA_22KHz 2

#define SA_16Bit 1

#define SA_MONO   1

#define SA_COMP_SDX2   2

#define MAKE_SA_TAG( rate, bits, chans, compression )   \
  ((long) ( (rate << SA_RATE_SHIFT )                    \
            | (bits << SA_SIZE_SHIFT)                   \
            | (chans << SA_CHANNELS_SHIFT)              \
            | (compression << SA_COMPRESSION_SHIFT) ) )

#define SA_22K_16B_M_SDX2 (MAKE_SA_TAG( SA_22KHz, SA_16Bit, SA_MONO, SA_COMP_SDX2 ))

typedef struct TemplateRec {
  long          templateTag;            /* used to match caller input value */
  Item          templateItem;           /* item for the template or zero */
  char*         instrumentName;         /* ptr to string of filename */
} TemplateRec, *TemplateRecPtr;


#endif /* __3do_satemplates_h__ */
