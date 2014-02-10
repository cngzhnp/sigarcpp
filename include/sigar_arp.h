#ifndef _SIGAR_ARP_H
#define _SIGAR_ARP_H

#include "sigar_def.h"

class Arp
{
private:
	//char ifname[MAX_INTERFACE_NAME_LEN];
	string ifname;
	//char type[64];
	string type;
	sigar_net_address_t hwaddr;
	sigar_net_address_t address;
	sigar_uint64_t flags;
};

class ArpList
{
private:
	unsigned long number;
	unsigned long size;
	Arp *data;
public:
	SIGAR_DECLARE(int) getArpList(sigar &, ArpList &);
	SIGAR_DECLARE(int) destroyArpList(sigar &, ArpList &);
};

#endif
