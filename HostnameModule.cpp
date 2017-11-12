#include "HostnameModule.hpp"

HostnameModule::HostnameModule() : IMonitor("Hostname/username module") {
	monitorInfo();
}
HostnameModule::HostnameModule(const HostnameModule & rhs) { *this = rhs; }
HostnameModule	&HostnameModule::operator=(const HostnameModule & rhs)
{
	_title = rhs._title;
	return *this;
}

HostnameModule::~HostnameModule() { return; }

void HostnameModule::monitorInfo() {
	char hostname[_SC_HOST_NAME_MAX];
	char username[_SC_LOGIN_NAME_MAX];

	if (!_info.empty())
		_info.erase(_info.begin(), _info.end());
	if (gethostname(hostname, _SC_HOST_NAME_MAX))
		_info.push_back("Can't resolve hostname");
	else
	{
		std::string h(hostname);
		_info.push_back(h);
	}
	if (getlogin_r(username, _SC_LOGIN_NAME_MAX))
		_info.push_back("Can't resolve username");
	else
	{
		std::string u(username);
		_info.push_back(u);
	}
}
