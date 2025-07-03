#ifndef PLAYER_H
#define PLAYER_H

typedef struct
{
  char symbol;
  int x;
  int y;
  char *name;
} Player;

void init_player(Player *player, const char symbol, const char *name);
void display_player(WINDOW *window, const Player *player);
void move_player(Player *player, int dx, int dy);

#endif
