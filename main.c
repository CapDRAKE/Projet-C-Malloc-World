#include <stdio.h>
#include <stdlib.h>     /* srand, rand */

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
};

//Structure de monstre
struct monster {
    int hp;
    int hpMAX;
    int attack;
    int posY;
    int posX;
    int name;
};

//Déclaration de notre structure joueur
typedef struct joueur joueur;

//Déclaration de notre structure monstre
typedef struct monster monster;

//Attaque du joueur
int attack(){
   return 0; 
}

//Fuire 
int run(){
    return 0;
}


void droite(int **mat) {
  
}

int generateMonster(int minVal, int maxVal) {
    int codeMonster;
    codeMonster = rand() % 2 + 14;// Random from 1 to 10
    return codeMonster;
}

int generateMonsterZone2(int minVal, int maxVal) {
    int codeMonster;
    codeMonster = rand() % 2 + 16;// Random from 1 to 10
    return codeMonster;
}

int generateMonsterZone3(int minVal, int maxVal) {
    int codeMonster;
    codeMonster = rand() % 2 + 18;// Random from 1 to 10
    return codeMonster;
}


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
    codeRessources = rand() % (maxVal-100) + minVal; // Random from 1 to 10
    
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

void leveling(int xp, joueur *J1){
    J1->experience = J1->experience + xp;
    if(J1->experience >= 40 && J1->niveau == 1){//passage niv 2 +10hp
        J1->niveau = 2;
        J1->hpMAX += 10;
        J1->hp = J1->hpMAX;
    }
    else if(J1->experience >= 80 && J1->niveau == 2){//passage niv 3
        J1->niveau = 3;
        J1->hpMAX += 20;
        J1->hp = J1->hpMAX;
    }
    else if(J1->experience >= 100 && J1->niveau == 3){//passage niv 4
        J1->niveau = 4;
        J1->hpMAX += 30;
        J1->hp = J1->hpMAX;
    }
    else if(J1->experience >= 150 && J1->niveau == 4){//passage niv 5
        J1->niveau = 5;
        J1->hpMAX += 40;
        J1->hp = J1->hpMAX;
    }
    else if((J1->experience >= 200 && J1->niveau == 5) || (J1->experience >= 250 && J1->niveau == 6) || (J1->experience >= 300 && J1->niveau == 7)){//passage niv 6,7,8
        J1->niveau += 1;
        J1->hpMAX += 50;
        J1->hp = J1->hpMAX;
    }
    else if((J1->experience >= 350 && J1->niveau == 8) || (J1->experience >= 400 && J1->niveau == 9)){//passage niv 9,10
        J1->niveau += 1;
        J1->hpMAX += 75;
        J1->hp = J1->hpMAX;
    }
}

