#include "OSModule.hpp"

OSModule::OSModule(): IMonitorModule("OS module") { monitorInfo(); }
OSModule::OSModule(const OSModule & rhs) { *this = rhs; }
OSModule	&OSModule::operator=(const OSModule & rhs)
{
	_title = rhs._title;
	return *this;
}

OSModule::~OSModule() { return; }

void OSModule::monitorInfo() {
	struct utsname os;

	uname(&os);
	std::cout << "System Name: "<< os.sysname << std::endl;
	std::cout << "Host Name: "<< os.nodename << std::endl;
	std::cout << "Release(Kernel) Version: "<< os.release << std::endl;
	std::cout << "Kernel Build Timestamp: "<< os.version << std::endl;
	std::cout << "Machine Arch: "<< os.machine << std::endl;
//	std::cout << "Domain Name: "<< os.domainname << std::endl;
	return ;
}


