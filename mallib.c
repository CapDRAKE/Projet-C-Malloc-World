//#include <stdlib.h>
//#include <stdio.h>
/**
 *
 * Déclaration des listes et dictionnaires de différents types.
 * les listes sont nommées ainsi : listType, ce qui donne par exemple : listInt.
 * pour les hashmap, elles sont nommées ainsi : hashmap_KV (K et V pour key et value)
 * ce qui donne par exemple hashmap_IS pour int et string;
 *
 **/

enum itemType{ARME, OUTIL, RESSOURCE, ARMURE, SOIN};


typedef struct listString listString;
typedef struct listItem listItem;
typedef struct item item;
typedef enum itemType itemType;
typedef struct listInt listInt;


struct item{
    int value;
    int code;
    int durabilite;
    itemType type;
};
struct listInt{
    int value;
    listInt* next;
};
struct listString{
    char* value;
    listString* next;
};
struct listItem{
    item* value;
    listItem* next;
};


/**
 *
 * Fonctions de déclaration des listes.
 *
 **/

//créé une listInt.
listInt* create_lint (){
    listInt* res = malloc(sizeof(listInt));
    res->value = -999999;
    return res;
}
//créé une listString
listString* create_lstring (){
    listString* res = malloc(sizeof(listString));
    return res;
}
//créé une liste d'items (utile pour le coffre)
listItem* create_litem(){
    listItem* res = malloc(sizeof(listItem));
    return res;
}

/**
*
*fonctions d'ajout de valeurs
*
**/
listInt* getLast_listInt (listInt* curs){
    while(curs->next != 0){
        curs = curs->next;
    }
    return curs;
}
listItem* getLast_listItem (listItem* curs){
    while(curs->next != 0){
        curs = curs->next;
    }
    return curs;
}

void put_listInt(listInt* liste, int value){

    if( liste->value == -999999 ){
        liste->value = value;
    }
    else{
        listInt* ajout = malloc(sizeof(listInt));
        ajout->value = value;
        liste->next = ajout;
    }
}
void put_listItem (listItem* liste, item* value){
    liste = getLast_listItem(liste);
    listItem* next = malloc(sizeof(listItem));
    next->value = value;
    liste->next = next;
}