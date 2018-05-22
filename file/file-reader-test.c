

#include "file-reader.h"

// *****************************************************************************
// *****************************************************************************
int main(int argc, unsigned char **argv)
     {
     void *pMalloc;
     unsigned char *filedata;

     long int Size = FileReader(argv[1], &pMalloc);

     filedata = (unsigned char *)pMalloc;

     printf("Size is %i bytes.\n", Size);

     for(int x = 0;x < Size;x++)
          {
          if((x % 16) == 0)
               {
               printf("\n%04X : ", x);
               }

          printf("%02X ", *filedata);

          filedata++;
          }

     printf("\n");

     free(pMalloc);
     }