void fightSouth(joueur *J1,int ** mat, int codeStatMonster) {
    int actionCombat;
    monster *M1 = malloc(sizeof(monster));
    
    if(codeStatMonster == 14) {
      // * Initialization of a Monster
        M1->hp = 5;
        M1->hpMAX = 5;
        M1->attack = 2;
        M1->posX = 1;
        M1->posY = 2;
        M1->name = 12; 
        printf("This is a Gobelins ! \n");
    }
    else if(codeStatMonster == 15) {
      // * Initialization of a Monster
        M1->hp = 7;
        M1->hpMAX = 7;
        M1->attack = 3;
        M1->posX = 1;
        M1->posY = 2;
        M1->name = 12; 
        printf("This is an Orc ! \n");
    }
    
    printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
    while(J1->hp > 0 && M1->hp > 0){
        printf("   -     Action :     - ");
        printf("\n");
        printf("   -     Attack (1)   - ");
        printf("\n");
        printf("   -     Heal (2)     - ");
        printf("\n");
        scanf("%d", &actionCombat);
        if(actionCombat > 2 || actionCombat < 1) {
            printf("Choix invalide, réessayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                // J1->experience = J1->experience + 5;
                leveling(20,J1);
                if(J1->hp == 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[(J1->posY)+1][J1->posX] = 0;
                }
            }
        }
        else if(actionCombat == 2) {
            printf("Vous avez décidé de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}

void fightNorth(joueur *J1,int ** mat, int codeStatMonster) {
    int actionCombat;
    monster *M1 = malloc(sizeof(monster));
    
    if(codeStatMonster == 14) {
      // * Initialization of a Monster
        printf("This is a Gobelins ! \n");
    }
    else if(codeStatMonster == 15) {
      // * Initialization of a Monster
        M1->hp = 7;
        M1->hpMAX = 7;
        M1->attack = 3;
        M1->posX = 1;
        M1->posY = 2;
        M1->name = 12; 
        printf("This is an Orc ! \n");
    }
    // * Initialization of a Monster
    // monster *M1 = malloc(sizeof(monster));
    // M1->hp = 5;
    // M1->hpMAX = 5;
    // M1->attack = 2;
    // M1->posX = 1;
    // M1->posY = 2;
    // M1->name = 12;

    printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
    while(J1->hp > 0 && M1->hp > 0){
        printf("   -     Action :     - ");
        printf("\n");
        printf("   -     Attack (1)   - ");
        printf("\n");
        printf("   -     Heal (2)     - ");
        printf("\n");
        scanf("%d", &actionCombat);
        if(actionCombat > 2 || actionCombat < 1) {
            printf("Choix invalide, réessayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                leveling(20,J1);
                if(J1->hp == 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[(J1->posY)-1][J1->posX] = 0;
                }
            }
        }
        else if(actionCombat == 2) {
            printf("Vous avez décidé de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}

void fightEast(joueur *J1,int ** mat) {
    int actionCombat;
    // * Initialization of a Monster
    monster *M1 = malloc(sizeof(monster));
    M1->hp = 5;
    M1->hpMAX = 5;
    M1->attack = 2;
    M1->posX = 1;
    M1->posY = 2;
    M1->name = 12;

    printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
    while(J1->hp > 0 && M1->hp > 0){
        printf("   -     Action :     - ");
        printf("\n");
        printf("   -     Attack (1)   - ");
        printf("\n");
        printf("   -     Heal (2)     - ");
        printf("\n");
        scanf("%d", &actionCombat);
        if(actionCombat > 2 || actionCombat < 1) {
            printf("Choix invalide, réessayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                leveling(20,J1);
                if(J1->hp == 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[J1->posY][(J1->posX)+1] = 0;
                }
            }
        }
        else if(actionCombat == 2) {
            printf("Vous avez décidé de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}

void fightWest(joueur *J1,int ** mat) {
    int actionCombat;
    // * Initialization of a Monster
    monster *M1 = malloc(sizeof(monster));
    M1->hp = 5;
    M1->hpMAX = 5;
    M1->attack = 2;
    M1->posX = 1;
    M1->posY = 2;
    M1->name = 12;

    printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
    while(J1->hp > 0 && M1->hp > 0){
        printf("   -     Action :     - ");
        printf("\n");
        printf("   -     Attack (1)   - ");
        printf("\n");
        printf("   -     Heal (2)     - ");
        printf("\n");
        scanf("%d", &actionCombat);
        if(actionCombat > 2 || actionCombat < 1) {
            printf("Choix invalide, réessayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                leveling(20,J1);
                if(J1->hp == 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[J1->posY][(J1->posX)-1] = 0;
                }
            }
        }
        else if(actionCombat == 2) {
            printf("Vous avez décidé de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}

void movement();
void actionCaseUsed(joueur *J1,int ** mat, char dir) {
    int actionChoised;

    printf("   -     Action :     - ");
    printf("\n");
    printf("   -     Fight (1)    - ");
    printf("\n");
    printf("   -     Leave (2)    - ");
    printf("\n");
    
    scanf("%d", &actionChoised);
    if(actionChoised > 2 || actionChoised < 1) {
        printf("Choix invalide, réessayer !");
        printf("\n");
        scanf("%d", &actionChoised);
    }
    else if(actionChoised == 1 && dir == 's') {
        int codeStatMonster = mat[(J1->posY)+1][J1->posX];
        fightSouth(J1,mat,codeStatMonster);
    }
    else if(actionChoised == 1 && dir == 'n') {
        int codeStatMonster = mat[(J1->posY)-1][J1->posX];
        fightNorth(J1,mat,codeStatMonster);
    }
    else if(actionChoised == 1 && dir == 'e') {
        fightEast(J1,mat);
    }
    else if(actionChoised == 1 && dir == 'w') {
        fightWest(J1,mat);
    }
    else if(actionChoised == 2) {
        printf("Vous avez décidé de fuir, comme c'est pitoyable.\n");
        printf("In which direction would you move?\n");
        movement(J1,mat);
    }
}

void teleportationZone(joueur *J1, int ** mat) {
    mat[J1->posY][J1->posX] = 0;
    if(mat[(J1->posY)+1][J1->posX] == -2 || mat[(J1->posY)+1][J1->posX] == -3)
        J1->posY = (J1->posY)+3;
    else if(mat[J1->posY][(J1->posX)-1] == -2 || mat[J1->posY][(J1->posX)-1] == -3)
        J1->posY = (J1->posY)+2;
    J1->posX = 0;
    mat[J1->posY][J1->posX] = J1->name;
}


void fall(joueur *J1, int **mat) {
    char fly;
    printf("Would you go further? (y or n)\n");
    // scanf("%c", &fly);
    do {
        scanf("%c", &fly);
    } while(fly != 'y' && fly!= 'n');
    if(fly == 'y') {
        printf("\n");
        printf("Vous réalisé ce pas de plus, et vous vous rendez compte qu'aucun pouvoir ne vous ai attribué,\nle seul chemin qui vous attend est celuis qui vous guidera vers l'éternelle profondeur des abysses.\n");
        printf("\n");
        printf("You are dead...");
        J1->hp = 0;
    }
    else if(fly == 'n')  {
        printf("Good choise, continue your adventure, Wizard.\n");
        printf("In which direction would you move?\n");
        movement(J1,mat);
    }
}

void northMov(joueur *J1, int** mat, int row) {
    if((J1->posY) == 0) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        fall(J1,mat);
    }
    else if(mat[(J1->posY)-1][J1->posX] == -1) {
        printf("You can't pass througth a wall, Wizard ! \n");
        movement(J1,mat,row);
    }
    else {
        if(mat[(J1->posY)-1][J1->posX] >= 10 && mat[(J1->posY)-1][J1->posX] <= 20){
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1,mat,'n');
        }
        else if(mat[(J1->posY)-1][J1->posX] >= 100 && mat[(J1->posY)-1][J1->posX] <= 110){
            printf("There is a ressource up there ! \n");
        }
        else if(mat[(J1->posY)-1][J1->posX] == 2){
            printf("There is a NPC up there ! \n");
        }
        else {
            J1->posY = J1->posY - 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[(J1->posY)+1][J1->posX] = 0;
        
        }
    }
}

void southMov(joueur *J1, int** mat, int row) {
    if(((J1->posY)+1 == (row*3)+2)) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        // movement(J1,mat,row);
        fall(J1,mat);
    }
    else if(mat[(J1->posY)+1][J1->posX] == -1) {
        printf("You can't pass througth a wall, Wizard ! \n");
        movement(J1,mat,row);
        // fall(J1);
    }
    else {
        if(mat[(J1->posY)+1][J1->posX] >= 10 && mat[(J1->posY)+1][J1->posX] <= 20){
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1,mat,'s');
        }
        else if(mat[(J1->posY)+1][J1->posX] >= 100 && mat[(J1->posY)+1][J1->posX] <= 110){
            printf("There is a ressource up there ! \n");
        }
        else if(mat[(J1->posY)+1][J1->posX] == 2){
            printf("There is a NPC up there ! \n");
        }
        else if(mat[(J1->posY)+1][J1->posX] == -2) {
            if(J1->niveau < 3) {
                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 3 !\n");
            }
            else {
                printf("Téléportation vers la zone 2 !\n");
                teleportationZone(J1, mat);
            }
        }
        else if(mat[(J1->posY)+1][J1->posX] == -3) {
            if(J1->niveau < 6) {
                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 6 !\n");
            }
            else {
                printf("Téléportation vers la zone 3 !\n");
                teleportationZone(J1, mat);
            }
        }
        else {
            J1->posY += 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[(J1->posY)-1][J1->posX] = 0;   
        }
    }
}

void eastMov(joueur *J1, int** mat, int row) {
    if((J1->posX) == row-1) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        // movement(J1,mat,row);
        fall(J1,mat);
    }
    else  {
        if(mat[J1->posY][(J1->posX)+1] >= 10 && mat[J1->posY][(J1->posX)+1] <= 20){
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1,mat,'e');
        }
        else if(mat[J1->posY][(J1->posX)+1] >= 100 && mat[J1->posY][(J1->posX)+1] <= 110){
            printf("There is a ressource up there ! \n");
        }
        else if(mat[J1->posY][(J1->posX)+1] == 2){
            printf("There is a NPC up there ! \n");
        }
        else {
            J1->posX += 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[J1->posY][(J1->posX)-1] = 0;   
        }
    }
}

void westMov(joueur *J1, int** mat, int row) {
    if((J1->posX) == 0) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        // movement(J1,mat,row);
        fall(J1,mat);
    }
    else {
        if(mat[J1->posY][(J1->posX)-1] >= 10 && mat[J1->posY][(J1->posX)-1] <= 20){
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1,mat,'w');
        }
        else if(mat[J1->posY][(J1->posX)-1] >= 100 && mat[J1->posY][(J1->posX)-1] <= 110){
            printf("There is a ressource up there ! \n");
        }
        else if(mat[J1->posY][(J1->posX)-1] == 2){
            printf("There is a NPC up there ! \n");
        }
        else if(mat[J1->posY][(J1->posX)-1] == -2) {
            if(J1->niveau < 3) {
                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 3 !\n");
            }
            else {
                printf("Téléportation vers la zone 2 !\n");
                teleportationZone(J1, mat);
            }
        }
        else if(mat[J1->posY][(J1->posX)-1] == -3) {
            if(J1->niveau < 6) {
                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 6 !\n");
            }
            else {
                printf("Téléportation vers la zone 3 !\n");
                teleportationZone(J1, mat);
            }
        }
        else if(mat[J1->posY][(J1->posX)-1] == 0){
            J1->posX = J1->posX - 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[J1->posY][(J1->posX)+1] = 0; 
        }
    }
}

void movement(joueur *J1, int** mat, int row) {
    char movChoise;
    do {
        scanf("%c", &movChoise);
    }while(movChoise != 'n' && movChoise != 's' && movChoise != 'e' &&  movChoise != 'w');
    
    if(movChoise == 'n') {
        northMov(J1,mat,row);
    }
    else if(movChoise == 's') {
        southMov(J1,mat,row);
    }
    else if(movChoise == 'e') {
        eastMov(J1,mat,row);
    }
    else if(movChoise == 'w') {
        westMov(J1,mat,row);
    }
    else if(movChoise == 'n' && J1->posY == 0) {
        fall(J1,mat);
    }
    else if(movChoise == 's' && J1->posY == ((row*3)+1)) {
        fall(J1,mat);
    }
    else if(movChoise == 'e' && J1->posX == row) {
        fall(J1,mat);
    }
    else if(movChoise == 'w' && J1->posX == 0) {
        fall(J1,mat);
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
    joueur *J1 = malloc(sizeof(joueur));
    J1->experience = 0;
    J1->hp = 10;
    J1->hpMAX = 10;
    J1->attack = 3;
    J1->niveau = 1;
    J1->posX = 0;
    J1->posY = 0;
    J1->name = 1;
    


    
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
