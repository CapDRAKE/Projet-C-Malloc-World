#include <stdlib.h>
#include <stdio.h>

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

