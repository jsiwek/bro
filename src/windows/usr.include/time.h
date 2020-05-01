#pragma once

#ifdef _MSC_VER
#include <../ucrt/time.h>
#else
#include <../include/time.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct tm *gmtime_r(const time_t *timer, struct tm *result);
struct tm *localtime_r(const time_t *timer, struct tm *result);
char* strptime(const char* s, const char* f, struct tm* tm);
time_t timegm(struct tm *tm);

#ifdef __cplusplus
}
#endif
