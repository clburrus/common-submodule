
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

// *****************************************************************************
// *****************************************************************************
int main(int argc, unsigned char **argv)
     {
     const char Terminator[] = { 10, 13, 0 };

     unsigned long Length = strlen(text);

     printf("Length is %i bytes\n", Length);

     int Start = 0, End = 0, Count = 0;

     for(int x=0;x < Length;x += (End - Start))
          {
          Start = ScanBufferForTerminatorsStart(text,
                                                Terminator,
                                                Start,
                                                Length);

          if(Start == -1)
               printf("shit.\n");

          End = ScanBufferForTerminatorsEnd(text,
                                            Terminator,
                                            Start,
                                            Length);

          if(End == -1)
               printf("fuck.\n");


          printf("%04i : ", Count);

          for(int n=Start;n < End;n++)
               {
               printf("%c", text[n]);
               }

          printf("\n");

          Start = End;

          Count++;
          }
     }
