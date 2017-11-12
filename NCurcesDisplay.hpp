#ifndef NCURCESDISPLAY_HPP_
# define NCURCESDISPLAY_HPP_

# include <iostream>
# include <ncurses.h>
# include "IMonitorDisplay.hpp"
# include <sys/ioctl.h>

class NCurcesDisplay: public IMonitorDisplay {
public:
	NCurcesDisplay();
	NCurcesDisplay(const NCurcesDisplay & rhs);
	NCurcesDisplay &operator=(const NCurcesDisplay & rhs);
	~NCurcesDisplay();
	void initDisplay();
	void start();

private:
	WINDOW *wnd;
	int in_char;
	struct winsize wt;

};

#endif
