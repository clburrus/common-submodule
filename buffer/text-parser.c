
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

     // For each entry, compare against character b.
     for(int x = 0;x < TermLen;x++)
          {
          // Return the index + 1 of the matched terminator.
          if(b == pTerm[x])
               return x + 1;
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

     // Stop when we find a character that's not a terminator.
     while((x < BufferLength) && (BufferMatchesTerminator(*pBuffer, pTerminator) != 0))
          {
          x++;
          pBuffer++;
          }

     if(x == BufferLength)
          {
          return -1;
          }

     return x;
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

     // Stop when we find a terminator character.
     while((x < BufferLength) && (BufferMatchesTerminator(*pBuffer, pTerminator) == 0))
          {
          x++;
          pBuffer++;
          }

     if(x == BufferLength)
          {
          return -1;
          }

     return x;
     }

