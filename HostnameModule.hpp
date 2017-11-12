#ifndef HOSTNAMEMODULE_HPP_
# define HOSTNAMEMODULE_HPP_

#include <iostream>
#include "IMonitor.hpp"
#include <unistd.h>
#include <climits>

class HostnameModule : public IMonitor {
public:
	HostnameModule();
	HostnameModule(const HostnameModule & rhs);
	HostnameModule &operator=(const HostnameModule & rhs);
	~HostnameModule();
	void 	monitorInfo();

};

#endif
