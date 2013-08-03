#ifndef _SIGAR_FILE_H
#define _SIGAR_FILE_H

#include "sigar_def.h"

class FileSystem
{
private:
	enum FileSystemType
	{
		SIGAR_FSTYPE_UNKNOWN,
		SIGAR_FSTYPE_NONE,
		SIGAR_FSTYPE_LOCAL_DISK,
		SIGAR_FSTYPE_NETWORK,
		SIGAR_FSTYPE_RAM_DISK,
		SIGAR_FSTYPE_CDROM,
		SIGAR_FSTYPE_SWAP,
		SIGAR_FSTYPE_MAX
	};
	char dir_name[SIGAR_FS_NAME_LEN];
	char dev_name[SIGAR_FS_NAME_LEN];
	char type_name[SIGAR_FS_INFO_LEN];     /* e.g. "local" */
	char sys_type_name[SIGAR_FS_INFO_LEN]; /* e.g. "ext3" */
	char options[SIGAR_FS_INFO_LEN];
	FileSystemType type;
	unsigned long flags;
public:
};

class FileSystemList
{
private:
	unsigned long number;
	unsigned long size;
	FileSystem *data;	
public:
	SIGAR_DECLARE(int) getFileSystemList(sigar &, FileSystemList &);
	SIGAR_DECLARE(int) destroyFileSystemList(sigar &,FileSystemList &);
};

class DiskUsage
{
private:
	sigar_uint64_t reads;
    sigar_uint64_t writes;
    sigar_uint64_t write_bytes;
    sigar_uint64_t read_bytes;
    sigar_uint64_t rtime;
    sigar_uint64_t wtime;
    sigar_uint64_t qtime;
    sigar_uint64_t time;
    sigar_uint64_t snaptime;
    double service_time;
    double queue;
};

class FileSystemUsage
{
private:
	DiskUsage disk;
	double use_percent;
	sigar_uint64_t total;
	sigar_uint64_t free;
	sigar_uint64_t used;
	sigar_uint64_t avail;
	sigar_uint64_t files;
	sigar_uint64_t free_files;
public:
	SIGAR_DECLARE(int) getFileSystemUsage(sigar &, const char *, FileSystemUsage &);
	SIGAR_DECLARE(int) getDiskUsage(sigar &, const char *, DiskUsage &);
	SIGAR_DECLARE(int) pingFileSystem(sigar &, FileSystem &);
};

#endif 
