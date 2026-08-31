#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include "fontlib.h"
#include "Star3000.h"


/**
 * Loads a font from the specified file and prepares it for use.
 *
 * Use UnloadFont() to release all resources acquired by LoadFont().
 *
 * @param fileName Font file to load.
 * @param memTypeBits Type of memory to load the font into (usually
 *                     MEMTYPE_ANY).
 * @returns Pointer to a FontDescriptor structure that describes the font;
 *          returns NULL if the file is not found, is not a valid font file,
 *          or there is not enough memory to process the file.
 */
FontDescriptor *
LoadFont(const char *fontFileName, uint32_t memTypeBits)
{
  FontDescriptor *retval = NULL;

  ASSERT(fontFileName);
  // only handle the values that SF3000 uses
  ASSERT(memTypeBits == MEMTYPE_ANY);

  retval = calloc(1, sizeof(FontDescriptor));
  if(NULL == retval) {
    return NULL;
  }

  FILE *fontfile = fopen(fontFileName, "rb");
  if(NULL == fontfile) {
    fprintf(stderr, "Unable to open font file '%s': %d, s\n", fontFileName,
            errno/*, strerror(errno)*/);
    exit(EXIT_FAILURE);
  }

  // At this point we need to parse and load the font file...

  fclose(fontfile);

  PASS;

  return retval;
}

void
UnloadFont(FontDescriptor *fDesc)
{
  UNIMPLEMENTED;
}

