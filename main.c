#include <stdio.h>
#include <stdlib.h>
#include "lib_recettes.h"
#include "lib_joueur.h"
#include "lib_monstre.h"
#include "lib_generation.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */



int generateRessources(int minVal, int maxVal ) {
    
    int codeRessources;
    codeRessources = rand() % (maxVal-100) + minVal;
    return codeRessources;
}


// ? Function to print the map during the game
int afficheMap(int** mat, int rowTriple, int col) {
    
    int i,j;
        
    for(i=0;i<rowTriple;i++) {
        for(j=0;j<col;j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// ? Main function - The first one to be executed, The menu
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

// ? Function to show the menu - Information
int menuInformations() {
    int returnMenu;
    printf("\n");
    printf("Auteur :");
    printf("\n");
    printf("\n");
    printf("- Bastien Leuwers : https://github.com/CapDRAKE");
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

// ? Function to show the main menu
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


// ? The fuction used during the playing loop 
void playGame(joueur *J1, int** mat, int row, int rowTriple) {
    int crashtest = 0;
    char choiseMode;
    
    // * While the player life is superior to 0 the game continue
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
            
            // * Print player stats
            if(choiseMode == 'c'){
                printf("Experience : %d \n HP : %d \n HP MAX : %d \n Attack : %d \n Niveau : %d \n POS X : %d \n POS Y : %d \n Name : %d \n",J1->experience, J1->hp, J1->hpMAX, J1->attack, J1->niveau, J1->posX, J1->posY, J1->name);
                printf("\n");
            }
            
            // * Use deplacement system
            else if(choiseMode == 'm') {
                movement(J1,mat,row);
                printf("\n");
            }
            // * Use deplacement system by selection a direction
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

// ? Main function, used to generate all the ressources, monster, npc, map and the player
int main() {
    
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
    
    popMonster(18, row, mat);
    popMonsterZone2(9, row, mat);
    popMonsterZone3(9, row, mat);
    popNpc(4, row, mat);
    popRessources(7, row, mat);
    printf("\n");
    
    playGame(J1,mat,row, rowTriple);
    
    for(i=0;i<rowTriple;i++) {
        for(j=0;j<col;j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    
    free(mat);
    free(J1);
    
    return 0;
    
}

