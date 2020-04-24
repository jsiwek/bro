#pragma once

#define WEXITSTATUS(x) 0
#define WIFEXITED(x) 0
#define WIFSIGNALED(x) 0
#define WTERMSIG(x) 0

#define WNOHANG 0

#if 0
pid_t waitpid(pid_t pid, int *stat_loc, int options);
#endif

#define waitpid(x, y, z) 0
