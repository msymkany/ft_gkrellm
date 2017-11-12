#ifndef CPUMODULE_HPP_
# define CPUMODULE_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

#include <ctime>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <iostream>
#include <sstream>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <mach/mach_host.h>
#define BUFFERLEN 128

class CPUModule : public IMonitorModule {
public:
	CPUModule();
	CPUModule(const CPUModule & rhs);
	CPUModule &operator=(const CPUModule & rhs);
	virtual ~CPUModule();
	void 	monitorInfo();
	double activity();
	std::string ncpu();
	std::string total();
};


#endif
