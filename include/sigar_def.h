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

#define SIGAR_PROC_STATE_SLEEP  'S'
#define SIGAR_PROC_STATE_RUN    'R'
#define SIGAR_PROC_STATE_STOP   'T'
#define SIGAR_PROC_STATE_ZOMBIE 'Z'
#define SIGAR_PROC_STATE_IDLE   'D'

#define SIGAR_PROC_NAME_LEN 128

#define SIGAR_FS_NAME_LEN SIGAR_PATH_MAX
#define SIGAR_FS_INFO_LEN 256


#define SIGAR_INET6_ADDRSTRLEN 46

#define SIGAR_MAXDOMAINNAMELEN 256
#define SIGAR_MAXHOSTNAMELEN 256

#define SIGAR_RTF_UP      0x1
#define SIGAR_RTF_GATEWAY 0x2
#define SIGAR_RTF_HOST    0x4

/*
 * platforms define most of these "standard" flags,
 * but of course, with different values in some cases.
 */
#define SIGAR_IFF_UP          0x1
#define SIGAR_IFF_BROADCAST   0x2
#define SIGAR_IFF_DEBUG       0x4
#define SIGAR_IFF_LOOPBACK    0x8
#define SIGAR_IFF_POINTOPOINT 0x10
#define SIGAR_IFF_NOTRAILERS  0x20
#define SIGAR_IFF_RUNNING     0x40
#define SIGAR_IFF_NOARP       0x80
#define SIGAR_IFF_PROMISC     0x100
#define SIGAR_IFF_ALLMULTI    0x200
#define SIGAR_IFF_MULTICAST   0x800
#define SIGAR_IFF_SLAVE       0x1000
#define SIGAR_IFF_MASTER      0x2000
#define SIGAR_IFF_DYNAMIC     0x4000

#define SIGAR_NULL_HWADDR "00:00:00:00:00:00"

/* scope values from linux-2.6/include/net/ipv6.h */
#define SIGAR_IPV6_ADDR_ANY        0x0000
#define SIGAR_IPV6_ADDR_UNICAST    0x0001
#define SIGAR_IPV6_ADDR_MULTICAST  0x0002
#define SIGAR_IPV6_ADDR_LOOPBACK   0x0010
#define SIGAR_IPV6_ADDR_LINKLOCAL  0x0020
#define SIGAR_IPV6_ADDR_SITELOCAL  0x0040
#define SIGAR_IPV6_ADDR_COMPATv4   0x0080

#define SIGAR_NETCONN_CLIENT 0x01
#define SIGAR_NETCONN_SERVER 0x02

#define SIGAR_NETCONN_TCP  0x10
#define SIGAR_NETCONN_UDP  0x20
#define SIGAR_NETCONN_RAW  0x40
#define SIGAR_NETCONN_UNIX 0x80

enum {
    SIGAR_TCP_ESTABLISHED = 1,
    SIGAR_TCP_SYN_SENT,
    SIGAR_TCP_SYN_RECV,
    SIGAR_TCP_FIN_WAIT1,
    SIGAR_TCP_FIN_WAIT2,
    SIGAR_TCP_TIME_WAIT,
    SIGAR_TCP_CLOSE,
    SIGAR_TCP_CLOSE_WAIT,
    SIGAR_TCP_LAST_ACK,
    SIGAR_TCP_LISTEN,
    SIGAR_TCP_CLOSING,
    SIGAR_TCP_IDLE,
    SIGAR_TCP_BOUND,
    SIGAR_TCP_UNKNOWN
};

#define SIGAR_SYS_INFO_LEN SIGAR_MAXHOSTNAMELEN /* more than enough */
#define SIGAR_FQDN_LEN 512

#endif

