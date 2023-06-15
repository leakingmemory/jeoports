#ifndef ASM_IOCTL_H
#define ASM_IOCTL_H

#define _IOC_NRBITS 8
#define _IOC_TYPEBITS 8
#ifndef _IOC_SIZEBITS
#define _IOC_SIZEBITS 14
#endif
#ifndef _IOC_DIRBITS
#define _IOC_DIRBITS 2
#endif
#define _IOC_NRMASK ((1 << _IOC_NRBITS) - 1)
#define _IOC_TYPEMASK ((1 << _IOC_TYPEBITS) - 1)
#define _IOC_SIZEMASK ((1 << _IOC_SIZEBITS) - 1)
#define _IOC_DIRMASK ((1 << _IOC_DIRBITS) - 1)
#define _IOC_NRSHIFT 0
#define _IOC_TYPESHIFT (_IOC_NRSHIFT + _IOC_NRBITS)
#define _IOC_SIZESHIFT (_IOC_TYPESHIFT + _IOC_TYPEBITS)
#define _IOC_DIRSHIFT (_IOC_SIZESHIFT + _IOC_SIZEBITS)
#define _IOC_SIZE(nr) ((nr >> _IOC_SIZESHIFT) & _IOC_SIZEMASK)
#define _IOC_DIR(nr) ((nr >> _IOC_DIRSHIFT) & _IOC_DIRMASK)
#define _IOC_NR(nr) ((nr >> _IOC_NRSHIFT) & _IOC_NRMASK)
#define _IOC_TYPE(nr) ((nr >> _IOC_TYPESHIFT) & _IOC_TYPEMASK)

#endif
