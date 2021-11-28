#include "lib_generation.h"


int popMonster(int max, int row, int** mat) {

    int monster = generateMonster(14, 15);
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;

    for (int inc = 0; inc < max; inc++) {
        if (mat[randomCase][randomCase2] == 0) {
            mat[randomCase][randomCase2] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row + 1;
            monster = generateMonster(14, 15);
        }
        else {
            randomCase = rand() % row - 1;
            randomCase2 = rand() % row - 1;
            monster = generateMonster(14, 15);
            inc--;
        }
    }

    return mat[randomCase][randomCase2];
}


int popMonsterZone2(int max, int row, int** mat) {
    int total = row + 1;
    int monster = generateMonsterZone2(16, 17);
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;

    for (int inc = 0; inc < max; inc++) {
        if (mat[randomCase + total][randomCase2 + total] == 0) {
            mat[randomCase + total][randomCase2 + total] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row + 1;
            monster = generateMonsterZone2(16, 17);
        }
        else {
            randomCase = rand() % row - 1;
            randomCase2 = rand() % row - 1;
            monster = generateMonsterZone2(16, 17);
            inc--;
        }
    }

    return mat[randomCase + total][randomCase2 + total];
}

int popMonsterZone3(int max, int row, int** mat) {


    int monster = generateMonster(14, 15);
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;

    for (int inc = 0; inc < max; inc++) {
        if (mat[randomCase][randomCase2] == 0) {
            mat[randomCase][randomCase2] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row + 1;
            monster = generateMonster(14, 15);
        }
        else {
            randomCase = rand() % row - 1;
            randomCase2 = rand() % row - 1;
            monster = generateMonster(14, 15);
            inc--;
        }
    }

    return mat[randomCase][randomCase2];
}

int generateNpc(int minVal, int maxVal) {

    int codeNpc;

    // -- SINGLE VERSION --
    codeNpc = rand() % maxVal + minVal; // Random from 1 to 10
    //printf("%d", codeNpc);

    // -- MULTIPLE VERSION --
    //for(int i=1; i<10; i++) {
    //    codeNpc = rand() % maxVal + minVal; // Random from 1 to 10
    //    printf("\n");
    //    printf("%d", codeNpc);
    //}  

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
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
        }
        else {
            randomCaseNpc = rand() % row - 1;
            randomCaseNpc2 = rand() % row - 1;
            npc = generateNpc(30, 40);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
            inc--;
        }
    }

    return mat[randomCaseNpc][randomCaseNpc2];
}

int generateRessources(int minVal, int maxVal) {

    int codeRessources;

    // -- SINGLE VERSION --
    codeRessources = rand() % (maxVal - 100) + minVal; // Random from 1 to 10

    //printf("%d", codeNpc);

    // -- MULTIPLE VERSION --
    //for(int i=1; i<10; i++) {
    //    codeNpc = rand() % maxVal + minVal; // Random from 1 to 10
    //    printf("\n");
    //    printf("%d", codeNpc);
    //}  

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
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
        }
        else {
            randomCaseRessource = rand() % row - 1;
            randomCaseRessource2 = rand() % row - 1;
            ressources = generateRessources(100, 110);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
            inc--;
        }
    }

    return mat[randomCaseRessource][randomCaseRessource2];
}

