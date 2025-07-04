#ifndef PLAYER_H
#define PLAYER_H

#define INVENTORY_COLUMNS 5
#define INVENTORY_ROWS 4

#include "item.h"

typedef struct
{
  char symbol;
  int x;
  int y;
  char *name;
  int max_health;
  int health;
  int strength;
  int max_mana;
  int mana;
  int speed;
  int exp;
  int level;
  Item items[INVENTORY_COLUMNS][INVENTORY_ROWS];
} Player;

void init_player(Player *player, const char symbol, int x, int y, const char *name, int max_health, int health, int strength, int max_mana, int mana, int speed, int exp, int level, Item items[5][4]);
void display_player(WINDOW *window, const Player *player);
void display_player_info(WINDOW *window, const Player *player);
void display_player_inventory(WINDOW *window, const Player *player, int selected_col, int selected_row);
void move_player(Player *player, int dx, int dy);

#endif
