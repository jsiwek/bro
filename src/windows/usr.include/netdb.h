#pragma once

static inline
struct hostent *gethostbyname2(const char *name, int af) {
  return NULL; // getaddrinfo
}
