#include <mallib.c>

typedef struct chest chest;

item** initInventory();

itemType codeType(int code);
item* initItems(int code);
item* initArmor(int code);
item* initWeapon (int code);
item* initResources (int code);
item* initTools (int code);
item* initPotion (int code);
int putInInventory(item** inventory, int code);
int decrementDurInTab (item** inventory, int pos, int nb);
int decrementDurability(item* litem);
int hasEnoughResource(item** inventory,int code, int nb);
chest* create_chest();
item* getItemInChest(chest* ches, int num);
void putItemInChest(chest* ches, item* it);
void repare(item** inventory);



// l'inventaire est juste un tableau de pointeurs d'items
item** initInventory(){ 
    item** res = malloc(sizeof(item*)*10);
    for (int i = 0; i<10; i++){
        res[i] = 0;
    }
    return res;
}
// Ajoute un item à l'inventaire, retourne 1 si réussi, sinon retourne 0
int putInInventory(item** inventory, int code){
    for (int i = 0; i <10 ;i++){
        if(inventory[i]==0){
            inventory[i]= initItems(code);
            return 1;
        }else{
            if(codeType(code)== RESSOURCE && code == inventory[i]->code && inventory[i]->durabilite <20){
                inventory[i]->durabilite +=1;
                return 1;
            }
        }
    }
    return 0;
}

void repare(item** inventory){
    for(int i =0; i<10; i++){
        if(inventory[i]->type == OUTIL || inventory[i]->type == ARME){
            inventory[i]->durabilite = 20;
        }
    }
}

//décrémente la durabilité d'un item à une position donnée. renvoi le nombre de diminition réalisé.
int decrementDurInTab (item** inventory, int pos, int nb){
    int renvoi =0;
    for (int i = 0; i<nb; i++){
        if(decrementDurability(inventory[pos])==0){
            free(inventory[pos]);
            return renvoi;
        }
        renvoi+=1;
    }
    return renvoi;
}
int decrementDurability(item* litem){
    litem->durabilite -=1;
    if (litem->durabilite<=0)
    {
        return 0;
    }else{
        return 1;
    }
}

//Vérifie si l'inventaire contient une quantite superieur a "nb" d'un item.
int hasEnoughResource(item** inventory,int code, int nb){
    int total=0;
    for (int i=0; i<10; i++ ){
        if(inventory[i]->code == code){
            total += inventory[i]->durabilite;
        }
    }
    if (total >= nb){
        return 1;
    }else{
        return 0;
    }
}

int findPosInInventory(item** tab, int code){
    for (int i = 0; i<10; i++){
        if (tab[i]->code == code){
            return i;
        }
    }
    return -1;
}


itemType codeType(int code){ // retourne le type correspondant au code de l'item
    switch (code)
    {
    case 2:
    case 3:
    case 4:
    case 12:
    case 13:
    case 14:
    case 23:
    case 24:
    case 25:
        return OUTIL;
        break;
    case 5:
    case 6:
    case 7:
    case 16:
    case 17:
    case 18:
    case 27:
    case 28:
    case 29:
        return RESSOURCE;
        break;
    case 15:
    case 26:
    case 34:
        return SOIN;
        break;
    case 11:
    case 22:
    case 33:
        return ARMURE;
        break;
    
    default:
        return ARME;
        break;
    }
}

item* initItems(int code){ //retourne un pointeur vers une nouvelle varible item
    switch (codeType(code))
    {
    case ARMURE:
        return initArmor(code);
        break;
    case ARME:
        return initWeapon(code);
        break;
    case RESSOURCE:
        return initResources(code);
        break;
    case OUTIL:
        return initTools(code);
        break;
    case SOIN:
        return initPotion(code);
        break;
    default: 
        return;
    }
}

item* initArmor(int code){
    item* res = malloc(sizeof(item));
    res->code = code;
    res->type = ARMURE;
    res->durabilite = 1;
    switch (code)
    {
    case 11: //plastron en pierre
        res->value = 10;
        break;
    case 22: //Plastron en fer
        res->value = 20;
        break;
    case 33: //Plastron en diamant
        res->value = 40;
        break;
    }
}
item* initWeapon (int code){
    item* res = malloc(sizeof(item));
    res->code = code;
    res->type = ARME;
    switch (code)
    {
    case 1: //epee en bois
        res->value = 1;
        res->durabilite = 10;
        break;
    case 8: //epee en pierre
        res->value = 2;
        res->durabilite = 10;
        break;
    case 9: //lance en pierre
        res->value = 3;
        res->durabilite = 8;
        break;
    case 10: //marteau en pierre
        res->value = 5;
        res->durabilite = 5;
        break;
    case 19: //Epee en fer
        res->value = 5;
        res->durabilite = 10;
        break;
    case 20: //Lance en fer
        res->value = 7;
        res->durabilite = 8;
        break;
    case 21: //Marteau en fer
        res->value = 10;
        res->durabilite = 5;
        break;
    case 30: //epee en diamant
        res->value = 10;
        res->durabilite = 10;
        break;
    case 31: //Lance en diamant
        res->value = 15;
        res->durabilite = 8;
        break;
    case 32: //Marteau en diamant
        res->value = 20;
        res->durabilite = 5;
        break;
    }
}

item* initResources (int code){
    item* res = malloc(sizeof(item));
    res->code = code;
    res->type = RESSOURCE;
    res->durabilite = 1;

    switch (code)
    {
    case 5: //sapin
    case 6: //pierre
    case 7: //Herbe
        res->value = 1;
        break;
    case 16: //Hêtre
    case 17: //Fer
    case 18: //Lavande 
        res->value = 2;
        break;
    case 27: //Chene
    case 28: //Diamant
    case 29: //Chanvre
        res->value = 3;
        break;
    }
}

item* initTools (int code){
    item* res = malloc(sizeof(item));
    res->code = code;
    res->type = OUTIL;
    res->durabilite = 10;

    switch (code)
    {
    case 2: //pioche en bois
    case 3: //Serpe en bois
    case 4: //Hache en bois
        res->value = 1;
        break;
    case 12: //pioche en pierre
    case 13: //serpe en pierre
    case 14: //hache en pierre
        res->value = 2;
        break;
    case 23: //Pioche en fer
    case 24: //Serpe en fer
    case 25: //Hache en fer
        res->value = 3;
        break;
    }
}

item* initPotion (int code){
    item* res = malloc(sizeof(item));
    res->code = code;
    res->type = SOIN;
    res->durabilite = 1;

    switch (code)
    {
    case 15: //potion de vie I
        res->value = 30;
        break;
    case 26: //potion de vie II
        res->value = 80;
        break;
    case 34: //Potion de soin III
        res->value = 200;
        break;
    }
}



struct chest{
    listItem* objets;
    int total;
};

chest* create_chest(){
    chest* res = malloc(sizeof(chest));
    res->objets = create_litem;
    res->total = 0;
    return res;
}
item* getItemInChest(chest* ches, int num){
    listItem* litem = ches->objets;
    if (num <= ches->total){
        for (int i = 0; i<num; i++){
            litem = litem->next;
        }
        return litem->value;
    }
    else {
        return 0;
    }
}
void putItemInChest(chest* ches, item* it){
    listItem* litem = malloc(sizeof(listItem));
    put_listItem(ches->objets, it);
}

