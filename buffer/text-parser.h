#include <string.h>

extern signed long ScanBufferForTerminatorsStart(const char *pBuffer,
                                            const char *pTerminator,
                                            unsigned long StartPos,
                                            unsigned long BufferLength);

extern signed long ScanBufferForTerminatorsEnd(const char *pBuffer,
                                            const char *pTerminator,
                                            unsigned long StartPos,
                                            unsigned long BufferLength);
