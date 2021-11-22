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
int attack(){
   return 0; 
}

//Augmentation du level
void leveling(){

}

//Fuire 
int run(){
    return 0;
}


void droite(int **mat) {
  
}

int generateMonster(int minVal, int maxVal ) {
    
    int codeMonster;
    int cumul = maxVal + minVal;
    
    // -- SINGLE VERSION --
    codeMonster = rand() % maxVal + minVal; // Random from 1 to 10
    //printf("%d", codeMonster);
    
    // -- MULTIPLE VERSION --
    //for(int i=0; i<10; i++) {
    //    codeMonster = rand() % cumul; // Random from 1 to 10
    //    printf("\n");
    //    printf("%d", codeMonster);
    //}
    
    return codeMonster;
}


int popMonster(int max, int row, int** mat) {
    
    int monster = generateMonster(10,20);
    int randomCase = rand() % row;
    int randomCase2 = rand() % row;
    
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCase][randomCase2] == 0) {
            mat[randomCase][randomCase2] = monster;
            
            randomCase = rand() % row;
            randomCase2 = rand() % row+1;
            monster = generateMonster(10,20);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
        }
        else {
            randomCase = rand() % row-1;
            randomCase2 = rand() % row-1;
            monster = generateMonster(10,20);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
            inc--;
        }
    }
    
    return mat[randomCase][randomCase2];
}

int generateNpc(int minVal, int maxVal ) {
    
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
    
    int npc = generateNpc(2,2);
    int randomCaseNpc = rand() % row;
    int randomCaseNpc2 = rand() % row;
    
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCaseNpc][randomCaseNpc2] == 0) {
            mat[randomCaseNpc][randomCaseNpc2] = 2;
            
            randomCaseNpc = rand() % row;
            randomCaseNpc2 = rand() % row+1;
            npc = generateNpc(2,2);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
        }
        else {
            randomCaseNpc = rand() % row-1;
            randomCaseNpc2 = rand() % row-1;
            npc = generateNpc(30,40);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
            inc--;
        }
    }
    
    return mat[randomCaseNpc][randomCaseNpc2];
}

int generateRessources(int minVal, int maxVal ) {
    
    int codeRessources;
    
    // -- SINGLE VERSION --
    codeRessources = rand() % maxVal + minVal; // Random from 1 to 10
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
    
    int ressources = generateRessources(100,110);
    int randomCaseRessource = rand() % row;
    int randomCaseRessource2 = rand() % row;
    
    for(int inc=0;inc<max;inc++) {
        if(mat[randomCaseRessource][randomCaseRessource2] == 0) {
            mat[randomCaseRessource][randomCaseRessource2] = ressources;
            
            randomCaseRessource = rand() % row;
            randomCaseRessource2 = rand() % row+1;
            ressources = generateRessources(100,110);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
        }
        else {
            randomCaseRessource = rand() % row-1;
            randomCaseRessource2 = rand() % row-1;
            ressources = generateRessources(100,110);
            //printf("Case random 1 : %d and case random2 : %d", randomCase, randomCase2);
            //printf("\n");
            inc--;
        }
    }
    
    return mat[randomCaseRessource][randomCaseRessource2];
}


