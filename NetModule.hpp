#ifndef NETMODULE_HPP_
# define NETMODULE_HPP_

#include <iostream>

class NetModule {
public:
	NetModule();
	NetModule(const NetModule & rhs);
	NetModule &operator=(const NetModule & rhs);
	virtual ~NetModule();

};

#endif
