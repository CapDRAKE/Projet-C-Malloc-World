#include <stdio.h>
#include <stdlib.h>

//Structure du joueur
struct joueur {
    int niveau;
    float experience;
    int hp;
    int hpMAX;
    int posY;
    int posX;
};

//Déclaration de notre structure joueur
typedef struct joueur joueur;

void movement(joueur *J1) {
    char movChoise;
    printf("In which direction would you move?");
    printf("\n");
    scanf("%c", &movChoise);

    if(movChoise == 78)
        J1->posY += 1;
    else if(movChoise == 83)
        J1->posY = J1->posY - 1;
    else if(movChoise == 69)
        J1->posX += 1;
    else if(movChoise == 87)
        J1->posX = J1->posX - 1;
}


void initPlayer(joueur J1, float experience, int hp, int hpMAX, int niveau, int posX, int posY) {
    J1.experience = experience;
    J1.hp = hp;
    J1.hpMAX = hpMAX;
    J1.niveau = niveau;
    J1.posX = posX;
    J1.posY = posY;
}


void main()
{
    // Initialization of a player
    joueur *J1 = malloc(sizeof(joueur));
    J1->experience = 0;
    J1->hp = 10;
    J1->hpMAX = 10;
    J1->niveau = 0;
    J1->posX = 1;
    J1->posY = 1;
    
    //joueur *J1 = malloc(sizeof(joueur));
    
    //initPlayer(*J1,0,10,10,0,1,1);
    
    printf("Experience : %f \n HP : %d \n HP MAX : %d \n Niveau : %d \n POS X : %d \n POS Y : %d",J1->experience, J1->hp, J1->hpMAX, J1->niveau, J1->posX, J1->posY);

    // char movChoise;
    // printf("In which direction would you move?");
    // printf("\n");
    // scanf("%c", &movChoise);
    // printf("%c", movChoise);

    // if(movChoise == 78)
    //     J1->posY += 1;
    // else if(movChoise == 83)
    //     J1->posY = J1->posY - 1;
    // else if(movChoise == 69)
    //     J1->posX += 1;
    // else if(movChoise == 87)
    //     J1->posX = J1->posX - 1;
    
    movement(J1);
    
    printf("Experience : %f \n HP : %d \n HP MAX : %d \n Niveau : %d \n POS X : %d \n POS Y : %d",J1->experience, J1->hp, J1->hpMAX, J1->niveau, J1->posX, J1->posY);
    
    free(J1);
}