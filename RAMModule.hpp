#ifndef RAMMODULE_HPP_
# define RAMMODULE_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class RAMModule : public IMonitorModule {
public:
	RAMModule();
	RAMModule(const RAMModule & rhs);
	RAMModule &operator=(const RAMModule & rhs);
	~RAMModule();
	void 	monitorInfo();

};

#endif
