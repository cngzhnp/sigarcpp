#ifndef _SIGAR_SWAP_H
#define _SIGAR_SWAP_H

#include "sigar_def.h"

class Swap
{
private:
	sigar_uint64_t
	total,
	used, 
	free,
	page_in,
	page_out;
public:
	SIGAR_DECLARE(int) getSwap(sigar &,Swap &);
};

#endif
