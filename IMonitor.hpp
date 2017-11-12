#ifndef IMONITORMODULE_HPP_
# define IMONITORMODULE_HPP_

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"

class IMonitor : public IMonitorModule {
public:
	virtual ~IMonitor();
	std::string		getTitle() const;

	const char *getInfo(size_t i) const;
	size_t 	getSize() const;
	virtual void 	monitorInfo() = 0;

protected:
	IMonitor();
	IMonitor(std::string title);
	IMonitor(const IMonitor & rhs);
	IMonitor &operator=(const IMonitor & rhs);
	std::string					_title;
	std::vector<std::string>	_info;
};

#endif
