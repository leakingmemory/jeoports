#ifndef LINUX_SYSCTL_H
#define LINUX_SYSCTL_H

struct __sysctl_args {
	int *name;
	int nlen;
	void *oldval;
	size_t *oldlenp;
	void *newval;
	size_t newlen;
	unsigned long __ununsed[4];
};

#endif
