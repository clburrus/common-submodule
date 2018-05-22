#include "file-reader.h"

static long int LastSizeRead;
static void *LastMalloc;

// *****************************************************************************
// *****************************************************************************
long int GetLastSizeRead(void)
     {
     return LastSizeRead;
     }

// *****************************************************************************
// Reads an entire file into a malloc'ed buffer.
//
// Returns :
//      non-zero : Size of malloc'd buffer.
//      zero : Failure.
// *****************************************************************************
long int FileReader(const char *pFullPath, void **pDest)
     {
     long int Size;
     FILE *pInput;

     pInput = fopen(pFullPath, "rb");

     if(pInput)
          {
          // Get the size of the file.
          fseek(pInput, 0L, SEEK_END);
          Size = ftell(pInput);

          // Size is non-zero.
          if(Size)
               {
               // Rewind to the beginning of the file.
               rewind(pInput);

               // Allocate the number of bytes we need.
               LastMalloc = malloc(Size);

               // Store our allocated pointer in the parameter location.
               *pDest = LastMalloc;

               if(*pDest)
                    {
                    // Read the expected number of bytes.
                    LastSizeRead = fread(*pDest, 1, Size, pInput);
                    }
               }

          // Close the open file.
          fclose(pInput);

          // Return the size of the malloc'ed buffer.
          return Size;
          }

     // Something went wrong.
     return 0;
     }

