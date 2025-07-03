#include <ncurses.h>
#include "player.h"

int main()
{
  Player player;
  init_player(&player, '@', "Hero");

  initscr();
  noecho();
  curs_set(0); // hides the blinking cursour
  display_player(&player);
  refresh();
  getch();
  endwin();

  return 0;
}
