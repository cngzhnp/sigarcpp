#ifndef _SIGAR_UPTIME_H
#define _SIGAR_UPTIME_H

#include "sigar_def.h"

class sigarUptime
{
private:
	double uptime;
	double loadavg[3];
public:
	SIGAR_DECLARE(int) getUptime(sigar &,sigarUptime &);
	SIGAR_DECLARE(int) sigar_loadavg_get(sigar &,sigarUptime &);
};

#endif
