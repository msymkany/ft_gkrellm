#ifndef RAMMODULE_HPP_
# define RAMMODULE_HPP_

#include <iostream>
#include "IMonitorModule.hpp"
#include <unistd.h>
#include <mach/mach_host.h>
#include <sstream>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

class RAMModule : public IMonitorModule {
public:
	RAMModule();
	RAMModule(const RAMModule & rhs);
	RAMModule &operator=(const RAMModule & rhs);
	~RAMModule();
	void 	monitorInfo();

};

#endif


