#pragma once

#ifdef _MSC_VER
#include <io.h>
#define isatty(x) _isatty(x)
typedef int pid_t;
typedef int off64_t;
typedef int ssize_t;
#else
#include <../include/unistd.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

unsigned alarm(unsigned seconds);
int fork();
int fsync(int fildes);
pid_t getppid(void);
int link(const char *path1, const char * path2);
int pipe(int fildes[2]);
ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off64_t offset);
int setpgid(pid_t, pid_t);

#ifdef __cplusplus
}
#endif
