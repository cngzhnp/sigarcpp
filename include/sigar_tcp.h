#ifndef _SIGAR_TCP_H
#define _SIGAR_TCP_H

#include "sigar_def.h"

class TCP
{
private:
	sigar_uint64_t active_opens;
	sigar_uint64_t passive_opens;
	sigar_uint64_t attempt_fails;
	sigar_uint64_t estab_resets;
	sigar_uint64_t curr_estab;
	sigar_uint64_t in_segs;
	sigar_uint64_t out_segs;
	sigar_uint64_t retrans_segs;
	sigar_uint64_t in_errs;
	sigar_uint64_t out_rsts;
public:
	SIGAR_DECLARE(int) getTCP(sigar &,TCP &)
};

#endif
