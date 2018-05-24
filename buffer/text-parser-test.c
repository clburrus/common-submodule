
#include <stdio.h>
#include <string.h>
#include "text-parser.h"


const unsigned char text[] =
     {
     "(.text+0x20): undefined reference to `main'\n\
collect2: error: ld returned 1 exit status\n\
dev@dev-VirtualBox:~/projects/assembler/common-submodule/buffer$ gcc text-parser.c\n\
text-parser.c: In function ‘ScanBufferForTerminators’:\n\
text-parser.c:37:59: warning: passing argument 1 of ‘BufferMatchesTerminator’ makes integer from pointer without a cast [-Wint-conversion]\n\
      while((x < BufferLength) && (BufferMatchesTerminator(pBuffer, pTerminator) == 0))\n\
                                                           ^~~~~~~\n\
text-parser.c:9:12: note: expected ‘char’ but argument is of type ‘const char *’\n\
 static int BufferMatchesTerminator(const char b, const char *pTerm)\n\
            ^~~~~~~~~~~~~~~~~~~~~~~\n\
/usr/lib/gcc/x86_64-linux-gnu/7/../../../x86_64-linux-gnu/Scrt1.o: In function `_start':\n\
(.text+0x20): undefined reference to `main'\n\
collect2: error: ld returned 1 exit status\n\
dev@dev-VirtualBox:~/projects/assembler/common-submodule/buffer$ gcc text-parser.c\n\
/usr/lib/gcc/x86_64-linux-gnu/7/../../../x86_64-linux-gnu/Scrt1.o: In function `_start':\n\
(.text+0x20): undefined reference to `main'\n\
collect2: error: ld returned 1 exit status\n\
dev@dev-VirtualBox:~/projects/assembler/common-submodule/buffer$\n"
     };


/*
const unsigned char text[] =
          {
"When in the Course of human events it becomes necessary for one people to \n\
dissolve the political bands which have connected them with another and to \n\
assume among the powers of the earth, the separate and equal station to which the \n\
Laws of Nature and of Nature's God entitle them, a decent respect to the \n\
opinions of mankind requires that they should declare the causes which \n\
impel them to the separation.\n"
          };
*/


// *****************************************************************************
// *****************************************************************************
int main(int argc, unsigned char **argv)
     {
     const char Terminator[] = { '\r', '\n', 0x0A, 0 };

     unsigned long Length = strlen(text);

     int x;

     printf("Length is %i bytes\n", Length);

     int Start = 0, End = 0, Count = 0;

     for(x=0;x < Length;)
          {
          Start = ScanBufferForTerminatorsStart(text,
                                                Terminator,
                                                Start,
                                                Length);

          End = ScanBufferForTerminatorsEnd(text,
                                            Terminator,
                                            Start,
                                            Length);

          printf("%04i : %04i %04i : ", Count, Start, End);

          for(int n=Start;n < End;n++)
               {
               printf("%c", text[n]);
               }

          printf("\n");

          x += (End - Start);

          Start = End;

          Count++;
          }
     }
