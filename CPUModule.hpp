#ifndef CPUMODULE_HPP_
# define CPUMODULE_HPP_

#include <iostream>

class CPUModule {
public:
	CPUModule();
	CPUModule(const CPUModule & rhs);
	CPUModule &operator=(const CPUModule & rhs);
	virtual ~CPUModule();

};

#endif
