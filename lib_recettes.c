#include <lib_inventaire.c>

typedef struct recette recette;


struct recette{

    int codeItem;
    int zone;
    int items[2];
    int quantite[2];

};


recette* getRecette(int code){



}

recette* initRecetteEpee(int code){
    recette* res = malloc(sizeof(recette));
    res->codeItem = code;
    switch (code)
    {
    case 1:// epee en bois
        res->zone = 1;
        res->items[0] = 5; //sapin
        res->items[1] = 0; // rien
        res->quantite[0]= 3;
        res->quantite[1]= 0;
        break;
    case 8: // epee en pierre
        res->zone = 1;
        res->items[0] = 5; //sapin
        res->items[1] = 6; // pierre
        res->quantite[0]= 2;
        res->quantite[1]= 3;
        break;
    case 19: //epee en fer
        res->zone = 2;
        res->items[0] = 16; //hêtre
        res->items[1] = 17; //fer
        res->quantite[0] = 2;
        res->quantite[1] = 4;
        break;
    case 30: //epee en diamant
        res->zone = 3;
        res->items[0] = 27; //chene
        res->items[1] = 28; //diamant
        res->quantite[0] = 2;
        res->quantite[1] = 5;
        break;
    default:
        break;
    }
    return res;
}

recette* initRecetteLance (int code){
    recette* res = malloc(sizeof(recette));
    
    switch (code)
    {
    case 9: //lance en pierre
        res->zone = 1;
        res->items[0] = 5; //sapin
        res->items[1] = 6; // pierre
        res->quantite[0]= 3;
        res->quantite[1]= 4;
        break;
    case 20: //lance en fer
        res->items[0] = 16; //hêtre
        res->items[1] = 17; //fer
        res->quantite[0] = 3;
        res->quantite[1] = 4;
        break;
    case 31: //lance en diamant
        res->items[0] = 27; //chene
        res->items[1] = 28; //diamant
        res->quantite[0] = 3;
        res->quantite[1] = 6;
        break;
    default:
        break;
    }
    return res;
}
recette* initRecetteMarteau(int code){
    recette* res = malloc(sizeof(recette));
    switch (code)
    {
    case 10: //marteau en pierre
        res->zone = 1;
        res->items[0] = 5; //sapin
        res->items[1] = 6; // pierre
        res->quantite[0]= 2;
        res->quantite[1]= 6;
        break;
    case 21: //Marteau en fer
        res->items[0] = 16; //hêtre
        res->items[1] = 17; //fer
        res->quantite[0] = 2;
        res->quantite[1] = 7;
        break;
    case 32: //Marteau en diamant
        res->items[0] = 27; //chene
        res->items[1] = 28; //diamant
        res->quantite[0] = 2;
        res->quantite[1] = 8;
        break;
    default:
        break;
    }
}
//faire les autres init



int crafting (item** inventory, int code){

    recette* recet = findRecette(code);

    if (hasEnoughResource(inventory, recet->items[0], recet->quantite[0])
            &&hasEnoughResource(inventory, recet->items[1], recet->quantite[1])){
        decrementDurInTab(inventory, findPosInInventory(inventory, recet->items[0]), recet->quantite[0]);
        decrementDurInTab(inventory, findPosInInventory(inventory, recet->items[1]), recet->quantite[1]);
        return 1;
    }
    return 0;
}



