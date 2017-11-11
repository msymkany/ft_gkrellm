#ifndef DATETIMEMODULE_HPP_
# define DATETIMEMODULE_HPP_

#include <iostream>

class DateTimeModule {
public:
	DateTimeModule();
	DateTimeModule(const DateTimeModule & rhs);
	DateTimeModule &operator=(const DateTimeModule & rhs);
	virtual ~DateTimeModule();

};

#endif
