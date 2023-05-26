#ifndef LINUX_VERSION_H
#define LINUX_VERSION_H

#define KERNEL_VERSION(maj, min, p) ((maj << 16) | (min << 8) | (p <= 255 ? p : 255))
#define LINUX_VERSION_CODE KERNEL_VERSION(6, 1, 0)

#endif
