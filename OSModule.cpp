#include "OSModule.hpp"

OSModule::OSModule(): IMonitor("OS module") { monitorInfo(); }
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
	std::string s(os.sysname);
	_info.push_back("System Name: " + s);
	s = os.release;
	_info.push_back("Release(Kernel) Version: " + s);
	std::system("defaults read /System/Library/CoreServices/SystemVersion ProductName > test.txt");
	std::ifstream my("test.txt");
	if (my)
	{
		std::getline(my, s);
		my.close();
	}
	else
		s = "Can't resolve OS name";
	_info.push_back("OS Name: " + s);
	std::system("defaults read /System/Library/CoreServices/SystemVersion ProductVersion > test.txt");
	std::getline(my, s);
	std::ifstream my2("test.txt");
	if (my2)
	{
		std::getline(my2, s);
		my2.close();
	}
	else
		s = "Can't resolve OS Version";
	_info.push_back("OS Version: " + s);
	std::system("rm -f test.txt");
	return ;
}


