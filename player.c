#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

void init_player(Player *player, const char symbol, int x, int y, const char *name, int max_health, int health, int strength, int max_mana, int mana, int speed)
{
   player->symbol = symbol;

   player->name = malloc(strlen(name) + 1);
   if (player->name != NULL)
   {
      strcpy(player->name, name);
   }

   player->x = x;
   player->y = y;

   player->max_health = max_health;
   player->health = health;
   player->strength = strength;
   player->max_mana = max_mana;
   player->mana = mana;
   player->speed = speed;
}

void display_player(WINDOW *window, const Player *player)
{
  mvwaddch(window, player->y, player->x, player->symbol);
}

void display_player_info(WINDOW *window, const Player *player)
{
  mvwprintw(window, 1, 2, "Name: %s", player->name);
  mvwprintw(window, 2, 2, "Health: %d/%d", player->health, player->max_health);
  mvwprintw(window, 3, 2, "Strength: %d", player->strength);
  mvwprintw(window, 4, 2, "Mana: %d/%d", player->mana, player->max_mana);
  mvwprintw(window, 5, 2, "Speed: %d", player->speed);
}

void move_player(Player *player, int dx, int dy)
{
  player->x += dx;
  player->y += dy;
}

