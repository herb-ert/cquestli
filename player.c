#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void init_player(Player *player, const char symbol, const char *name)
{
   player->symbol = symbol;

   player->name = malloc(strlen(name) + 1);
   if (player->name != NULL)
   {
      strcpy(player->name, name);
   }

   player->x = 0;
   player->y = 0;
}

void display_player(WINDOW *window, const Player *player)
{
  mvwaddch(window, player->y, player->x, player->symbol);
}

void display_player_info(WINDOW *window, const Player *player)
{
  mvwprintw(window, 1, 2, "Name: %s", player->name);
}

void move_player(Player *player, int dx, int dy)
{
  player->x += dx;
  player->y += dy;
}

