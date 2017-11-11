#ifndef IMONITORMODULE_HPP_
# define IMONITORMODULE_HPP_

#include <iostream>

class IMonitorModule {
public:
	IMonitorModule();
	IMonitorModule(const IMonitorModule & rhs);
	IMonitorModule &operator=(const IMonitorModule & rhs);
	virtual ~IMonitorModule();

protected:
	
	std::string		_title;
	std::string		get_title() const;
	void		set_title( std::string rhs );
	
};

#endif
