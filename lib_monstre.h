#ifndef lib_monstre
#define lib_monstre
#include <stdlib.h>
#include <stdio.h>


//Déclaration de notre structure monstre
typedef struct monster monster;

//Structure de monstre
struct monster {
    int hp;
    int hpMAX;
    int attack;
    int posY;
    int posX;
    int name;

};

int generateMonster(int minVal, int maxVal);
int generateMonsterZone2(int minVal, int maxVal);
int generateMonsterZone3(int minVal, int maxVal);

void generateMonsterZone1Stat(monster *M1, int codeMonsterStat);
void generateMonsterZone2Stat(monster *M1, int codeMonsterStat);
void generateMonsterZone3Stat(monster *M1, int codeMonsterStat);



#endif