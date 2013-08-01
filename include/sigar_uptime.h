#ifndef _SIGAR_UPTIME_H
#define _SIGAR_UPTIME_H

#include "sigar_def.h"

class Uptime
{
private:
	double uptime;
	double loadavg[3];
public:
	SIGAR_DECLARE(int) getUptime(sigar &,Uptime &);
	SIGAR_DECLARE(int) sigar_loadavg_get(sigar &,Uptime &);
};

#endif
