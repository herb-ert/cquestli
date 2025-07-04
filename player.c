#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "item.h"

void init_player(Player *player, const char symbol, int x, int y, const char *name, int max_health, int health, int strength, int max_mana, int mana, int speed, int exp, int level, Item items[5][4])
{
   player->name = malloc(strlen(name) + 1);
   if (player->name != NULL)
   {
      strcpy(player->name, name);
   }

   for (int i = 0; i < INVENTORY_COLUMNS; i++)
   {
     for (int j = 0; j < INVENTORY_ROWS; j++)
     {
       player->items[i][j] = items[i][j];
     }
   }

   player->symbol = symbol;
   player->x = x;
   player->y = y;
   player->max_health = max_health;
   player->health = health;
   player->strength = strength;
   player->max_mana = max_mana;
   player->mana = mana;
   player->speed = speed;
   player->exp = exp;
   player->level = level;
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

void display_player_inventory(WINDOW *window, const Player *player, int selected_col, int selected_row)
{
  int win_height, win_width;
  getmaxyx(window, win_height, win_width);

  const int cell_width = 3;
  const int start_y = 1;

  int grid_width = INVENTORY_COLUMNS * cell_width;
  int start_x = (win_width - grid_width) / 2;

  for (int row = 0; row < INVENTORY_ROWS; row++)
  {
    for (int col = 0; col < INVENTORY_COLUMNS; col++)
    {
      int x = start_x + col * cell_width;
      int y = start_y + row;

      Item item = player->items[col][row];
      
      if (col == selected_col && row == selected_row)
      {
        wattron(window, A_REVERSE);
      }

      if (item.name != NULL)
      {
        mvwprintw(window, y, x, "[%c]", item.name[0]);
      }
      else
      {
        mvwprintw(window, y, x, "[ ]");
      }

      if (col == selected_col && row == selected_row)
      {
        wattroff(window, A_REVERSE);
      }
    }
  }
}

void move_player(Player *player, int dx, int dy)
{
  player->x += dx;
  player->y += dy;
}

