#ifndef NETMODULE_HPP_
# define NETMODULE_HPP_

#include <iostream>
#include <net/route.h>
#include <net/if.h>
#include <sys/sysctl.h>
#include <sstream>
#include "IMonitorModule.hpp"

class NetModule : public IMonitorModule {
public:
	NetModule();
	NetModule(const NetModule & rhs);
	NetModule &operator=(const NetModule & rhs);
	~NetModule();
	void 	monitorInfo();
	void getInfo();
private:
	std::string _inbytes;
	std::string _oubytes;
	std::string _inpucket;
	std::string	_oupacket;

};

#endif



