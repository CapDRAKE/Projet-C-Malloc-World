#ifndef mallib
#define mallib
#include <stdlib.h>
#include <stdio.h>
enum itemType { ARME, OUTIL, RESSOURCE, ARMURE, SOIN };


typedef struct listString listString;
typedef struct listItem listItem;
typedef struct item item;
typedef enum itemType itemType;
typedef struct listInt listInt;

struct item {
    int value;
    int code;
    int durabilite;
    itemType type;
};
struct listInt {
    int value;
    listInt* next;
};
struct listString {
    char* value;
    listString* next;
};
struct listItem {
    item* value;
    listItem* next;
};

listInt* create_lint();
listString* create_lstring();
listItem* create_litem();

listInt* getLast_listInt(listInt* curs);
listItem* getLast_listItem(listItem* curs);
void put_listInt(listInt* liste, int value);
void put_listItem(listItem* liste, item* value);


#endif