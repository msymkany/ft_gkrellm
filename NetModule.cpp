#include "NetModule.hpp"

NetModule::NetModule() : IMonitor("Hostname/username module") { monitorInfo(); }
NetModule::NetModule(const NetModule & rhs) { *this = rhs; }
NetModule	&NetModule::operator=(const NetModule & rhs)
{
	_title = rhs._title;
	return *this;
}

NetModule::~NetModule() { return; }

void NetModule::monitorInfo() {
	int         mib[6];
	char         *lim;
	char         *next;
	size_t         len;
	struct         if_msghdr *ifm;

	long int     ipackets = 0;
	long int     opackets = 0;
	long int     ibytes = 0;
	long int     obytes = 0;

    mib[0]= CTL_NET;// networking subsystem
    mib[1]= PF_ROUTE;// type of information
    mib[2]= 0;// protocol (IPPROTO_xxx)
    mib[3]= 0;// address family
    mib[4]= NET_RT_IFLIST2;// operation
    mib[5]= 0;

    sysctl(mib, 6, NULL, &len, NULL, 0);
    char buf[len];
    sysctl(mib, 6, buf, &len, NULL, 0);

    lim = buf + len;
    for (next = buf; next < lim; ) {
        ifm = (struct if_msghdr *)next;
        next += ifm->ifm_msglen;

        if (ifm->ifm_type == RTM_IFINFO2) {
            struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;

            if(if2m->ifm_data.ifi_type!=18) {
                opackets += if2m->ifm_data.ifi_opackets;
                ipackets += if2m->ifm_data.ifi_ipackets;
                obytes   += if2m->ifm_data.ifi_obytes;
                ibytes   += if2m->ifm_data.ifi_ibytes;
            }
        }
    }
	if (!_info.empty())
		_info.erase(_info.begin(), _info.end());
    std::ostringstream stream;
    stream << static_cast<double>(ibytes) / 1000000000.0;
    _info.push_back("Data received:  " + stream.str().substr(0, 7));

    std::ostringstream stream2;
    stream2 << static_cast<double>(obytes) / 1000000000.0;
	_info.push_back("Data send:  " + stream2.str().substr(0, 7));

    std::ostringstream stream3;
    stream3 <<  ipackets;
	_info.push_back("Packets in:  " + stream3.str());

    std::ostringstream stream4;
    stream4 << opackets;
	_info.push_back("Packets out:  " + stream4.str());

//	std::cout << _inbytes << " : input bytes" << std::endl;
//	std::cout << _oubytes << " : out bytes" << std::endl;
//	std::cout << _inpucket << " : input pakets" << std::endl;
//	std::cout << _oupacket << " : out pakets" << std::endl;
}
