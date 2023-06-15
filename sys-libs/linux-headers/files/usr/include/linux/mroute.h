#ifndef LINUX_MROUTE_H
#define LINUX_MROUTE_H

#include <stdint.h>
#include <linux/in.h>
#include <linux/sockios.h>

struct sioc_sg_req {
	struct in_addr src;
	struct in_addr grp;
	unsigned long pktcnt;
	unsigned long bytecnt;
	unsigned long wrong_if;
};

typedef unsigned short vifi_t;

struct sioc_vif_req {
	vifi_t vifi;
	unsigned long icount;
	unsigned long ocount;
	unsigned long ibytes;
	unsigned long obytes;
};

#define SIOCGETVIFCNT SIOCPROTOPRIVATE
#define SIOCGETSGCNT (SIOCPROTOPRIVATE + 1)

#endif
