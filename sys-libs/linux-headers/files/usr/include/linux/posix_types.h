#ifndef LINUX_POSIX_TYPES_H
#define LINUX_POSIX_TYPES_H

#include <asm/posix_types.h>

#ifdef __FD_SETSIZE
#undef __FD_SETSIZE
#endif
#define __FD_SETSIZE 1024

typedef struct {
	unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
} __kernel_fd_set;

#endif
