#include "stdio.h"

#define LOG_PRI(log)                                            \
    do {                                                        \
        printf("%s:%d %s", __FUNCTION__, __LINE__, log);        \
    } while(0)
