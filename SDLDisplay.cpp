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

void SDLDisplay::get_text_and_rect(int x, int y, std::string &a,SDL_Texture **texture, SDL_Rect *rect, TTF_Font *font, SDL_Color selectedColour)
{
	int text_width;
	int text_height;
	SDL_Surface *surface;
	//SDL_Color selectedColour = {0, 0, 150, 0}; //rgb(0,106,132)
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

void     SDLDisplay::draw_info(std::string str, int x, int y, TTF_Font *font, SDL_Color selectedColour)
{
	SDL_Texture * mTexture;
	SDL_Rect tmp;
	SDL_Color textColor = {230, 223, 240, 0};
	textColor = textColor;
	get_text_and_rect(x, y, str, &mTexture, &tmp, font, selectedColour);
	SDL_RenderCopy(renderer, mTexture, NULL, &tmp);
	SDL_DestroyTexture(mTexture);
}

void SDLDisplay::start()
{TTF_Font *font;
    TTF_Font *f;
SDL_Rect rect;
SDL_Rect rec;

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
    f = TTF_OpenFont( "libraries/Aller_Rg.ttf", 25);
	SDL_Event e;
	bool quit = false;
    int useClip = 0;
SDL_Color selectedColour = {42,20,25, 0};
SDL_SetRenderDrawColor(renderer, 230, 223, 240, 0 );
SDL_Color Colour = {170,72,95, 0};
	while (1)
	{
        SDL_RenderClear(renderer);
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
				break ;
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

		rect.x = 0;
		rect.y = 0;
		rect.w = 350;
		rect.h = 400;
		SDL_SetRenderDrawColor(renderer, 210,194,238, 0 );

		SDL_RenderFillRect(renderer, &rect);
		SDL_SetRenderDrawColor(renderer, 230, 223, 240, 0 );
      SDL_Surface *bmp = SDL_LoadBMP("libraries/pony.bmp");
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, bmp);
	SDL_FreeSurface(bmp);
	rec.w = 150;
	rec.h = 150;
	rec.x = 1050;
	rec.y = 250;
	SDL_RenderCopy(renderer, tex, NULL, &rec);

        draw_info("OS Info :", 5, 0, font, selectedColour);
        draw_info("       press 1", 0, 40, font, selectedColour);
        draw_info("CPU Info : ", 5, 80, font, selectedColour);
        draw_info("       press 2", 0, 120, font, selectedColour);
        draw_info("RAM Info :", 5, 160,font, selectedColour);
        draw_info("       press 3", 0, 200,font, selectedColour);
        draw_info("NETWORK Info :", 5, 240, font, selectedColour);
        draw_info("       press 4", 0, 280, font, selectedColour);

        if (useClip == 0)
        {

        	
        	
        	draw_info("OS Info :", 5, 0, font, Colour);
        draw_info("       press 1", 0, 40, font, Colour);

            t.monitorInfo();
		      draw_info(t.getTitle(), 400, 0, f, selectedColour);
              draw_info(t.getInfo(0), 800, 0, f, selectedColour);
              draw_info(h.getTitle(), 400, 40, f, selectedColour);
              for (size_t i = 0; i < h.getSize(); i++)
               draw_info(h.getInfo(i), 800, 40 + (i * 40) , f, selectedColour);

                draw_info(os.getTitle(), 400, 120, f, selectedColour);
              for (size_t i = 0; i < os.getSize(); i++)
                draw_info(os.getInfo(i), 800, 120 + (i * 40), f, selectedColour);
        }
        if (useClip == 1){

        	draw_info("CPU Info : ", 5, 80, font, Colour);
        draw_info("       press 2", 0, 120, font, Colour);
        	cpu.monitorInfo();
          for (size_t i = 0; i < cpu.getSize(); i++)
               draw_info(cpu.getInfo(i), 400, 40 + (i * 40) , f, selectedColour);
        }
        if (useClip == 2){
        	draw_info("RAM Info :", 5, 160,font, Colour);
        draw_info("       press 3", 0, 200,font, Colour);
          	ram.monitorInfo();
          for (size_t i = 0; i < ram.getSize(); i++)
               draw_info(ram.getInfo(i), 400, 40 + (i * 40) , f, selectedColour);
        }
      if (useClip == 3){
      	draw_info("NETWORK Info :", 5, 240, font, Colour);
        draw_info("       press 4", 0, 280, font, Colour);

         	net.monitorInfo();
          for (size_t i = 0; i < net.getSize(); i++)
               draw_info(net.getInfo(i), 400, 40 + (i * 40) , f, selectedColour);
      }




        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_DestroyTexture(tex);
        if (quit == true)
            break ;
        SDL_Delay(500);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
    return ;
}
