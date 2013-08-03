#ifndef _SIGAR_NFS_H
#define _SIGAR_NFS_H

#include "sigar_def.h"

class NFSv2
{
private:
	sigar_uint64_t null;
	sigar_uint64_t getattr;
	sigar_uint64_t setattr;
	sigar_uint64_t root;
	sigar_uint64_t lookup;
	sigar_uint64_t readlink;
	sigar_uint64_t read;
	sigar_uint64_t writecache;
	sigar_uint64_t write;
	sigar_uint64_t create;
	sigar_uint64_t remove;
	sigar_uint64_t rename;
	sigar_uint64_t link;
	sigar_uint64_t symlink;
	sigar_uint64_t mkdir;
	sigar_uint64_t rmdir;
	sigar_uint64_t readdir;
	sigar_uint64_t fsstat;
public:
	SIGAR_DECLARE(int) getNFSv2Client(sigar &, NFSv2 &);
	SIGAR_DECLARE(int) getNFSv2Server(sigar &, NFSv2 &);
};

class NFSv3
{
private:
	sigar_uint64_t null;
	sigar_uint64_t getattr;
	sigar_uint64_t setattr;
	sigar_uint64_t lookup;
	sigar_uint64_t access;
	sigar_uint64_t readlink;
	sigar_uint64_t read;
	sigar_uint64_t write;
	sigar_uint64_t create;
	sigar_uint64_t mkdir;
	sigar_uint64_t symlink;
	sigar_uint64_t mknod;
	sigar_uint64_t remove;
	sigar_uint64_t rmdir;
	sigar_uint64_t rename;
	sigar_uint64_t link;
	sigar_uint64_t readdir;
	sigar_uint64_t readdirplus;
	sigar_uint64_t fsstat;
	sigar_uint64_t fsinfo;
	sigar_uint64_t pathconf;
	sigar_uint64_t commit;
public:
	SIGAR_DECLARE(int) getNFSv3Client(sigar &, NFSv3 &);
	SIGAR_DECLARE(int) getNFSv3Server(sigar &, NFSv3 &);
};

#endif
