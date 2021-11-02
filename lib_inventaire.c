#include <mallib.c>

typedef struct coffre coffre;
typedef struct inventaire inventaire;


//dictionnaire avec en clef un item (la structure) et en valeur un int
struct coffre{
    listItem* key;
    listInt* value;
    listInt** hashtable;
};
struct inventaire{
    item** codes;
    int* quantite;
};

inventaire* initInventaire(){
    item** codes = malloc(sizeof(item*)*10);
    int* quantite = malloc(sizeof(int)*10);
    for (int i = 0; i<10; i++){
        codes[i] = 0;
        quantite[i]=0;
    }
}

item* initItems(int code){
    item* res = malloc(sizeof(item));
    res->code = code;
    switch (code)
    {
    case 1: //epee en bois
        res->type = ARME;
        res->value = 1;
        res->durabilite = 10;
        break;
    case 2: //pioche en bois
        res->type = OUTIL;
        res->value = 1;
        res->durabilite = 10;
        break;
    case 3: //Serpe en bois
        res->type = OUTIL;
        res->value = 1;
        res->durabilite = 10;
        break;
    case 4: //Hache en bois
        res->type = OUTIL;
        res->value = 1;
        res->durabilite = 10;
        break;
    case 5: //sapin
        res->type = RESSOURCE;
        res->value = 1;
        res->durabilite = -1;
        break;
    case 6: //pierre
        res->type = RESSOURCE;
        res->value = 1;
        res->durabilite = -1;
        break;
    case 7: //Herbe
        res->type = RESSOURCE;
        res->value = 1;
        res->durabilite = -1;
        break;
    case 8: //epee en pierre
        res->type = ARME;
        res->value = 2;
        res->durabilite = 10;
        break;
    case 9: //lance en pierre
        res->type = ARME;
        res->value = 3;
        res->durabilite = 8;
        break;
    case 10: //marteau en pierre
        res->type = ARME;
        res->value = 5;
        res->durabilite = 5;
        break;
    case 11: //plastron en pierre
        res->type = ARMURE;
        res->value = 10;
        res->durabilite = 10;
        break;
    case 12: //pioche en pierre
        res->type = OUTIL;
        res->value = 1;
        res->durabilite = 10;
        break;
    case 13: //serpe en pierre
        res->type = OUTIL;
        res->value = 1;
        res->durabilite = 10;
        break;
    case 14: //hache en pierre
        res->type = OUTIL;
        res->value = 1;
        res->durabilite = 10;
        break;
    case 15: //potion de vie I
        res->type = SOIN;
        res->value = 30;
        res->durabilite = 1;
        break;

    default:
        break;
    }
}