int afficheMap(int** mat, int row) {
    
    int i,j;
        
    for(i=0;i<row;i++) {
        for(j=0;j<row;j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

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


void movement(joueur *J1, int** mat, int row) {
    char movChoise;
    printf("In which direction would you move?");
    printf("\n");
    scanf("%c", &movChoise);
    while(movChoise != 78 && movChoise != 83 && movChoise != 69 &&  movChoise != 87) {
        printf("Bad answer, retry ! (N, S, E, W allowed)");
        printf("\n");
        scanf("%c", &movChoise);
    }
    
    if(movChoise == 78) {
        if((J1->posY) == 0) {
            printf("You can't go up there ! Choise another way ! \n");
            movement(J1,mat,row);
        }
        else {
            J1->posY = J1->posY - 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[(J1->posY)+1][J1->posX] = 0;
        }
    }
    else if(movChoise == 83) {
        if((J1->posY) == row-1) {
            printf("You can't go up there ! Choise another way ! \n");
            movement(J1,mat,row);
        }
        else {
            J1->posY += 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[(J1->posY)-1][J1->posX] = 0;
        }
    }
    else if(movChoise == 69) {
        if((J1->posX) == row-1) {
            printf("You can't go up there ! Choise another way ! \n");
            movement(J1,mat,row);
        }
        else  {
            J1->posX += 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[J1->posY][(J1->posX)-1] = 0;
        }
    }
    else if(movChoise == 87) {
        if((J1->posX) == 0) {
            printf("You can't go up there ! Choise another way ! \n");
            movement(J1,mat,row);
        }
        else {
            J1->posX = J1->posX - 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[J1->posY][(J1->posX)+1] = 0;
        }
    }
}

void playGame(joueur *J1, int** mat, int row) {
    int crashtest = 0;
    int choiseMode;
    
    while(crashtest < 10) {
        printf("\n");
        afficheMap(mat, row);
        printf("\n");
        
        printf("--------------------------------");
        printf("\n");
        printf("|  What action would you do ?  |");
        printf("\n");
        printf("|      Print your stats - 1    |");
        printf("\n");
        printf("|           Move - 2           |");
        printf("\n");
        printf("--------------------------------");
        printf("\n");
        
        scanf("%d", &choiseMode);
        printf("\n");
        
        if(choiseMode == 1){
            printf("Experience : %f \n HP : %d \n HP MAX : %d \n Niveau : %d \n POS X : %d \n POS Y : %d \n Name : %d \n",J1->experience, J1->hp, J1->hpMAX, J1->niveau, J1->posX, J1->posY, J1->name);
            printf("\n");
        }
        
        else if(choiseMode == 2) {
            movement(J1,mat,row);
            printf("\n");
        }
    
         crashtest+=1;
    }
        
 
    
    
    // while(choiseMode ) {
    //     printf("\n");
    //     // Affichage de la carte 
    //     // afficheMap(mat, row);
    
    //     printf("\n");
    
    //     movement(J1,mat);
    
    //     printf("\n");
    
    //     printf("Experience : %f \n HP : %d \n HP MAX : %d \n Niveau : %d \n POS X : %d \n POS Y : %d \n Name : %d \n",J1->experience, J1->hp, J1->hpMAX, J1->niveau, J1->posX, J1->posY, J1->name);
    
    //     printf("\n");
    
    //     afficheMap(mat, row);
    
    //     printf("\n");
        
    //     crashtest+=1;
    // }
    
}



int main() {
    //printf("Nous générons un monstre : ");
    //generateMonster(1, 15);  
    
    //printf("\n");
    
    //printf("Nous générons un NPC : ");
    //generateNpc(16, 30);
    
    
    int **mat, row, col, i, j, n, gameChoise;

    // * Initialization of a player
    joueur *J1 = malloc(sizeof(joueur));
    J1->experience = 0;
    J1->hp = 10;
    J1->hpMAX = 10;
    J1->niveau = 0;
    J1->posX = 0;
    J1->posY = 0;
    J1->name = 16;

    
    mainMenu();
    
    
    printf("Choose a size for your game grid :");
    printf("\n");
    //scanf("%d", &row);
    row = 7;
    mat = (int **)malloc(row*sizeof(int *));
    
    col = row;

    for(i=0;i<row;i++) {
        mat[i]=(int *)malloc(col*sizeof(int));
    }

    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if (j == 0 && i == 0){
                mat[i][j] = J1->name;
            }
            else 
                mat[i][j] = 0;
            // if (i == 0)
            // {
            //     mat[i][j] = -1;
            // }
            // else if (i == row-1){
            //     mat[i][j] = -1;
            // }
            // else if (j == 0){
            //     mat[i][j] = -1;
            // }
            // else if (j == col-1){
            //     mat[i][j] = -1;
            // }
            // else if (j == 1 && i == 1){
            //     mat[i][j] = J1->name;
            // }
            // //else if (mat[randomCase][randomCase2] == 0) {
            // //mat[randomCase][randomCase2] = 15;
            // //}
            // else {
            //     //n = rand()%10 + 4;
            //     mat[i][j] = 0;
            
        }
    }
    
    printf("\n");
    
    
    printf("Experience : %f \n HP : %d \n HP MAX : %d \n Niveau : %d \n POS X : %d \n POS Y : %d \n Name : %d \n",J1->experience, J1->hp, J1->hpMAX, J1->niveau, J1->posX, J1->posY, J1->name);
    // Generation des éléments présent sur la carte
    popMonster(10, row, mat);
    popNpc(4, row, mat);
    popRessources(10, row, mat);
    
    playGame(J1,mat,row);
    // Affichage de la carte 
    // afficheMap(mat, row);
    
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