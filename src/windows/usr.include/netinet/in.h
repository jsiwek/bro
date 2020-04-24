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

#include <in6addr.h>
#include <winsock2.h>

#define IPPROTO_GRE 47
