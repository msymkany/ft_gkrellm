#include "CPUModule.hpp"

CPUModule::CPUModule(): IMonitorModule("CPU module") { monitorInfo(); }
CPUModule::CPUModule(const CPUModule & rhs) { *this = rhs; }
CPUModule	&CPUModule::operator=(const CPUModule & rhs)
{
	_title = rhs._title;
	return *this;
}

CPUModule::~CPUModule() { return; }

void CPUModule::monitorInfo() {
	//	Your code here
}
