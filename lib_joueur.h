#ifndef lib_joueur
#define lib_joueur
#include <stdio.h>
#include <stdlib.h>
#include "lib_monstre.h"
#include "lib_inventaire.h"

//D�claration de notre structure joueur
typedef struct joueur joueur;

//Structure du joueur
struct joueur {
    int niveau;

    int experience;
    int hp;
    int hpMAX;
    int attack;
    int posY;
    int posX;
    int name;
    item** inventory;
};

void leveling(int xp, joueur* J1);
void teleportationZone(joueur* J1, int** mat);
void fall(joueur* J1, int** mat, int row);
void northMov(joueur* J1, int** mat, int row);
void southMov(joueur* J1, int** mat, int row);
void eastMov(joueur* J1, int** mat, int row);
void westMov(joueur* J1, int** mat, int row);
void movement(joueur* J1, int** mat, int row);

void actionCaseUsed(joueur* J1, int** mat, char dir, int row);
void fightWest(joueur* J1, int** mat);
void fightEast(joueur* J1, int** mat);
void fightNorth(joueur* J1, int** mat, int codeStatMonster);
void fightSouth(joueur* J1, int** mat, int codeStatMonster);

#endif