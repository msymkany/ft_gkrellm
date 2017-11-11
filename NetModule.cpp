#include "NetModule.hpp"

NetModule::NetModule() : IMonitorModule("Hostname/username module") { monitorInfo(); }
NetModule::NetModule(const NetModule & rhs) { *this = rhs; }
NetModule	&NetModule::operator=(const NetModule & rhs)
{
	_title = rhs._title;
	return *this;
}

NetModule::~NetModule() { return; }


