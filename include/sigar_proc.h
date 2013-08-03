#ifndef _SIGAR_PROC_H
#define _SIGAR_PROC_H

#include "sigar_def.h"

class ProcList
{
private:
	unsigned long number;
	unsigned long size;
	sigar_pid_t *data;
public:
	SIGAR_DECLARE(int) getProcList(sigar &, ProcList &);
	SIGAR_DECLARE(int) destroyProcList(sigar &, ProcList &);
};

class ProcState
{
private:
	sigar_uint64_t total;
	sigar_uint64_t sleeping;
	sigar_uint64_t running;
	sigar_uint64_t zombie;
	sigar_uint64_t stopped;
	sigar_uint64_t idle;
	sigar_uint64_t threads;
public:
	SIGAR_DECLARE(int) getProcState(sigar &, ProcState &);
};

class sigarProcMemory
{
private:
	sigar_uint64_t
	size,
	resident,
	share,
	minor_faults,
	major_faults,
	page_faults;
public:
	SIGAR_DECLARE(int) getProcMemory(sigar &, sigar_pid_t, ProcMemory &);
};

class ProcCred
{
private:
	sigar_uid_t uid;
	sigar_gid_t gid;
	sigar_uid_t euid;
	sigar_gid_t egid;
public:
	SIGAR_DECLARE(int) getProcCred(sigar &,sigar_pid_t, ProcCred &);
	SIGAR_DECLARE(int) getProcPort(sigar &, int, unsigned long, sigar_pid_t);
};

class ProcCredName
{
private:
	char user[SIGAR_CRED_NAME_MAX];
	char group[SIGAR_CRED_NAME_MAX];
public:
	SIGAR_DECLARE(int) getProcCredName(sigar &, sigar_pid_t, ProcCredName &);
};

class ProcTime
{
private:
	sigar_uint64_t
	start_time,
	user,
	sys,
	total;
public:
	SIGAR_DECLARE(int) getProcTime(sigar &, sigar_pid_t, ProcTime &);
};

class ProcCpu
{
private:
	sigar_uint64_t
	start_time,
	user,
	sys,
	total;
	sigar_uint64_t last_time;
	double percent;
public:
	SIGAR_DECLARE(int) getProcCpu(sigar &, sigar_pid_t, ProcCpu &);
};

class ProcState
{
private:
	char name[SIGAR_PROC_NAME_LEN];
	char state;
	sigar_pid_t ppid;
	int tty;
	int priority;
	int nice;
	int processor;
	sigar_uint64_t threads;
public:
	SIGAR_DECLARE(int) getProcState(sigar &, sigar_pid_t, ProcState &);
};

class ProcArgs
{
private:
	unsigned long number;
	unsigned long size;
	char **data;
public:
	SIGAR_DECLARE(int) getProcArgs(sigar &, sigar_pid_t, ProcArgs &);
	SIGAR_DECLARE(int) destroyProcArgs(sigar &, sigar_pid_t, ProcArgs &);
};

class ProcEnv
{
private:
	void *data; /* user data */
	enum {
		SIGAR_PROC_ENV_ALL,
		SIGAR_PROC_ENV_KEY
	} type;
	/* used for SIGAR_PROC_ENV_KEY */
	const char *key;
	int klen;
	int (*env_getter)(void *, const char *, int, char *, int);
public:
	SIGAR_DECLARE(int) getProcEnv(sigar &, sigar_pid_t, ProcEnv &);
};

class ProcExe
{
private:
	char name[SIGAR_PATH_MAX+1];
	char cwd[SIGAR_PATH_MAX+1];
	char root[SIGAR_PATH_MAX+1];
public:
	SIGAR_DECLARE(int) getProcExe(sigar &, sigar_pid_t, ProcExe &);
};

class ProcFd
{
private:
	sigar_uint64_t total;
public:
	SIGAR_DECLARE(int) getProcFd(sigar &, sigar_pid_t, ProcFd &);
};

class ProcModules
{
private:
	void *data; /* user data */
	int (*module_getter)(void *, char *, int);
public:
	SIGAR_DECLARE(int) getProcModules(sigar &, sigar_pid_t, ProcModules &);
};

#endif
