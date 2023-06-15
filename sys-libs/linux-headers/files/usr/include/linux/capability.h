#ifndef LINUX_CAPABILITY_H
#define LINUX_CAPABILITY_H

#include <stdint.h>

struct __user_cap_header_struct {
	uint32_t version;
	int pid;
};

struct __user_cap_data_struct {
	uint32_t effective;
	uint32_t permittable;
	uint32_t inheritable;
};

#endif
