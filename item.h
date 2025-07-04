#ifndef ITEM_H
#define ITEM_H

typedef enum
{
  COMMON = 0,
  UNCOMMON = 1,
  RARE = 2,
  EPIC = 3,
  LEGENDARY = 4,
} Rarity;

typedef enum
{
  CONSUMABLE = 0,
} Category;

typedef struct
{
  int id;
  char *name;
  char *description;
  Rarity rarity;
  Category category;
} Item;

void init_item(Item *item, int id, char *name, char *description, Rarity rarity, Category category);
char* get_rarity_name(Rarity rarity);
char* get_category_name(Category category);
int get_rarity_color(Rarity rarity);

#endif
