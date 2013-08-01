#ifndef _SIGAR_DEF_H
#define _SIGAR_DEF_H

#include <limits.h>

#ifndef MAX_INTERFACE_NAME_LEN
#define MAX_INTERFACE_NAME_LEN 256
#endif

#if defined(_LP64)         || \
    defined(__LP64__)      || \
    defined(__64BIT__)     || \
    defined(__powerpc64__) || \
    defined(__osf__)
#define SIGAR_64BIT
#endif

/* for printf sigar_uint64_t */
#ifdef SIGAR_64BIT
# define SIGAR_F_U64 "%lu"
#else
# define SIGAR_F_U64 "%Lu"
#endif

#if defined(WIN32)

typedef unsigned __int32 sigar_uint32_t;

typedef unsigned __int64 sigar_uint64_t;

typedef __int32 sigar_int32_t;

typedef __int64 sigar_int64_t;

#elif ULONG_MAX > 4294967295UL

typedef unsigned int sigar_uint32_t;

typedef unsigned long sigar_uint64_t;

typedef int sigar_int32_t;

typedef long sigar_int64_t;

#else

typedef unsigned int sigar_uint32_t;

typedef unsigned long long sigar_uint64_t;

typedef int sigar_int32_t;

typedef long long sigar_int64_t;

#endif

#define SIGAR_FIELD_NOTIMPL -1

#define SIGAR_OK 0
#define SIGAR_START_ERROR 20000
#define SIGAR_ENOTIMPL       (SIGAR_START_ERROR + 1)
#define SIGAR_OS_START_ERROR (SIGAR_START_ERROR*2)

#ifdef WIN32
#   define SIGAR_ENOENT ERROR_FILE_NOT_FOUND
#   define SIGAR_EACCES ERROR_ACCESS_DENIED
#   define SIGAR_ENXIO  ERROR_BAD_DRIVER_LEVEL
#else
#   define SIGAR_ENOENT ENOENT
#   define SIGAR_EACCES EACCES
#   define SIGAR_ENXIO  ENXIO
#endif

#ifdef WIN32
#   define SIGAR_DECLARE(type) \
        __declspec(dllexport) type __stdcall
#else
#   define SIGAR_DECLARE(type) type
#endif

#if defined(PATH_MAX)
#   define SIGAR_PATH_MAX PATH_MAX
#elif defined(MAXPATHLEN)
#   define SIGAR_PATH_MAX MAXPATHLEN
#else
#   define SIGAR_PATH_MAX 4096
#endif

#ifdef WIN32
typedef sigar_uint64_t sigar_pid_t;
typedef unsigned long sigar_uid_t;
typedef unsigned long sigar_gid_t;
#else
#include <sys/types.h>
typedef pid_t sigar_pid_t;
typedef uid_t sigar_uid_t;
typedef gid_t sigar_gid_t;

typedef struct sigar_t sigar_t;
#define SIGAR_CRED_NAME_MAX 512
#endif

