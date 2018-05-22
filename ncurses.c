#include <ncurses.h>

int		main(void)
{
	initscr();
	
	// cbreak();
	noecho();
	int height = 10;
	int width = 20;
	int start_x, start_y;
	start_x = start_y = 10;
	
	WINDOW *win = newwin(height, width, start_y, start_x);
	refresh();
	char c = 'G';
	box(win, c, 104);
	mvwprintw(win, 1, 1, "My window");
	wrefresh(win);
	getch();
	getch();

	endwin();
	return (0);
}
