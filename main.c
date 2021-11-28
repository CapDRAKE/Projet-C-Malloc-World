#include <stdio.h>
#include <stdlib.h>
#include "lib_recettes.h"
#include "lib_joueur.h"
#include "lib_monstre.h"
#include "lib_generation.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */





int afficheMap(int** mat, int rowTriple, int col) {
    
    int i,j;
        
    for(i=0;i<rowTriple;i++) {
        for(j=0;j<col;j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int mainMenu();
int menuCommandes() {
    int returnMenu;
    printf("\n");
    printf(" - Malloc World Alpha Version 0.0.1 -");
    printf("\n");
    printf("\n");
    printf("Déplacements : Haut (h), Bas (b), Gauche (g) et Droite (d)");
    printf("\n");
    printf("\n");
    printf("Lors du déplacement il est possible de rencontré un obstacle :");
    printf("\n");
    printf("- Monstre : Vous allez devoir combatre ou fuir !");
    printf("\n");
    printf("- Ressources : Vous pourrez ramassez ces dernière mais attantion à votre inventaire !");
    printf("\n");
    printf("- NPC : Les PNJ vous permetterons de crafter et de réparer vos items !");
    printf("\n");
    printf("- Portail : Vous pourrez vous déplacez dans plusieurs monde sous certaines conditions !");
    printf("\n");
    printf("\n");
    printf("Retourner au Menu Principale? (1 : Yes)");
    printf("\n");
    
    scanf("%d", &returnMenu);
    if(returnMenu == 1) {
        printf("\n");
        mainMenu();
    }
}

int menuInformations() {
    int returnMenu;
    printf("\n");
    printf("Auteur :");
    printf("\n");
    printf("\n");
    printf("- Bastien Lewers : https://github.com/CapDRAKE");
    printf("\n");
    printf("- Nicolas Cortial : https://github.com/IreshDeragon");
    printf("\n");
    printf("- Allan Barbot : https://github.com/CurtainShow");
    printf("\n");
    printf("\n");
    printf("Durée du projet : 2 mois");
    printf("\n");
    printf("\n");
    printf("Licence du projet : MIT");
    printf("\n");
    printf("\n");
    printf("Retourner au Menu Principale? (1 : Yes)");
    printf("\n");
    
    scanf("%d", &returnMenu);
    if(returnMenu == 1) {
        printf("\n");
        mainMenu();
    }
}

int mainMenu() {
    int gameChoise;

    printf(" Welcome to Malloc World !");
    printf("\n");
    printf("   -     Jouer (1)    - ");
    printf("\n");
    printf("   -   Commandes (2)  - ");
    printf("\n");
    printf("   - Informations (3) - ");
    printf("\n");
    
    scanf("%d", &gameChoise);
    if(gameChoise > 3 || gameChoise < 1) {
        printf("Choix invalide, réessayer !");
        printf("\n");
        scanf("%d", &gameChoise);
    }
    else if(gameChoise == 2) {
        menuCommandes();
    }
    else if(gameChoise == 3) {
        menuInformations();
    }
    
}



void playGame(joueur *J1, int** mat, int row, int rowTriple) {
    int crashtest = 0;
    char choiseMode;
    
    while(J1->hp > 0) {
        if(J1->hp > 0) {
            printf("\n");
            afficheMap(mat, rowTriple, row);
            printf("\n");
            
            printf("--------------------------------");
            printf("\n");
            printf("|  What action would you do ?  |");
            printf("\n");
            printf("--------------------------------");
            printf("\n");
            printf("|      Print your stats - c    |");
            printf("\n");
            printf("|   Print your Inventory - i   |");
            printf("\n");
            printf("--------------------------------");
            printf("\n");
            printf("|       Move to North - n      |");
            printf("\n");
            printf("|       Move to South - s      |");
            printf("\n");
            printf("|        Move to East - e      |");
            printf("\n");
            printf("|        Move to West - w      |");
            printf("\n");
            printf("--------------------------------");
            printf("\n");
            
            scanf("%c", &choiseMode);
            printf("\n");
            
            if(choiseMode == 'c'){
                printf("Experience : %d \n HP : %d \n HP MAX : %d \n Attack : %d \n Niveau : %d \n POS X : %d \n POS Y : %d \n Name : %d \n",J1->experience, J1->hp, J1->hpMAX, J1->attack, J1->niveau, J1->posX, J1->posY, J1->name);
                printf("\n");
            }
            
            else if(choiseMode == 'm') {
                movement(J1,mat,row);
                printf("\n");
            }
            else if(choiseMode == 'n')
                northMov(J1,mat,row);
                
            else if(choiseMode == 's')
                southMov(J1,mat,row);
                
            else if(choiseMode == 'e')
                eastMov(J1,mat,row);
                
            else if(choiseMode == 'w')
                westMov(J1,mat,row);
    
        }
    }
}


int main() {
    //printf("Nous générons un monstre : ");
    //generateMonster(1, 15);  
    
    //printf("\n");
    
    //printf("Nous générons un NPC : ");
    //generateNpc(16, 30);
    
    
    int **mat, row, rowTriple, col, i, j, n, gameChoise;

    // * Initialization of a player
    joueur *J1 = initPlayer();
    
    
    mainMenu();
    
    
    printf("Choose a size for your game grid :");
    printf("\n");
    //scanf("%d", &row);
    row = 10;
    rowTriple = (row*3)+2;
    printf("%d", rowTriple);
    mat = (int **)malloc(rowTriple*sizeof(int *));
    
    col = row;

    for(i=0;i<rowTriple;i++) {
        mat[i]=(int *)malloc(col*sizeof(int));
    }

    for(i=0;i<rowTriple;i++) {
        for(j=0;j<row;j++) {
            if (j == 0 && i == 0){
                mat[i][j] = J1->name;
            }
            else if (j == 0 && i == row-1){
                mat[i][j] = -2;
            }
            else if (j == 0 && i == (row*2)){
                mat[i][j] = -3;
            }
            else if (i == row){
                mat[i][j] = -1;
            }
            else if (i == (row*2)+1){
                mat[i][j] = -1;
            }
            else 
                mat[i][j] = 0;
        }
    }
    
    printf("\n");
    
    // for(i=0;i<rowTriple;i++) {
    //     for(j=0;j<col;j++) {
    //         printf("%d\t", mat[i][j]);
    //     }
    //     printf("\n");
    // }
    
    
    // printf("HP : %d \n HP MAX : %d \n Attack : %d \n POS X : %d \n POS Y : %d \n Name : %d \n",M1->hp, M1->hpMAX, M1->attack, M1->posX, M1->posY, M1->name);
    // Generation des éléments présent sur la carte
    popMonster(9, row, mat);
    popMonsterZone2(9, row, mat);
    popNpc(4, row, mat);
    popRessources(9, row, mat);
    
    playGame(J1,mat,row, rowTriple);
    // Affichage de la carte 
    // afficheMap(mat, rowTriple, col);
    
    // printf("\n");
    
    // movement(J1,mat);
    
    // printf("\n");
    
    // printf("Experience : %f \n HP : %d \n HP MAX : %d \n Niveau : %d \n POS X : %d \n POS Y : %d \n Name : %d \n",J1->experience, J1->hp, J1->hpMAX, J1->niveau, J1->posX, J1->posY, J1->name);
    
    // printf("\n");
    
    // afficheMap(mat, row);
    
    // printf("\n");
    
    
    return 0;
    
    free(mat);
    free(J1);
}


// TODO : Faire la TP dans tout les sens.
// ! 24/11

// TODO : Faire pop des monstres.
// ! 24/11 - 25/11

// TODO : Fonction de combats et leveling.
// ! 24/11 - 25/11

// TODO : Comprendre l'inventaire et en crée un pour le joueur.
