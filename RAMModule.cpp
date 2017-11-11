#include "RAMModule.hpp"

RAMModule::RAMModule() : IMonitorModule("Hostname/username module") { monitorInfo(); }
RAMModule::RAMModule(const RAMModule & rhs) { *this = rhs; }
RAMModule	&RAMModule::operator=(const RAMModule & rhs)
{
	_title = rhs._title;
	return *this;
}

RAMModule::~RAMModule() { return; }


