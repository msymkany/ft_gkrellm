#ifndef OSMODULE_HPP_
# define OSMODULE_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class OSModule : public IMonitorModule {
public:
	OSModule();
	OSModule(const OSModule & rhs);
	OSModule &operator=(const OSModule & rhs);
	~OSModule();

};

#endif
