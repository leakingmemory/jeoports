#ifndef LINUX_UTSNAME_H
#define LINUX_UTSNAME_H

struct oldold_utsname {
	char sysname[9];
	char nodename[9];
	char release[9];
	char version[9];
	char machine[9];
};

struct old_utsname {
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
};

#define NEW_UTSNAME_ARRAY_LEN (64+1)

struct new_utsname {
	char sysname[NEW_UTSNAME_ARRAY_LEN];
	char nodename[NEW_UTSNAME_ARRAY_LEN];
	char release[NEW_UTSNAME_ARRAY_LEN];
	char version[NEW_UTSNAME_ARRAY_LEN];
	char machine[NEW_UTSNAME_ARRAY_LEN];
	char domainname[NEW_UTSNAME_ARRAY_LEN];
};

#endif
