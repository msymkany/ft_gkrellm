#ifndef IMONITORMODULE_HPP_
# define IMONITORMODULE_HPP_

#include <iostream>
#include <vector>

class IMonitorModule {
public:
	virtual ~IMonitorModule();
	std::string		getTitle() const;

	const char *getInfo(size_t i) const;
	size_t 	getSize() const;
	virtual void 	monitorInfo() = 0;

protected:
	IMonitorModule();
	IMonitorModule(std::string title);
	IMonitorModule(const IMonitorModule & rhs);
	IMonitorModule &operator=(const IMonitorModule & rhs);
	std::string					_title;
	std::vector<std::string>	_info;
};

#endif
