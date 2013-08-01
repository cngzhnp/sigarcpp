#ifndef _SIGAR_CPU_H
#define _SIGAR_CPU_H

#include "sigar_def.h"

class sigarCPU
{
private:
	sigar_uint64_t
	user, 
	sys,
	nice,
	idle,
	wait,
	irq,
	soft_irq,
	stolen,
	total;
public:
	SIGAR_DECLARE(int) getCPU(sigar &,sigarCPU &);
};

class sigarCPUList
{
private:
	unsigned long number;
    unsigned long size;
    sigarCPU *data;
public:
	SIGAR_DECLARE(int) getCPUList(sigar &,sigarCPUList &);
	SIGAR_DECLARE(int) destroyCPUList(sigar &,sigarCPUList &);
};

#endif
