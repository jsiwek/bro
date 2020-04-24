#pragma once

#ifdef _MSC_VER
#include <../ucrt/stdlib.h>
#else
#include <../include/stdlib.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

long random(void);
void srandom(unsigned seed);
int setenv(const char *envname, const char *envval, int overwrite);
int unsetenv(const char *name);

#ifdef __cplusplus
}
#endif
