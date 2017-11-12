#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule() : IMonitor("Date/time module") { monitorInfo(); }
DateTimeModule::DateTimeModule(const DateTimeModule & rhs) { *this = rhs; }
DateTimeModule	&DateTimeModule::operator=(const DateTimeModule & rhs)
{
	_title = rhs._title;
	return *this;
}

DateTimeModule::~DateTimeModule() { return; }

void		DateTimeModule::monitorInfo() {

	std::time_t     now = time(0);
	char       buf[80];
	std::string t;

	if (!_info.empty())
		_info.erase(_info.begin(), _info.end());
	std::strftime(buf, sizeof(buf), "%Y-%m-%d.%X", std::localtime(&now));
	t = buf;
	_info.push_back(t);
}
