#ifndef lib_generation
#define lib_generation
#include <stdlib.h>
#include <stdio.h>
#include "lib_monstre.h"

int popMonster(int max, int row, int** mat);
int popMonsterZone2(int max, int row, int** mat);
int popMonsterZone3(int max, int row, int** mat);
int generateNpc(int minVal, int maxVal);
int popNpc(int max, int row, int** mat);
int generateRessources(int minVal, int maxVal);
int popRessources(int max, int row, int** mat);


#endif