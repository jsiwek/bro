#pragma once

#ifdef _MSC_VER
#include <../ucrt/string.h>
#else
#include <../include/string.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef bzero
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
#endif

int strerror_r(int errnum, char *strerrbuf, size_t buflen);

#ifdef __cplusplus
}
#endif
