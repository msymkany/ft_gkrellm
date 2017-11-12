#ifndef SDLDISPLAY_HPP_
# define SDLDISPLAY_HPP_

#include <iostream>

class SDLDisplay {
public:
	SDLDisplay();
	SDLDisplay(const SDLDisplay & rhs);
	SDLDisplay &operator=(const SDLDisplay & rhs);
	virtual ~SDLDisplay();

};

#endif
