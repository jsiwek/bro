#pragma once

#ifdef _MSC_VER
#include <../ucrt/sys/types.h>
#inlcude <winsock2.h> // For u_char.
#else
#include <../include/sys/types.h>
#include <_bsd_types.h> // For u_char.
#endif
