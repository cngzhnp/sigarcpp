#ifndef _SIGAR_MEM_H
#define _SIGAR_MEM_H

#include "sigar_def.h"

class Mem
{
private:
	sigar_uint64_t
	ram,
	total,
    used, 
    free,
    actual_used,
    actual_free;
    double used_percent;
    double free_percent;
public:
	SIGAR_DECLARE(int) getMemory(sigar &,Mem &);
};

#endif
