#ifndef NETMODULE_HPP_
# define NETMODULE_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class NetModule : public IMonitorModule {
public:
	NetModule();
	NetModule(const NetModule & rhs);
	NetModule &operator=(const NetModule & rhs);
	~NetModule();

};

#endif
