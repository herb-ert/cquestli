#ifdef _WIN32
  #include "curses.h"
#else
  #include <ncurses.h>
#endif
#include <stdlib.h>
#include <string.h>
#include "item.h"

void init_item(Item *item, int id, char *name, char *description, Rarity rarity, Category category)
{
  item->id = id;
 
  item->name = malloc(strlen(name) + 1);
  if (item->name != NULL)
  {
    strcpy(item->name, name);
  }

  item->description = malloc(strlen(description) + 1);
  if (item->description != NULL)
  {
    strcpy(item->description, description);
  }

  item->rarity = rarity;
  item->category = category;
}

char* get_rarity_name(Rarity rarity)
{
  switch (rarity)
  {
    case COMMON: 
      return "Common";
    case UNCOMMON:
      return "Uncommon";
    case RARE:
      return "Rare";
    case EPIC:
      return "Epic";
    case LEGENDARY:
      return "Legendary";
    default:
      return "Unknown";
  }
}

char* get_category_name(Category category)
{
  switch (category)
  {
    case CONSUMABLE:
      return "Consumable";
  }
}

int get_rarity_color(Rarity rarity)
{
  switch (rarity)
  {
    case COMMON:
      return COLOR_PAIR(1);
    case UNCOMMON:
      return COLOR_PAIR(2);
    case RARE:
      return COLOR_PAIR(3);
    case EPIC:
      return COLOR_PAIR(4);
    case LEGENDARY:
      return COLOR_PAIR(5);
  }
}

