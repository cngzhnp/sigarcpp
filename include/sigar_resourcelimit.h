#ifndef _SIGAR_RESOURCELIMIT_H
#define _SIGAR_RESOURCELIMIT_H

#include "sigar_def.h"

class sigarResourceLimit
{
private:
	/* RLIMIT_CPU */
	sigar_uint64_t cpu_cur, cpu_max;
	/* RLIMIT_FSIZE */
	sigar_uint64_t file_size_cur, file_size_max;
    /* PIPE_BUF */
	sigar_uint64_t pipe_size_cur, pipe_size_max;
	/* RLIMIT_DATA */
	sigar_uint64_t data_cur, data_max;
	/* RLIMIT_STACK */
	sigar_uint64_t stack_cur, stack_max;
	/* RLIMIT_CORE */
	sigar_uint64_t core_cur, core_max;
	/* RLIMIT_RSS */
	sigar_uint64_t memory_cur, memory_max;
	/* RLIMIT_NPROC */
	sigar_uint64_t processes_cur, processes_max;
	/* RLIMIT_NOFILE */
	sigar_uint64_t open_files_cur, open_files_max;
	/* RLIMIT_AS */
	sigar_uint64_t virtual_memory_cur, virtual_memory_max;
public:
	SIGAR_DECLARE(int) getResourceLimit(sigar &,sigarResourceLimit &);
};

#endif
