#include <stdio.h>
#include <stdlib.h>     /* srand, rand */

//Structure du joueur
struct joueur {
    int niveau;
    float experience;
    int hp;
    int hpMAX;
    int posY;
    int posX;
    int name;
};
//Déclaration de notre structure joueur
typedef struct joueur joueur;

//Attaque du joueur
int attack(int mob, int poxY, int posX){
   return 0; 
}

//Augmentation de l'xp ainsi que du level
void leveling(int xp, joueur *J1){
    J1->experience = J1->experience + xp;
    if(experience == 50 && J1->niveau == 1){//passage niv 2 +10hp
        J1->niveau = 2;
        J1->hpMAX += 10;
        J1->hp = J1->hpMAX;
    }
    else if(experience == 60 && J1->niveau == 2){//passage niv 3
        J1->niveau = 3;
        J1->hpMAX += 20;
        J1->hp = J1->hpMAX;
    }
    else if(experience == 70 && J1->niveau == 3){//passage niv 4
        J1->niveau = 4;
        J1->hpMAX += 30;
        J1->hp = J1->hpMAX;
    }
    else if(experience == 80 && J1->niveau == 4){//passage niv 5
        J1->niveau = 5;
        J1->hpMAX += 40;
        J1->hp = J1->hpMAX;
    }
    else if((experience == 90 && J1->niveau == 5) || (experience == 95 && J1->niveau == 6) || (experience == 100 && J1->niveau == 7)){//passage niv 6,7,8
        J1->niveau += 1;
        J1->hpMAX += 50;
        J1->hp = J1->hpMAX;
    }
    else if((experience == 110 && J1->niveau == 8) || (experience == 115 && J1->niveau == 9)){//passage niv 9,10
        J1->niveau += 1;
        J1->hpMAX += 75;
        J1->hp = J1->hpMAX;
    }
}