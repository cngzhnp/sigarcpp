#ifndef _SIGAR_CPU_INFO_H
#define _SIGAR_CPU_INFO_H

#include "sigar_def.h"

class CPUInfo
{
private:
	char vendor[128];
	char model[128];
	int mhz;
	int mhz_max;
	int mhz_min;
	sigar_uint64_t cache_size;
	int total_sockets;
	int total_cores;
	int cores_per_socket;
};

class CPUInfoList
{
private:
	unsigned long number;
	unsigned long size;
	CPUInfo *data;
public:
	SIGAR_DECLARE(int) getCPUInfoList(sigar &,CPUInfoList &);
	SIGAR_DECLARE(int) destroyCPUInfoList(sigar &,CPUInfoList &);
};

#endif
