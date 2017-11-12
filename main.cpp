// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 17:00:17 by msymkany          #+#    #+#             //
//   Updated: 2017/11/11 17:00:21 by msymkany         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitor.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "OSModule.hpp"
#include "RAMModule.hpp"
#include "CPUModule.hpp"
#include "NetModule.hpp"
#include "NCurcesDisplay.hpp"
#include "SDLDisplay.hpp"

void 	testModule(void)
{
	DateTimeModule t;
	HostnameModule h;
	OSModule	os;

	std::cout<< std::endl;
	std::cout << t.getTitle() << std::endl;
	std::cout << t.getInfo(0) << std::endl;
	std::cout<< std::endl;
	sleep(5);
	t.monitorInfo();
	std::cout<< std::endl;
//	std::cout << t.getTitle() << std::endl;
	std::cout << t.getInfo(0) << std::endl;
	std::cout<< std::endl;

//	std::cout << h.getTitle() << std::endl;
//	for (size_t i = 0; i < h.getSize(); i++)
//	{
//		std::cout << h.getInfo(i) << std::endl;
//	}
//	std::cout<< std::endl;
//
//	std::cout << os.getTitle() << std::endl;
//	for (size_t i = 0; i < os.getSize(); i++)
//	{
//		std::cout << os.getInfo(i) << std::endl;
//	}
//	std::cout<< std::endl;
//
//	std::cout << "RAM info"<< std::endl;
//	RAMModule ram;
//	for (size_t i = 0; i < ram.getSize(); i++)
//	{
//		std::cout << ram.getInfo(i) << std::endl;
//	}
//	std::cout<< std::endl;
//
//	std::cout << "CPU info"<< std::endl;
//	CPUModule cpu;
//	for (size_t i = 0; i < cpu.getSize(); i++)
//	{
//		std::cout << cpu.getInfo(i) << std::endl;
//	}
//	std::cout<< std::endl;
//
//	std::cout << "NET info"<< std::endl;
//	NetModule net;
//	for (size_t i = 0; i < net.getSize(); i++)
//	{
//		std::cout << net.getInfo(i) << std::endl;
//	}
//	std::cout<< std::endl;

}

void ncur(WINDOW *wnd)
{
	NCurcesDisplay n(wnd);
}

void sdl()
{
	SDLDisplay sdl(0);
}

int main()
{
	//testModule();
	WINDOW *wnd;
	int in_char;
	struct winsize wt;

	ioctl(0, TIOCGWINSZ, &wt);
	int a = 0;
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
		if (a == 1)
		{
			sdl();
			in_char = 'q';
		}
		if (a == 2)
			in_char = 'q';
		switch(in_char) {
			case 'q':
				endwin();
				exit(0);
				break;
			case 'g':
				clear();
				mvwprintw(wnd, wt.ws_row / 2, wt.ws_col / 2 - 6, "To be continue.....");
				a = 1;
				break;
			case 't':
				ncur(wnd);
				a = 2;
			default:
				break;
		}
		refresh();
	}
	endwin();
	return 0;
}