#ifndef _SIGAR_THREAD_CPU_H
#define _SIGAR_THREAD_CPU_H

#include "sigar_def.h"

class ThreadCPU
{
private:
	sigar_uint64_t user;
	sigar_uint64_t sys;
	sigar_uint64_t total;
public:
	SIGAR_DECLARE(int) getThreadCPU(sigar &, sigar_uint64_t, ThreadCPU &);
};

#endif 
