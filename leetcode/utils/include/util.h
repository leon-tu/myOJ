#include "stdio.h"

#define LOG_LEN 128

#define LOG_PRI(log, ...)                                                                \
    do {                                                                                 \
        char strHead[LOG_LEN];                                                           \
        snprintf(strHead, LOG_LEN-1, "%s[%d]: %s", __FUNCTION__, __LINE__, log);         \
        printf(strHead, ##__VA_ARGS__);                                                    \
    } while(0)

#define NULL_CHECK(pointer)                 \
    do {                                    \
        if(NULL == pointer) {               \
            LOG_PRI("NULL pointer\n");      \
        } while(0)
