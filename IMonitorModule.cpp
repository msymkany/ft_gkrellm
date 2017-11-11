#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule() { return; }
IMonitorModule::IMonitorModule(const IMonitorModule & rhs) { *this = rhs; }
IMonitorModule	&IMonitorModule::operator=(const IMonitorModule & rhs)
{
	return *this;
}

IMonitorModule::~IMonitorModule() { return; }


std::string		IMonitorModule::get_title() const { return _title; }
	void	IMonitorModule::set_title( std::string rhs ) { _title = rhs; }
