#ifndef LINUX_PPP_IOCTL_H
#define LINUX_PPP_IOCTL_H

#define PPPIOCGASYNCMAP _IOR('t', 88, int)
#define PPPIOCGDEBUG _IOR('t', 65, int)
#define PPPIOCGFLAGS _IOR('t', 90, int)
#define PPPIOCGUNIT _IOR('t', 86, int)
#define PPPIOCGXASYNCMAP _IOR('t', 80, ext_accm)
#define PPPIOCSASYNCMAP _IOW('t', 87, int)
#define PPPIOCSDEBUG _IOW('t', 64, int)
#define PPPIOCSFLAGS _IOW('t', 89, int)
#define PPPIOCSMAXCID _IOW('t', 81, int)
#define PPPIOCSMRU _IOW('t', 82, int)
#define PPPIOCSXASYNCMAP _IOW('t', 79, ext_accm)


#endif
