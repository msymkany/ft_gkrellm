#ifndef DATETIMEMODULE_HPP_
# define DATETIMEMODULE_HPP_

#include <iostream>
#include <ctime>
#include "IMonitorModule.hpp"

class DateTimeModule : public IMonitorModule {
public:
	DateTimeModule();
	DateTimeModule(const DateTimeModule & rhs);
	DateTimeModule &operator=(const DateTimeModule & rhs);
	~DateTimeModule();
	void 	monitorInfo();

};

#endif

