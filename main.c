#include <ncurses.h>
#include <stdlib.h>
#include "player.h"

int main()
{
  Player player;
  init_player(&player, '@', "Hero");

  initscr();
  noecho();
  curs_set(0); // hides the blinking cursour
  keypad(stdscr, TRUE);

  int ch;
  while((ch = getch()) != 'q')
  {
    clear();

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

    display_player(&player);
    refresh();
  }

  getch();
  endwin();
  free(player.name);

  return 0;
}
