#include "NCurcesDisplay.hpp"

NCurcesDisplay::NCurcesDisplay() { return; }

NCurcesDisplay::NCurcesDisplay(WINDOW *wn) {
wnd = wn;
 start();
}

NCurcesDisplay::NCurcesDisplay(const NCurcesDisplay & rhs) { *this = rhs; }
NCurcesDisplay	&NCurcesDisplay::operator=(const NCurcesDisplay & rhs)
{
	c = rhs.c;
	return *this;
}

NCurcesDisplay::~NCurcesDisplay() { delwin(wnd); }


void NCurcesDisplay::start() {
	clear();
	noecho();
	curs_set(0);
	scrollok(stdscr, true);
	start_color();
	halfdelay(1);

	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	ioctl(0, TIOCGWINSZ, &wt);
	bool quit = false;
	int useClip = 0;
	while (1) {
		c = wgetch(wnd);
		switch (c) {
			case '1':
				wclear(wnd);
				useClip = 0;
				break;
			case '2':
				wclear(wnd);
				useClip = 1;
				break;
			case '3':
				wclear(wnd);
				useClip = 2;
				break;
			case '4':
				wclear(wnd);
				useClip = 3;
				break;
			case 'q':
				endwin();
				exit(0);
				break;
			default:
				break;
		}
		if (quit) {
			break;
		}

		box(wnd, 0, 0);
		wattron(wnd, COLOR_PAIR(1));
		mvwprintw(wnd, wt.ws_row / 2 - 3, 5, "OS Info :");
		mvwprintw(wnd, wt.ws_row / 2 - 2, 5, "       press 1");
		mvwprintw(wnd, wt.ws_row / 2 - 1, 5, "CPU Info : ");
		mvwprintw(wnd, wt.ws_row / 2, 5, "       press 2");
		mvwprintw(wnd, wt.ws_row / 2 + 1, 5, "RAM Info :");
		mvwprintw(wnd, wt.ws_row / 2 + 2, 5, "       press 3");
		mvwprintw(wnd, wt.ws_row / 2 + 3, 5, "NETWORK Info :");
		mvwprintw(wnd, wt.ws_row / 2 + 4, 5, "       press 4");
		wattroff(wnd, COLOR_PAIR(1));

		if (useClip == 0)
		{
			wattron(wnd, COLOR_PAIR(3));
			mvwprintw(wnd, wt.ws_row / 2 - 3, 5, "OS Info :");
			mvwprintw(wnd, wt.ws_row / 2 - 2, 5, "       press 1");
			wattroff(wnd, COLOR_PAIR(3));

			wattron(wnd, COLOR_PAIR(2));
			t.monitorInfo();
			mvwprintw(wnd, wt.ws_row / 2 - 3, wt.ws_col / 3, t.getTitle().c_str());
			mvwprintw(wnd, wt.ws_row / 2 - 3, 2 * wt.ws_col / 3, t.getInfo(0));
			mvwprintw(wnd, wt.ws_row / 2 - 1, wt.ws_col / 3, h.getTitle().c_str());
			for (size_t i = 0; i < h.getSize(); i++)
				mvwprintw(wnd, wt.ws_row / 2 - 2 + i + 1, 2 * wt.ws_col / 3, h.getInfo(i));

			mvwprintw(wnd, wt.ws_row / 2 + 1, wt.ws_col / 3, os.getTitle().c_str());
			for (size_t i = 0; i < os.getSize(); i++)
				mvwprintw(wnd, wt.ws_row / 2 + i + 2, 2 * wt.ws_col / 3, os.getInfo(i));
			wattroff(wnd, COLOR_PAIR(2));
		}
		if (useClip == 1){
			wattron(wnd, COLOR_PAIR(3));
			mvwprintw(wnd, wt.ws_row / 2 - 1, 5, "CPU Info : ");
			mvwprintw(wnd, wt.ws_row / 2, 5, "       press 2");
			wattroff(wnd, COLOR_PAIR(3));

			wattron(wnd, COLOR_PAIR(2));
			cpu.monitorInfo();
			for (size_t i = 0; i < cpu.getSize(); i++)
				mvwprintw(wnd, wt.ws_row / 2 - 3 + i + 1, wt.ws_col / 3, cpu.getInfo(i));
			wattroff(wnd, COLOR_PAIR(2));
		}
		if (useClip == 2){
			wattron(wnd, COLOR_PAIR(3));
			mvwprintw(wnd, wt.ws_row / 2 + 1, 5, "RAM Info :");
			mvwprintw(wnd, wt.ws_row / 2 + 2, 5, "       press 3");
			wattroff(wnd, COLOR_PAIR(3));

			wattron(wnd, COLOR_PAIR(2));
			ram.monitorInfo();
			for (size_t i = 0; i < ram.getSize(); i++)
				mvwprintw(wnd, wt.ws_row / 2 - 3 + i + 1, wt.ws_col / 3, ram.getInfo(i));
			wattroff(wnd, COLOR_PAIR(2));
		}
		if (useClip == 3){
			wattron(wnd, COLOR_PAIR(3));
			mvwprintw(wnd, wt.ws_row / 2 + 3, 5, "NETWORK Info :");
			mvwprintw(wnd, wt.ws_row / 2 + 4, 5, "       press 4");
			wattroff(wnd, COLOR_PAIR(3));

			wattron(wnd, COLOR_PAIR(2));
			net.monitorInfo();
			for (size_t i = 0; i < net.getSize(); i++)
				mvwprintw(wnd, wt.ws_row / 2 - 3 + i + 1, wt.ws_col / 3, net.getInfo(i));
			wattroff(wnd, COLOR_PAIR(2));
		}
		wrefresh(wnd);
		usleep(500000);
	}
}