#include "NCurcesDisplay.hpp"

NCurcesDisplay::NCurcesDisplay() { 
	initDisplay();
	return; }
NCurcesDisplay::NCurcesDisplay(const NCurcesDisplay & rhs) { *this = rhs; }
NCurcesDisplay	&NCurcesDisplay::operator=(const NCurcesDisplay & rhs)
{
	return *this;
}

NCurcesDisplay::~NCurcesDisplay() { return; }


void NCurcesDisplay::initDisplay()
{
	ioctl(0, TIOCGWINSZ, &wt);
	wnd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(wnd, true);
	nodelay(wnd, true);
	curs_set(0);
	mvwprintw(wnd, wt.ws_row / 2, wt.ws_col / 2 - 16, "Graphic mode : g \t Text mode : t");
	
	while (1){
		in_char = wgetch(wnd);
		switch(in_char) {
			case 'q':
				endwin();
				exit(0);
				break;
			case 'g':
				clear();
				mvwprintw(wnd, wt.ws_row / 2, wt.ws_col / 2 - 6, "To be continue.....");
				break;
			case 't':
				start();
			default:
				break;
		}
		refresh();
	}
}

void NCurcesDisplay::start()
{
	clear();
	
}

