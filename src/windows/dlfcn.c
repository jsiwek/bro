#include <dlfcn.h>
#include <stddef.h>

void *dlopen(const char *file, int mode)
	{
	return NULL;
	}

void *dlsym(void *handle, const char *name)
	{
	return NULL;
	}

char *dlerror(void)
	{
	return (char *)"unimplemented";
	}
