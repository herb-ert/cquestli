#ifndef PLAYER_H
#define PLAYER_H

typedef struct
{
  char symbol;
  char *name;
  int x;
  int y;
} Player;

void init_player(Player *player, const char symbol, const char *name);
void display_player(const Player *player);
void move_player(Player *player, int dx, int dy);

#endif
