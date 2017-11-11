#ifndef RAMMODULE_HPP_
# define RAMMODULE_HPP_

#include <iostream>

class RAMModule {
public:
	RAMModule();
	RAMModule(const RAMModule & rhs);
	RAMModule &operator=(const RAMModule & rhs);
	virtual ~RAMModule();

};

#endif
