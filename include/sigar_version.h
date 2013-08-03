#ifndef _SIGAR_VERSION_H
#define _SIGAR_VERSION_H

#include "sigar_def.h"

class Version
{
private:
	const char *build_date;
	const char *scm_revision;
	const char *version;
	const char *archname;
	const char *archlib;
	const char *binname;
	const char *description;
	int major, minor, maint, build;
public:
	SIGAR_DECLARE(Version *) sigar_version_get(void);
};

#endif
