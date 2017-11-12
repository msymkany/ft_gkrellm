#ifndef SDLDISPLAY_HPP_
# define SDLDISPLAY_HPP_

#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_image/SDL_image.h"
#include <iostream>
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "OSModule.hpp"
#include "RAMModule.hpp"
#include "CPUModule.hpp"
#include "NetModule.hpp"
# include "IMonitorDisplay.hpp"


#define WIDTH 1200
#define HEIGHT 400

class SDLDisplay : public IMonitorDisplay {
public:
	SDLDisplay(int l);
	SDLDisplay(const SDLDisplay & rhs);
	SDLDisplay &operator=(const SDLDisplay & rhs);
	~SDLDisplay();
	void start();
	void get_text_and_rect(int x, int y, std::string &a, SDL_Texture **texture, SDL_Rect *rect, TTF_Font *font);
	void     draw_info(std::string str, int x, int y, TTF_Font *font);

private:
	SDLDisplay();
	int i;
	SDL_Window *window;
	SDL_Renderer *renderer;
	DateTimeModule t;
	HostnameModule h;
	OSModule	os;
};

#endif
