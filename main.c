#include <ncurses.h> 
#include <stdlib.h>
#include "player.h"

int main()
{
  initscr();
  noecho();
  curs_set(0); // hides the blinking cursour
  keypad(stdscr, TRUE);
  
  int term_height, term_width;
  getmaxyx(stdscr, term_height, term_width);

  int box1_width = term_width * 3 / 4;
  int box2_width = term_width - box1_width;
  int box_height = term_height;

  WINDOW *main_window = newwin(box_height, box1_width, 0, 0);
  WINDOW *side_window = newwin(box_height, box2_width, 0, box1_width);

  Player player;
  init_player(&player, '@', "Hero");
    
  int ch;
  while((ch = getch()) != 'q')
  {
    switch(ch)
    {
      case KEY_UP:
        move_player(&player, 0, -1);
        break;
      case KEY_DOWN:
        move_player(&player, 0, 1);
        break;
      case KEY_LEFT:
        move_player(&player, -1, 0);
        break;
      case KEY_RIGHT:
        move_player(&player, 1, 0);
        break;
    }
    
    werase(main_window);
    box(main_window, 0, 0);
    mvwprintw(main_window, 0, 2, " Game ");
    display_player(main_window, &player);
    wrefresh(main_window);

    werase(side_window);
    box(side_window, 0, 0);
    mvwprintw(side_window, 0, 2, " Info ");
    mvwprintw(side_window, 2, 2, "Name: %s", player.name);
    mvwprintw(side_window, 3, 2, "Pos (%d, %d)", player.x, player.y);
    wrefresh(side_window);
  }

  delwin(main_window);
  delwin(side_window);
  free(player.name);
  endwin();

  return 0;
}
