#ifndef OSMODULE_HPP_
# define OSMODULE_HPP_

#include <iostream>
#include "IMonitorModule.hpp"
#include <sys/utsname.h>

class OSModule : public IMonitorModule {
public:
	OSModule();
	OSModule(const OSModule & rhs);
	OSModule &operator=(const OSModule & rhs);
	~OSModule();
	void 	monitorInfo();

};

#endif
