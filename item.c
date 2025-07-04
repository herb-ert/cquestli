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

