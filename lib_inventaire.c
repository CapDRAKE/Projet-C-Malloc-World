#include <mallib.c>

typedef struct coffre coffre;
typedef struct inventory inventory;

inventory* initinventory();
itemType codeType(int code);
item* initItems(int code);
item* initArmor(int code);
item* initWeapon (int code);
item* initResources (int code);
item* initTools (int code);
item* initPotion (int code);



//dictionnaire avec en clef un item (la structure) et en valeur un int
struct coffre{
    listItem* key;
    listInt* value;
    listInt** hashtable;
};
struct inventory{
    item** codes;
    int* quantity;
};

inventory* initinventory(){
    item** codes = malloc(sizeof(item*)*10);
    int* quantity = malloc(sizeof(int)*10);
    for (int i = 0; i<10; i++){
        codes[i] = 0;
        quantity[i]=0;
    }
}

itemType codeType(int code){ // retourne le type correspondant au code
    switch (code)
    {
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

item* initItems(int code){
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