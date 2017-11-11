#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule() { return; }

IMonitorModule::IMonitorModule(std::string title) : _title(title) {
}

IMonitorModule::IMonitorModule(const IMonitorModule & rhs) { *this = rhs; }
IMonitorModule	&IMonitorModule::operator=(const IMonitorModule & rhs)
{
	_title = rhs._title;
	return *this;
}

IMonitorModule::~IMonitorModule() { return; }


std::string		IMonitorModule::get_title() const { return _title; }
size_t IMonitorModule::getSize() const {
	return _info.size();
}

const char *IMonitorModule::getInfo(size_t i) const { return _info[i].c_str(); }