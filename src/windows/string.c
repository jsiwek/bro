#include <string.h>

int strerror_r(int errnum, char *strerrbuf, size_t buflen)
	{
	return strerror_s(strerrbuf, buflen, errnum);
	}
