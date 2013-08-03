#ifndef _SIGAR_NET_H
#define _SIGAR_NET_H

#include "sigar_def.h"

class NetAddress
{
private:
	enum Family
	{
		SIGAR_AF_UNSPEC,
        SIGAR_AF_INET,
        SIGAR_AF_INET6,
        SIGAR_AF_LINK
	};
	union Addr
	{
		sigar_uint32_t in;
        sigar_uint32_t in6[4];
        unsigned char mac[8];
	};
};

class NetInfo
{
private:
	char default_gateway[SIGAR_INET6_ADDRSTRLEN];
	char default_gateway_interface[MAX_INTERFACE_NAME_LEN];
	char host_name[SIGAR_MAXHOSTNAMELEN];
	char domain_name[SIGAR_MAXDOMAINNAMELEN];
	char primary_dns[SIGAR_INET6_ADDRSTRLEN];
	char secondary_dns[SIGAR_INET6_ADDRSTRLEN];
public:
	SIGAR_DECLARE(int) getNetInfo(sigar &, NetInfo &);
};

class NetRoute
{
private:
	sigar_net_address_t destination;
	sigar_net_address_t gateway;
	sigar_net_address_t mask;
	sigar_uint64_t
		flags,
		refcnt,
		use,
		metric,
		mtu,
		window,
		irtt;
	char ifname[MAX_INTERFACE_NAME_LEN];
};

class NetRouteList
{
private:
	unsigned long number;
	unsigned long size;
	NetRoute *data;
public:
	SIGAR_DECLARE(int) getNetRouteList(sigar &, NetRouteList &);
	SIGAR_DECLARE(int) destroyNetRouteList(sigar &, NetRouteList &);
};

class NetInterfaceConfig
{
private:
	char name[MAX_INTERFACE_NAME_LEN];
	char type[64];
	char description[256];
	NetAddress hwaddr;
	NetAddress address;
	NetAddress destination;
	NetAddress broadcast;
	NetAddress netmask;
	NetAddress address6;
	int prefix6_length;
	int scope6;
	sigar_uint64_t
		flags,
		mtu,
		metric;
	int tx_queue_len;
public:
	SIGAR_DECLARE(int) getNetInterfaceConfig(sigar &, const char *, NetInterfaceConfig &);
	SIGAR_DECLARE(int) primarygetNetInterfaceConfig(sigar &, NetInterfaceConfig &);
};

class NetInterfaceState
{
private:
	sigar_uint64_t
		/* received */
		rx_packets,
		rx_bytes,
		rx_errors,
		rx_dropped,
		rx_overruns,
		rx_frame,
		/* transmitted */
		tx_packets,
		tx_bytes,
		tx_errors,
		tx_dropped,
		tx_overruns,
		tx_collisions,
		tx_carrier,
		speed;
public:
	SIGAR_DECLARE(int) getNetInterfaceState(sigar &, const char *, NetInterfaceState &);
};

class NetInterfaceList
{
private:
	unsigned long number;
	unsigned long size;
	char **data;
public:
	SIGAR_DECLARE(int) getNetInterfaceList(sigar &, NetInterfaceList &);
	SIGAR_DECLARE(int) destroyNetInterfaceList(sigar &, NetInterfaceList &);
};

class NetConnection
{
private:
	unsigned long local_port;
	NetAddress local_address;
	unsigned long remote_port;
	NetAddress remote_address;
	sigar_uid_t uid;
	unsigned long inode;
	int type;
	int state;
	unsigned long send_queue;
	unsigned long receive_queue;
};

class NetConnectionList
{
private:
	unsigned long number;
	unsigned long size;
	NetConnection *data;
public:
	SIGAR_DECLARE(int) getNetConnectionList(sigar &, NetConnectionList &, int);
	SIGAR_DECLARE(int) destroyNetConnectionList(sigar &, NetConnectionList &);
};

class NetConnectionWalker
{
private:
	sigar_t *sigar;
	int flags;
	void *data; /* user data */
	int (*add_connection)(NetConnectionWalker &,NetConnection &);
public:
	SIGAR_DECLARE(int) getNetConnectionWalk(NetConnectionWalker &);
};

class NetState
{
public:
	int tcp_states[SIGAR_TCP_UNKNOWN];
	sigar_uint32_t tcp_inbound_total;
	sigar_uint32_t tcp_outbound_total;
	sigar_uint32_t all_inbound_total;
	sigar_uint32_t all_outbound_total;
private:
	SIGAR_DECLARE(int) getNetState(sigar &, NetState &,int);
	SIGAR_DECLARE(int) getPortNetState(sigar &, NetState &, int, NetAddress &, unsigned long);
	SIGAR_DECLARE(int) getNetListenAddress(sigar &, unsigned long, NetAddress &);
};

#endif
