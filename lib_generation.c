#include "lib_generation.h"

// ? Generate a random position (X,Y) to insert a monster in the 1st Zone
int popMonster(int max, int row, int** mat) {

    // * Random between 14 and 15
    int monster = generateMonster(14,15);
    // * Random on the row number
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;
    // * Set the monster on the map thanks to the random position
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCase][randomCase2] == 0) {
            mat[randomCase][randomCase2] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row+1;
            monster = generateMonster(14,15);
        }
        // * If the position is already used, select a new position
        else {
            randomCase = rand() % row-1;
            randomCase2 = rand() % row-1;
            monster = generateMonster(14,15);
            inc--;
        }
    }
    return mat[randomCase][randomCase2];
}

// ? Generate a random position (X,Y) to insert a monster in the 2nd Zone
int popMonsterZone2(int max, int row, int** mat) {
    int total = row+1;
    // * Random between 16 and 17
    int monster = generateMonsterZone2(16,17);
    // * Random on the row number
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;
    // * Set the monster on the map thanks to the random position
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCase+total][randomCase2+total] == 0) {
            mat[randomCase+ total][randomCase2+ total] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row+1;
            monster = generateMonsterZone2(16,17);
        }
        // * If the position is already used, select a new position
        else {
            randomCase = rand() % row-1;
            randomCase2 = rand() % row-1;
            monster = generateMonsterZone2(16,17);
            inc--;
        }
    }
    return mat[randomCase+ total][randomCase2+ total];
}

// ? Generate a random position (X,Y) to insert a monster in the 3rd Zone
int popMonsterZone3(int max, int row, int** mat) {
    int total = row*2;
    // * Random between 18 and 19
    int monster = generateMonsterZone3(18,19);
    // * Random on the row number
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;
    // * Set the monster on the map thanks to the random position
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCase+total][randomCase2+total] == 0) {
            mat[randomCase+ total][randomCase2+ total] = monster;
            randomCase = rand() % row;
            randomCase2 = rand() % row+1;
            monster = generateMonsterZone3(18,19);
        }
        // * If the position is already used, select a new position
        else {
            randomCase = rand() % row-1;
            randomCase2 = rand() % row-1;
            monster = generateMonsterZone3(18,19);
            inc--;
        }
    }
    return mat[randomCase+total][randomCase2+total];

}

// ? Generate a code to create an NPC
int generateNpc(int minVal, int maxVal) {

    int codeNpc;
    codeNpc = rand() % maxVal + minVal;

    return codeNpc;
}

// ? Generate a random position (X,Y) to insert an NPC in the map
int popNpc(int max, int row, int** mat) {
    // * Random between 2 and 2
    int npc = generateNpc(2, 2);
    // * Random on the row number
    int randomCaseNpc = rand() % row;
    int randomCaseNpc2 = rand() % row;
    // * Set the NPC on the map thanks to the random position
    for (int inc = 0; inc < max; inc++) {
        if (mat[randomCaseNpc][randomCaseNpc2] == 0) {
            mat[randomCaseNpc][randomCaseNpc2] = 2;

            randomCaseNpc = rand() % row;
            randomCaseNpc2 = rand() % row + 1;
            npc = generateNpc(2, 2);
        }
        // * If the position is already used, select a new position
        else {
            randomCaseNpc = rand() % row - 1;
            randomCaseNpc2 = rand() % row - 1;
            npc = generateNpc(30, 40);
            inc--;
        }
    }
    return mat[randomCaseNpc][randomCaseNpc2];
}

// ? Generate a code to create a ressources
int generateRessources(int minVal, int maxVal) {

    int codeRessources;
    codeRessources = rand() % (maxVal - 100) + minVal;

    return codeRessources;
}

// ? Generate a random position (X,Y) to insert a ressources in the map
int popRessources(int max, int row, int** mat) {
    // * Random between 100 and 110
    int ressources = generateRessources(100, 110);
    // * Random on the row number
    int randomCaseRessource = rand() % row;
    int randomCaseRessource2 = rand() % row;
    // * Set the Ressources on the map thanks to the random position
    for (int inc = 0; inc < max; inc++) {
        if (mat[randomCaseRessource][randomCaseRessource2] == 0) {
            mat[randomCaseRessource][randomCaseRessource2] = ressources;

            randomCaseRessource = rand() % row;
            randomCaseRessource2 = rand() % row + 1;
            ressources = generateRessources(100, 110);
        }
        // * If the position is already used, select a new position
        else {
            randomCaseRessource = rand() % row - 1;
            randomCaseRessource2 = rand() % row - 1;
            ressources = generateRessources(100, 110);
            inc--;
        }
    }
    return mat[randomCaseRessource][randomCaseRessource2];
}

