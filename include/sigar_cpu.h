#ifndef _SIGAR_CPU_H
#define _SIGAR_CPU_H

#include "sigar_def.h"

class CPU
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
	SIGAR_DECLARE(int) getCPU(sigar &,CPU &);
};

class CPUList
{
private:
	unsigned long number;
    unsigned long size;
    CPU *data;
public:
	SIGAR_DECLARE(int) getCPUList(sigar &,CPUList &);
	SIGAR_DECLARE(int) destroyCPUList(sigar &,CPUList &);
};

#endif
