#include "SDLDisplay.hpp"

SDLDisplay::SDLDisplay() { return ; }

SDLDisplay::SDLDisplay(const SDLDisplay & rhs) { *this = rhs; }

SDLDisplay	&SDLDisplay::operator=(const SDLDisplay & rhs)
{
	i = rhs.i;
	return *this;
}

SDLDisplay::SDLDisplay(int l) 
{ 
	if (l == 0)
		start(); 
}

SDLDisplay::~SDLDisplay() { return; }

void SDLDisplay::get_text_and_rect(int x, int y, std::string &a,SDL_Texture **texture, SDL_Rect *rect, TTF_Font *font)
{
	int text_width;
	int text_height;
	SDL_Surface *surface;
	SDL_Color selectedColour = {0, 106, 132, 0}; //rgb(0,106,132)
	surface = TTF_RenderText_Solid(font, a.c_str(), selectedColour);
	*texture = SDL_CreateTextureFromSurface(renderer, surface);
	text_width = surface->w;
	text_height = surface->h;
	SDL_FreeSurface(surface);
	rect->w = text_width;
	rect->h = text_height;
	rect->x = x;
	rect->y = y;

}

void     SDLDisplay::draw_info(std::string str, int x, int y, TTF_Font *font)
{
	SDL_Texture * mTexture;
	SDL_Rect tmp;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0 );
	SDL_Color textColor = {2, 2, 2, 0};
	textColor = textColor;
	get_text_and_rect(x, y, str, &mTexture, &tmp, font);
	SDL_RenderCopy(renderer, mTexture, NULL, &tmp);
	SDL_DestroyTexture(mTexture);
}

void SDLDisplay::start()
{
    TTF_Font *font;
    TTF_Font *f;
	window = nullptr;
	renderer = nullptr;
	if ((window = SDL_CreateWindow("RUSH_01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
					SDL_WINDOW_OPENGL)) == NULL)
		SDL_Log("%s", SDL_GetError());
	if ((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
		SDL_Log("%s", SDL_GetError());
	SDL_RenderClear(renderer);
	TTF_Init();
	font = TTF_OpenFont( "libraries/SEASRN__.ttf", 35);
    f = TTF_OpenFont( "libraries/AmaticSC-Regular.ttf", 35);
	SDL_Event e;
	bool quit = false;
    int useClip = 0;
	while (1)
	{
        SDL_RenderClear(renderer);
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if (e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym){
					case SDLK_1:
					case SDLK_KP_1:
						useClip = 0;
						break;
					case SDLK_2:
					case SDLK_KP_2:
						useClip = 1;
						break;
					case SDLK_3:
					case SDLK_KP_3:
						useClip = 2;
						break;
					case SDLK_4:
					case SDLK_KP_4:
						useClip = 3;
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
					default:
						break;
				}
			}
		}
        draw_info("OS Info :", 0, 0, font);
        draw_info("       press 1", 0, 40, font);
        draw_info("CPU Info : ", 0, 80, font);
        draw_info("       press 2", 0, 120, font);
        draw_info("RAM Info :", 0, 160,font);
        draw_info("       press 3", 0, 200,font);
        draw_info("NETWORK Info :", 0, 240, font);
        draw_info("       press 4", 0, 280, font);

        if (useClip == 0)
        {
            /*h.monitorInfo();
            
            os.monitorInfo();*/
            t.monitorInfo();
		      draw_info(t.getTitle(), 400, 0, f);
              draw_info(t.getInfo(0), 800, 0, f);
              draw_info(h.getTitle(), 400, 40, f);
              for (size_t i = 0; i < h.getSize(); i++)
               draw_info(h.getInfo(i), 800, 40 + (i * 40) , f);

                draw_info(os.getTitle(), 400, 120, f);
              for (size_t i = 0; i < os.getSize(); i++)
                draw_info(os.getInfo(i), 800, 120 + (i * 40), f);
        }
      /*  if (useClip == 1)
          draw_info("CPU Info : press 2", 0, 0);
        if (useClip == 2)
          draw_info("RAM Info : press 3", 0, 0);
      if (useClip == 2)
          draw_info("NETWORK Info : press 4", 0, 0);*/

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        if (quit == true)
            break ;

	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
    return ;
}
