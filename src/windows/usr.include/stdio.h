#pragma once

#ifdef _MSC_VER
#include <../ucrt/stdio.h>
#else
#include <../include/stdio.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __MINGW32__
#define L_tmpnam_s L_tmpnam // aux/broker/src/detail/filesystem.cc
#endif

int vasprintf(char **ptr, const char *format, va_list arg);

#ifdef __cplusplus
}
#endif
