#ifndef CPUMODULE_HPP_
# define CPUMODULE_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule {
public:
	CPUModule();
	CPUModule(const CPUModule & rhs);
	CPUModule &operator=(const CPUModule & rhs);
	virtual ~CPUModule();
	void 	monitorInfo();

};


#endif
