#ifndef _SIGAR_WHO_H
#define _SIGAR_WHO_H

#include "sigar_def.h"

class Who
{
private:
	char user[32];
	char device[32];
	char host[256];
	sigar_uint64_t time;
};

class WhoList
{
private:
	unsigned long number;
	unsigned long size;
	Who *data;
public:
	SIGAR_DECLARE(int) getWhoList(sigar &, WhoList &);
	SIGAR_DECLARE(int) destroyWhoList(sigar &, WhoList &);
};

#endif
