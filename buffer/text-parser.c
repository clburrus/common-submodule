#include <stdio.h>
#include "text-parser.h"

// *****************************************************************************
// Expectations :
//      b is non-zero.
//      pTerm is a zero-terminated string of characters.
// *****************************************************************************
static int BufferMatchesTerminator(const char b, const char *pTerm)
     {
     // Get the length of the terminators string.
     int TermLen = strlen(pTerm);

     // printf("BufferMatchesTerminator(%02X)\n", b);

     // For each entry, compare against character b.
     for(int x = 0;x < TermLen;x++)
          {
          // Return the index + 1 of the matched terminator.
          if(b == pTerm[x])
               {
               // printf("%02X matches %02X\n", b, pTerm[x]);
               return x + 1;
               }
          else
               {
               // printf("%02X does not match %02X\n", b, pTerm[x]);
               }
          }

     // No matches found.  Return 0.
     return 0;
     }


// *****************************************************************************
// Returns the starting position of the first non-terminator character.
// *****************************************************************************
signed long ScanBufferForTerminatorsStart(const char *pBuffer,
                                          const char *pTerminator,
                                          unsigned long StartPos,
                                          unsigned long BufferLength)
     {
     signed long x = StartPos;

     // printf("ScanBufferForTerminatorsStart()\n");

     // Stop when we find a character that's not a terminator.
     while(x < BufferLength)
          {
          if(BufferMatchesTerminator(pBuffer[x], pTerminator))
               {
               x++;
               // pBuffer++;
               }
          else
               {
               return x;
               }
          }

     return -1;
     }



// *****************************************************************************
// Returns the starting position of the first non-terminator character.
// *****************************************************************************
signed long ScanBufferForTerminatorsEnd(const char *pBuffer,
                                        const char *pTerminator,
                                        unsigned long StartPos,
                                        unsigned long BufferLength)
     {
     signed long x = StartPos;

     // printf("ScanBufferForTerminatorsEnd()\n");

     // Stop when we find a terminator character.
     // Stop when we find a character that's not a terminator.
     while(x < BufferLength)
          {
          if(BufferMatchesTerminator(pBuffer[x], pTerminator))
               {
               return x;
               }
          else
               {
               x++;
               // pBuffer++;
               }
          }

     return -1;
     }

