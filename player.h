#ifndef PLAYER_H
#define PLAYER_H

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
} Player;

void init_player(Player *player, const char symbol, int x, int y, const char *name, int max_health, int health, int strength, int max_mana, int mana, int speed);
void display_player(WINDOW *window, const Player *player);
void display_player_info(WINDOW *window, const Player *player);
void move_player(Player *player, int dx, int dy);

#endif
