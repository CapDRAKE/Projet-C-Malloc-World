#include "lib_generation.h"


int popMonster(int max, int row, int** mat) {

    int monster = generateMonster(14,15);
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;
    
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCase][randomCase2] == 0) {
            mat[randomCase][randomCase2] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row+1;
            monster = generateMonster(14,15);
        }
        else {
            randomCase = rand() % row-1;
            randomCase2 = rand() % row-1;
            monster = generateMonster(14,15);
            inc--;
        }
    }
    return mat[randomCase][randomCase2];
}

int popMonsterZone2(int max, int row, int** mat) {
    int total = row+1;
    int monster = generateMonsterZone2(16,17);
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;
    
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCase+total][randomCase2+total] == 0) {
            mat[randomCase+ total][randomCase2+ total] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row+1;
            monster = generateMonsterZone2(16,17);
        }
        else {
            randomCase = rand() % row-1;
            randomCase2 = rand() % row-1;
            monster = generateMonsterZone2(16,17);
            inc--;
        }
    }
    return mat[randomCase+ total][randomCase2+ total];
}

int popMonsterZone3(int max, int row, int** mat) {
    int total = row*2;
    int monster = generateMonsterZone3(18,19);
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;
    
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCase+total][randomCase2+total] == 0) {
            mat[randomCase+ total][randomCase2+ total] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row+1;
            monster = generateMonsterZone3(18,19);
        }
        else {
            randomCase = rand() % row-1;
            randomCase2 = rand() % row-1;
            monster = generateMonsterZone3(18,19);
            inc--;
        }
    }
    return mat[randomCase+total][randomCase2+total];

}

int generateNpc(int minVal, int maxVal) {

    int codeNpc;
    codeNpc = rand() % maxVal + minVal; // Random from 1 to 10

    return codeNpc;
}

int popNpc(int max, int row, int** mat) {
    int npc = generateNpc(2, 2);
    int randomCaseNpc = rand() % row;
    int randomCaseNpc2 = rand() % row;

    for (int inc = 0; inc < max; inc++) {
        if (mat[randomCaseNpc][randomCaseNpc2] == 0) {
            mat[randomCaseNpc][randomCaseNpc2] = 2;

            randomCaseNpc = rand() % row;
            randomCaseNpc2 = rand() % row + 1;
            npc = generateNpc(2, 2);
        }
        else {
            randomCaseNpc = rand() % row - 1;
            randomCaseNpc2 = rand() % row - 1;
            npc = generateNpc(30, 40);
            inc--;
        }
    }
    return mat[randomCaseNpc][randomCaseNpc2];
}

int generateRessources(int minVal, int maxVal) {

    int codeRessources;
    codeRessources = rand() % (maxVal - 100) + minVal; // Random from 1 to 10

    return codeRessources;
}

int popRessources(int max, int row, int** mat) {
    int ressources = generateRessources(100, 110);
    int randomCaseRessource = rand() % row;
    int randomCaseRessource2 = rand() % row;

    for (int inc = 0; inc < max; inc++) {
        if (mat[randomCaseRessource][randomCaseRessource2] == 0) {
            mat[randomCaseRessource][randomCaseRessource2] = ressources;

            randomCaseRessource = rand() % row;
            randomCaseRessource2 = rand() % row + 1;
            ressources = generateRessources(100, 110);
        }
        else {
            randomCaseRessource = rand() % row - 1;
            randomCaseRessource2 = rand() % row - 1;
            ressources = generateRessources(100, 110);
            inc--;
        }
    }
    return mat[randomCaseRessource][randomCaseRessource2];
}

