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

void display_player(const Player *player)
{
  mvprintw(player->y, player->x, "%c", player->symbol);
}

