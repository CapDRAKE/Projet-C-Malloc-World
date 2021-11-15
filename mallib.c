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
/*typedef struct hashmap_IS hashmap_IS;
typedef struct hashmap_Si hashmap_SI;
typedef struct hashmap_SS hashmap_SS;*/
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

/*struct hashmap_IS {
    listInt key;
    listString value;
    listString** hashtable;
};
struct hashmap_SS{
    listString key;
    listString value;
    listString** hashtable;
};
struct hashmap_SI{
    listString key;
    listInt value;
    listInt** hashtable;
};*/


/**
 *
 * Fonctions de déclaration des listes et hashmap.
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
listItem* create_litem(){
    listItem* res = malloc(sizeof(listItem));
    return res;
}

//créé une hashmap_IS (int et string)
/*hashmap_IS create_hashmap_IS(int taillemax){
    hashmap_IS* res = malloc(sizeof(hashmap_IS));
    res->hashtable = malloc(sizeof(listString*)* taillemax);
    return res;
}
hashmap_SS create_hashmap_SS(int taillemax){
    hashmap_SS* res = malloc(sizeof(hashmap_SS));
    res->hashtable = malloc(sizeof (listString*)*taillemax);
    return res;
}
hashmap_SI create_hashmap_SI(int taillemax){
    hashmap_SI* res = malloc(sizeof(hashmap_SI));
    res->hashtable = malloc(sizeof (listInt*)*taillemax);
    return res;
}*/
/**
*
*fonctions d'ajout de valeurs
*
**/
listInt* gestLast_listInt (listInt* curs){
    while(curs->next != 0){
        curs = curs->next;
    }
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