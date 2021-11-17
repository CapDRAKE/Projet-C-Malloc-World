#include <lib_inventaire.c>

typedef struct recette recette;

recette* initRecette(int code);
recette* initRecetteEpee(int code);
recette* initRecetteLance (int code);
recette* initRecetteMarteau(int code);
recette* initRecettePlastron(int code);
recette* initRecetteTools (int code);
recette* initRecettePotion (int code);

//crafting est la seule fonction ayant une utilisation extérieure au script.
int crafting (item** inventory, int code);



struct recette{

    int codeItem;
    int zone;
    int items[2];
    int quantite[2];

};

recette* initRecette(int code){
    switch (code)
    {
    case 1:
    case 8:
    case 19:
    case 30:
        return initRecetteEpee(code);
        break;
    case 9:
    case 20:
    case 31:
        return initRecetteLance(code);
        break;
    case 10:
    case 21:
    case 32:
        return initRecetteMarteau(code);
        break;
    case 11:
    case 22:
    case 33:
        return initRecettePlastron(code);
        break;
    case 2:
    case 3:
    case 4:
    case 12:
    case 13:
    case 14:
    case 23:
    case 24:
    case 25:
        return initRecetteTools(code);
        break;
    case 15:
    case 26:
    case 34:
        return initRecettePotion(code);
        break;
    default:
        return 0;
        break;
    }

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
        res->zone = 2;
        res->items[0] = 16; //hêtre
        res->items[1] = 17; //fer
        res->quantite[0] = 3;
        res->quantite[1] = 4;
        break;
    case 31: //lance en diamant
        res->zone = 3;
        res->items[0] = 27; //chene
        res->items[1] = 28; //diamant
        res->quantite[0] = 3;
        res->quantite[1] = 6;
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
        res->zone = 2;
        res->items[0] = 16; //hêtre
        res->items[1] = 17; //fer
        res->quantite[0] = 2;
        res->quantite[1] = 7;
        break;
    case 32: //Marteau en diamant
        res->zone = 3;
        res->items[0] = 27; //chene
        res->items[1] = 28; //diamant
        res->quantite[0] = 2;
        res->quantite[1] = 8;
        break;
    }
    return res;
}
//faire les autres init
recette* initRecettePlastron(int code){
    recette* res = malloc(sizeof(recette));
    switch (code)
    {
    case 11: //Plastron en pierre
        res->zone = 1;
        res->items[0] = 6; //pierre
        res->items[1] = 0; //rien
        res->quantite[0] = 10;
        res->quantite[1] = 0;
        break;
    case 22: //Plastron en fer
        res->zone = 2;
        res->items[0] = 17; //fer
        res->items[1] = 0; //rien
        res->quantite[0] = 12;
        res->quantite[1] = 0;
        break;
    case 33: //Plastron en diamant
        res->zone = 3;
        res->items[0] = 28; //diamant
        res->items[1] = 0; //rien
        res->quantite[0] = 16;
        res->quantite[1] = 0;
        break;
    }
    return res;
}

recette* initRecetteTools (int code){
    recette* res = malloc(sizeof(recette));
    switch (code)
    {
    case 2: //pioche en bois
    case 3: //Serpe en bois
    case 4: //Hache en bois
        res->zone = 1;
        res->items[0] = 5; //sapin
        res->items[1] = 0; //rien
        res->quantite[0] = 3;
        res->quantite[1] = 0;
        break;
    case 12: //pioche en pierre
    case 13: //serpe en pierre
    case 14: //hache en pierre
        res->zone = 1;
        res->items[0] = 5; //sapin
        res->items[1] = 6; //pierre
        res->quantite[0] = 2;
        res->quantite[1] = 3;
        break;
    case 23: //Pioche en fer
    case 24: //Serpe en fer
    case 25: //Hache en fer
        res->zone = 2;
        res->items[0] = 16; //hetre
        res->items[1] = 17; //fer
        res->quantite[0] = 2;
        res->quantite[1] = 4;
        break;
    }
    return res;
}
recette* initRecettePotion (int code){
    recette* res = malloc(sizeof(recette));
    switch (code)
    {
    case 15: //Potion de vie 1
        res->zone = 1;
        res->items[0] = 7; //herbe
        res->items[1] = 0; //rien
        res->quantite[0] = 2;
        res->quantite[1] = 0;
        break;
    case 26: //Potion de vie 2
        res->zone = 2;
        res->items[0] = 18; //lavande
        res->items[1] = 0; //rien
        res->quantite[0] = 2;
        res->quantite[1] = 0;
        break;
    case 34: //Potion de vie 3
        res->zone = 3;
        res->items[0] = 29; //chanvre
        res->items[1] = 0; //rien
        res->quantite[0] = 2;
        res->quantite[1] = 0;
        break;
    }
    return res;
}


int crafting (item** inventory, int code){

    recette* recet = initRecette(code);

    if (hasEnoughResource(inventory, recet->items[0], recet->quantite[0])
            &&hasEnoughResource(inventory, recet->items[1], recet->quantite[1])){
        decrementDurInTab(inventory, findPosInInventory(inventory, recet->items[0]), recet->quantite[0]);
        decrementDurInTab(inventory, findPosInInventory(inventory, recet->items[1]), recet->quantite[1]);
        return 1;
    }
    return 0;
}



