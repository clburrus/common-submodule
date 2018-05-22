#include <stdio.h>
#include <malloc.h>

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
int FileReader(const char *pFullPath, void **pDest)
     {
     long int Size;
     FILE *pInput;

     pInput = fopen(pFullPath, "rb");

     if(pInput)
          {
          // Get the size of the file.
          fseek(pInput, 0L, SEEK_END);
          Size = ftell(pInput);

          if(Size)
               {
               rewind(pInput);

               LastMalloc = malloc(Size);

               *pDest = LastMalloc;

               if(*pDest)
                    {
                    LastSizeRead = fread(*pDest, 1, Size, pInput);
                    }
               }

          fclose(pInput);
          return Size;
          }

     return 0;
     }

