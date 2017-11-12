#include "IMonitor.hpp"

IMonitor::IMonitor() { return; }

IMonitor::IMonitor(std::string title) : _title(title) {
}

IMonitor::IMonitor(const IMonitor & rhs) { *this = rhs; }
IMonitor	&IMonitor::operator=(const IMonitor & rhs)
{
	_title = rhs._title;
	return *this;
}

IMonitor::~IMonitor() { return; }


std::string		IMonitor::getTitle() const { return _title; }
size_t IMonitor::getSize() const {
	return _info.size();
}

const char *IMonitor::getInfo(size_t i) const { return _info[i].c_str(); }