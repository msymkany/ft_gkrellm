#ifndef NCURCESDISPLAY_HPP_
# define NCURCESDISPLAY_HPP_

# include <iostream>
# include <ncurses.h>
# include "IMonitorDisplay.hpp"
# include <sys/ioctl.h>
# include <unistd.h>
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "OSModule.hpp"
#include "RAMModule.hpp"
#include "CPUModule.hpp"
#include "NetModule.hpp"

class NCurcesDisplay: public IMonitorDisplay {
public:
	NCurcesDisplay(const NCurcesDisplay & rhs);
	NCurcesDisplay(WINDOW *wn);
	NCurcesDisplay &operator=(const NCurcesDisplay & rhs);
	~NCurcesDisplay();
	void start();

private:
	NCurcesDisplay();
	WINDOW *wnd;
	int c;
	struct winsize wt;

	DateTimeModule t;
	HostnameModule h;
	OSModule	os;
	CPUModule cpu;
	RAMModule ram;
	NetModule net;
};

#endif
