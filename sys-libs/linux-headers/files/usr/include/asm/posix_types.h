#ifndef ASM_POSIX_TYPES_H
#define ASM_POSIX_TYPES_H

#include <stdint.h>

#ifndef __kernel_uid_t
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
#endif

typedef int64_t __kernel_long_t;

typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_time_t;

#endif
