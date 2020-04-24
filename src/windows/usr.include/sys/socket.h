#pragma once

// GDI defines ERROR.
#ifndef NOGDI
#define NOGDI
#endif

// NLS defines CompareString.
#ifndef NONLS
#define NONLS
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <ws2tcpip.h>

#undef ignore
#undef STATUS_INVALID_HANDLE
#undef STATUS_INVALID_PARAMETER
#undef VOID

typedef char *caddr_t; // Should be in sys/types.h.
