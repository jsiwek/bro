#pragma once

#ifdef _MSC_VER
#include <../ucrt/sys/stat.h>
#else
#include <../include/sys/stat.h>
#endif
#include <direct.h>

#define S_ISUID 0x800000000
#define S_ISGID 0x400000000
#define S_ISVTX 0x200000000

#define mkdir(path, mode) (_mkdir(path))
