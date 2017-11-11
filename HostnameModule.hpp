#ifndef HOSTNAMEMODULE_HPP_
# define HOSTNAMEMODULE_HPP_

#include <iostream>

class HostnameModule {
public:
	HostnameModule();
	HostnameModule(const HostnameModule & rhs);
	HostnameModule &operator=(const HostnameModule & rhs);
	virtual ~HostnameModule();

};

#endif
