#ifndef lib_inventaire
#define lib_inventaire
#include "mallib.h"

typedef struct chest chest;
struct chest;

//fonctions de gestion de l'inventaire
item** initInventory();
int putInInventory(item** inventory, int code);
int decrementDurInTab(item** inventory, int pos, int nb);
int hasEnoughResource(item** inventory, int code, int nb);
void repare(item** inventory);
int findPosInInventory(item** tab, int code);

//fonctions de gestion du coffre du pnj
chest* create_chest();
item* getItemInChest(chest* ches, int num);
void putItemInChest(chest* ches, item* it);

//fonctions de gestion des items
itemType codeType(int code);
item* initItems(int code);
item* initArmor(int code);
item* initWeapon(int code);
item* initResources(int code);
item* initTools(int code);
item* initPotion(int code);
int decrementDurability(item* litem);

#endif