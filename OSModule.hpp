#ifndef OSMODULE_HPP_
# define OSMODULE_HPP_

#include <iostream>

class OSModule {
public:
	OSModule();
	OSModule(const OSModule & rhs);
	OSModule &operator=(const OSModule & rhs);
	virtual ~OSModule();

};

#endif
