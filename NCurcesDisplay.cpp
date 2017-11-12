#include "NCurcesDisplay.hpp"

NCurcesDisplay::NCurcesDisplay() { return; }

NCurcesDisplay::NCurcesDisplay(WINDOW *wn) {
wnd = wn;
 start(); 
}

NCurcesDisplay::NCurcesDisplay(const NCurcesDisplay & rhs) { *this = rhs; }
NCurcesDisplay	&NCurcesDisplay::operator=(const NCurcesDisplay & rhs)
{
	in_char = rhs.in_char;
	return *this;
}

NCurcesDisplay::~NCurcesDisplay() { return; }


void NCurcesDisplay::start()
{
	clear();
}

