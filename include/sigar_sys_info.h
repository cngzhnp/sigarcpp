#ifndef _SIGAR_SYS_INFO_H
#define _SIGAR_SYS_INFO_H

#include "sigar_def.h"

class SysInfo
{
private:
	char name[SIGAR_SYS_INFO_LEN]; /* canonicalized sysname */
	char version[SIGAR_SYS_INFO_LEN]; /* utsname.release */
	char arch[SIGAR_SYS_INFO_LEN];
	char machine[SIGAR_SYS_INFO_LEN];
	char description[SIGAR_SYS_INFO_LEN];
	char patch_level[SIGAR_SYS_INFO_LEN];
	char vendor[SIGAR_SYS_INFO_LEN];
	char vendor_version[SIGAR_SYS_INFO_LEN];
	char vendor_name[SIGAR_SYS_INFO_LEN];  /* utsname.sysname */
	char vendor_code_name[SIGAR_SYS_INFO_LEN];
public:
	SIGAR_DECLARE(int) getSysInfo(sigar &, SysInfo &);
	SIGAR_DECLARE(int) getFqdn(sigar &, char *, int);
	SIGAR_DECLARE(int) rpcPing(char *, int, unsigned long, unsigned long);
	SIGAR_DECLARE(char *) rpcStrerror(int);
	SIGAR_DECLARE(char *) getPassword(const char *);
};

#endif
