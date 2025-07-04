#include <ncurses.h> 
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "item.h"

typedef enum {
  GAME_STATE_GAME,
  GAME_STATE_INVENTORY
} GameState;

int main()
{
  initscr();
  noecho();
  curs_set(0); // hides the blinking cursour
  keypad(stdscr, TRUE);
  
  int term_height, term_width;
  getmaxyx(stdscr, term_height, term_width);

  int box1_width = term_width * 3 / 4;
  int box2_width = term_width - box1_width;
  int box_height = term_height;
  int box_height_half = box_height / 2;

  WINDOW *main_window = newwin(box_height, box1_width, 0, 0);
  WINDOW *info_window = newwin(box_height_half, box2_width, 0, box1_width);
  WINDOW *inventory_window = newwin(box_height_half, box2_width, box_height_half, box1_width);

  Item items[5][4] = {0};

  Item bread;
  init_item(&bread, 0, "Bread", "Flour & Water", COMMON, CONSUMABLE);
  items[0][0] = bread;

  Player player;
  init_player(&player, '@', 1, 1, "Hero", 100, 100, 10, 200, 200, 100, 100, 1, items);
  
  GameState game_state = GAME_STATE_GAME;

  int selected_col = 0;
  int selected_row = 0;

  int ch;
  while((ch = getch()) != 'q')
  {
    switch(ch)
    {
      case 'i':
        game_state = (game_state == GAME_STATE_GAME) ? GAME_STATE_INVENTORY : GAME_STATE_GAME;
        selected_col = 0;
        selected_row = 0;
        break;
    
      case 27:
        game_state = (game_state == GAME_STATE_INVENTORY) ? GAME_STATE_GAME : GAME_STATE_GAME;
        selected_col = 0;
        selected_row = 0;
        break;
    
      default:
        if (game_state == GAME_STATE_GAME)
        {
          switch (ch)
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
        }
        else if (game_state == GAME_STATE_INVENTORY)
        {
          switch (ch)
          {
            case KEY_UP:
              if (selected_row > 0) selected_row--;
              break;
            case KEY_DOWN:
              if (selected_row < INVENTORY_ROWS - 1) selected_row++;
              break;
            case KEY_LEFT:
              if (selected_col > 0) selected_col--;
              break;
            case KEY_RIGHT:
              if (selected_col < INVENTORY_COLUMNS - 1) selected_col ++;
              break;
          }
        }
    }
    
    werase(main_window);
    box(main_window, 0, 0);
    mvwprintw(main_window, 0, 2, "Game");
    display_player(main_window, &player);
    wrefresh(main_window);
    
    werase(info_window);
    box(info_window, 0, 0);
    mvwprintw(info_window, 0, 2, "Info");
    mvwprintw(info_window, box_height - 1, 2, "(%d, %d)", player.x, player.y);
    display_player_info(info_window, &player);
    wrefresh(info_window);

    werase(inventory_window);
    box(inventory_window, 0, 0);
    mvwprintw(inventory_window, 0, 2, "Inventory");
    display_player_inventory(inventory_window, &player, selected_col, selected_row);
    wrefresh(inventory_window);
  }

  delwin(main_window);
  delwin(info_window);
  free(player.name);
  endwin();

  return 0;
}
