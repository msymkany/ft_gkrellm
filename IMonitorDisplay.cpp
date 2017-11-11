#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay() { return; }
IMonitorDisplay::IMonitorDisplay(const IMonitorDisplay & rhs) { *this = rhs; }
IMonitorDisplay	&IMonitorDisplay::operator=(const IMonitorDisplay & rhs)
{
	return *this;
}

IMonitorDisplay::~IMonitorDisplay() { return; }


bool		IMonitorDisplay::getdisplay() const { return display; }
	void	IMonitorDisplay::setdisplay( bool rhs ) { display = rhs; }
