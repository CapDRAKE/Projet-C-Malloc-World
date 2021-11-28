#include <stdlib.h>
#include <stdio.h>
#include "lib_monstre.h"

int generateMonster(int minVal, int maxVal) {
    int codeMonster;
    codeMonster = rand() % 2 + 14;// Random from 1 to 10
    return codeMonster;
}

int generateMonsterZone2(int minVal, int maxVal) {

    int codeMonster;
    codeMonster = rand() % 2 + 16;// Random from 1 to 10
    return codeMonster;
}

int generateMonsterZone3(int minVal, int maxVal) {
    int codeMonster;
    codeMonster = rand() % 2 + 18;// Random from 1 to 10
    return codeMonster;
}

void generateMonsterZone1Stat(monster *M1, int codeMonsterStat) {
    switch( codeMonsterStat ){
        case 14:
            M1->hp = 5;
            M1->hpMAX = 5;
            M1->attack = 2;
            M1->name = 12; 
        case 15:
            M1->hp = 7;
            M1->hpMAX = 7;
            M1->attack = 3;
            M1->name = 12; 
    }
}

void generateMonsterZone2Stat(monster *M1, int codeMonsterStat) {
    switch( codeMonsterStat ){
        case 16:
            M1->hp = 16;
            M1->hpMAX = 16;
            M1->attack = 8;
            M1->name = 16; 
        case 17:
            M1->hp = 20;
            M1->hpMAX = 20;
            M1->attack = 5;
            M1->name = 17;  
    }
}

void generateMonsterZone3Stat(monster *M1, int codeMonsterStat) {
    switch( codeMonsterStat ){
        case 18:
            M1->hp = 25;
            M1->hpMAX = 25;
            M1->attack = 10;
            M1->name = 18; 
        case 19:
            M1->hp = 30;
            M1->hpMAX = 30;
            M1->attack = 15;
            M1->name = 19; 
    }
}

