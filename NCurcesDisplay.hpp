#ifndef NCURCESDISPLAY_HPP_
# define NCURCESDISPLAY_HPP_

# include <iostream>
# include <ncurses.h>
# include "IMonitorDisplay.hpp"
# include <sys/ioctl.h>


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
	int in_char;
	//struct winsize wt;

};

#endif
