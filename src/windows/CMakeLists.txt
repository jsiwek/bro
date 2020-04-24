include(ZeekSubdir)

set(windows_SRCS
    dlfcn.c
    fcntl.c
    fnmatch.c
    fts.c
    glob.c
    regex.c
    stdio.c
    stdlib.c
    string.c
    sys.resource.c
    time.c
    unistd.c
)

bro_add_subdir_library(windows ${windows_SRCS})
