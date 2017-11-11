#include "HostnameModule.hpp"

HostnameModule::HostnameModule() : IMonitorModule("Hostname/username module") { monitorInfo(); }
HostnameModule::HostnameModule(const HostnameModule & rhs) { *this = rhs; }
HostnameModule	&HostnameModule::operator=(const HostnameModule & rhs)
{
	return *this;
}

HostnameModule::~HostnameModule() { return; }

void HostnameModule::monitorInfo() {
	char hostname[HOST_NAME_MAX];
	char username[LOGIN_NAME_MAX];
}



