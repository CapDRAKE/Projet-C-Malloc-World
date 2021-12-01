#include "lib_joueur.h"

// ? Initialization of a player
joueur* initPlayer() {
    joueur* J1 = malloc(sizeof(joueur));
    J1->experience = 0;
    J1->hp = 10;
    J1->hpMAX = 10;
    J1->attack = 3;
    J1->niveau = 1;
    J1->posX = 0;
    J1->posY = 0;
    J1->name = 1;
    J1->inventory = initInventory();
    return J1;
}

// ? Creation of the leveling and experience system
void leveling(int xp, joueur* J1) {
    // * Player level 1 to 2
    J1->experience = J1->experience + xp;
    if (J1->experience >= 40 && J1->niveau == 1) {//passage niv 2 +10hp
        J1->niveau = 2;
        J1->hpMAX += 10;
        J1->hp = J1->hpMAX;
    }
    // * Player level 2 to 3
    else if (J1->experience >= 80 && J1->niveau == 2) {//passage niv 3
        J1->niveau = 3;
        J1->hpMAX += 20;
        J1->hp = J1->hpMAX;
    }
    // * Player level 3 to 4
    else if (J1->experience >= 100 && J1->niveau == 3) {//passage niv 4
        J1->niveau = 4;
        J1->hpMAX += 30;
        J1->hp = J1->hpMAX;
    }
    // * Player level 4 to 5
    else if (J1->experience >= 150 && J1->niveau == 4) {//passage niv 5
        J1->niveau = 5;
        J1->hpMAX += 40;
        J1->hp = J1->hpMAX;
    }
    // * Player level 5 to 8
    else if ((J1->experience >= 200 && J1->niveau == 5) || (J1->experience >= 250 && J1->niveau == 6) || (J1->experience >= 300 && J1->niveau == 7)) {//passage niv 6,7,8
        J1->niveau += 1;
        J1->hpMAX += 50;
        J1->hp = J1->hpMAX;
    }
    // * Player level 8 to 10
    else if ((J1->experience >= 350 && J1->niveau == 8) || (J1->experience >= 400 && J1->niveau == 9)) {//passage niv 9,10
        J1->niveau += 1;
        J1->hpMAX += 75;
        J1->hp = J1->hpMAX;
    }
}

// ? Player teleportation - Zone 2 and 3 
void teleportationZone(joueur* J1, int** mat) {
    mat[J1->posY][J1->posX] = 0;
    // * Set position player to Y + 3 to jump behind the wall, or +2 if he trigger the portal at the right
    if (mat[(J1->posY) + 1][J1->posX] == -2 || mat[(J1->posY) + 1][J1->posX] == -3)
        J1->posY = (J1->posY) + 3;
    else if (mat[J1->posY][(J1->posX) - 1] == -2 || mat[J1->posY][(J1->posX) - 1] == -3)
        J1->posY = (J1->posY) + 2;
    J1->posX = 0;
    mat[J1->posY][J1->posX] = J1->name;
}


// ? Player Fighting Monster at South
void fightSouth(joueur *J1,int ** mat, int codeStatMonster) {
    int actionCombat;
    monster *M1 = malloc(sizeof(monster));
    // * After creating a monster - attribute his stats with an ID
    if(codeStatMonster == 14) {
        generateMonsterZone1Stat(M1, 14);
        printf("This is a Gobelins ! \n");
    }
    else if(codeStatMonster == 15) {
        generateMonsterZone1Stat(M1, 15);
        printf("This is an Orc ! \n");
    }
    else if(codeStatMonster == 16) {
        generateMonsterZone2Stat(M1, 16);
        printf("This is a Troll ! \n");
    }
    else if(codeStatMonster == 17) {
        generateMonsterZone2Stat(M1, 16); 
        printf("This is a Wapiti ! \n");
    }
    else if(codeStatMonster == 18) {
        generateMonsterZone3Stat(M1, 18); 
        printf("This is a Noe le Sbire ! \n");
    }
    else if(codeStatMonster == 19) {
        generateMonsterZone3Stat(M1, 19); 
        printf("This is a Nathanael Le Devoreur d'enfant ! \n");
    }
    // * Creation of a fighting windows
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
            printf("Choix invalide, rÃ©essayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        // * Fighting with the monster - one action per round
        // ! Not fonctional with item
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                if(J1->hp <= 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[(J1->posY)+1][J1->posX] = 0;
                    leveling(20,J1);
                }
            }
        }
        // * Healing section
        // ! Not fonctional with item
        else if(actionCombat == 2) {
            printf("Vous avez dÃ©cidÃ© de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}

// ? Player Fighting Monster at North
void fightNorth(joueur *J1,int ** mat, int codeStatMonster) {
    int actionCombat;
    monster *M1 = malloc(sizeof(monster));
    // * After creating a monster - attribute his stats with an ID
    if(codeStatMonster == 14) {
        generateMonsterZone1Stat(M1, 14);
        printf("This is a Gobelins ! \n");
    }
    else if(codeStatMonster == 15) {
        generateMonsterZone1Stat(M1, 15);
        printf("This is an Orc ! \n");
    }
    else if(codeStatMonster == 16) {
        generateMonsterZone2Stat(M1, 16);
        printf("This is a Troll ! \n");
    }
    else if(codeStatMonster == 17) {
        generateMonsterZone2Stat(M1, 16); 
        printf("This is a Wapiti ! \n");
    }
    else if(codeStatMonster == 18) {
        generateMonsterZone3Stat(M1, 18); 
        printf("This is a Noe le Sbire ! \n");
    }
    else if(codeStatMonster == 19) {
        generateMonsterZone3Stat(M1, 19); 
        printf("This is a Nathanael Le Devoreur d'enfant ! \n");
    }
    // * Fighting with the monster - one action per round
    // ! Not fonctional with item
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
            printf("Choix invalide, rÃ©essayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                // leveling(20,J1);
                if(J1->hp == 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[(J1->posY)-1][J1->posX] = 0;
                    leveling(20,J1);
                }
            }
        }
        // * Healing section
        // ! Not fonctional with item
        else if(actionCombat == 2) {
            printf("Vous avez dÃ©cidÃ© de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}

// ? Player Fighting Monster at East
void fightEast(joueur *J1,int ** mat, int codeStatMonster) {
    int actionCombat;
    monster *M1 = malloc(sizeof(monster));
    // * After creating a monster - attribute his stats with an ID
    if(codeStatMonster == 14) {
        generateMonsterZone1Stat(M1, 14);
        printf("This is a Gobelins ! \n");
    }
    else if(codeStatMonster == 15) {
        generateMonsterZone1Stat(M1, 15);
        printf("This is an Orc ! \n");
    }
    else if(codeStatMonster == 16) {
        generateMonsterZone2Stat(M1, 16);
        printf("This is a Troll ! \n");
    }
    else if(codeStatMonster == 17) {
        generateMonsterZone2Stat(M1, 16); 
        printf("This is a Wapiti ! \n");
    }
    else if(codeStatMonster == 18) {
        generateMonsterZone3Stat(M1, 18); 
        printf("This is a Noe le Sbire ! \n");
    }
    else if(codeStatMonster == 19) {
        generateMonsterZone3Stat(M1, 19); 
        printf("This is a Nathanael Le Devoreur d'enfant ! \n");
    }
    // * Fighting with the monster - one action per round
    // ! Not fonctional with item
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
            printf("Choix invalide, rÃ©essayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                // leveling(20,J1);
                if(J1->hp == 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[J1->posY][(J1->posX)+1] = 0;
                    leveling(20,J1);
                }
            }
        }
        // * Healing section
        // ! Not fonctional with item
        else if(actionCombat == 2) {
            printf("Vous avez dÃ©cidÃ© de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}

// ? Player Fighting Monster at West
void fightWest(joueur *J1,int ** mat, int codeStatMonster) {
    int actionCombat;
    monster *M1 = malloc(sizeof(monster));
    // * After creating a monster - attribute his stats with an ID
    if(codeStatMonster == 14) {
        generateMonsterZone1Stat(M1, 14);
        printf("This is a Gobelins ! \n");
    }
    else if(codeStatMonster == 15) {
        generateMonsterZone1Stat(M1, 15);
        printf("This is an Orc ! \n");
    }
    else if(codeStatMonster == 16) {
        generateMonsterZone2Stat(M1, 16);
        printf("This is a Troll ! \n");
    }
    else if(codeStatMonster == 17) {
        generateMonsterZone2Stat(M1, 16); 
        printf("This is a Wapiti ! \n");
    }
    else if(codeStatMonster == 18) {
        generateMonsterZone3Stat(M1, 18); 
        printf("This is a Noe le Sbire ! \n");
    }
    else if(codeStatMonster == 19) {
        generateMonsterZone3Stat(M1, 19); 
        printf("This is a Nathanael Le Devoreur d'enfant ! \n");
    }
    // * Fighting with the monster - one action per round
    // ! Not fonctional with item
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
            printf("Choix invalide, rÃ©essayer !");
            printf("\n");
            scanf("%d", &actionCombat);
        }
        else if(actionCombat == 1) {
            if(J1->hp > 0 && M1->hp > 0){
                M1->hp = (M1->hp)-(J1->attack);
                J1->hp = (J1->hp)-(M1->attack);
                printf("You have %d HP, The monster have %d \n", J1->hp, M1->hp);
                // leveling(20,J1);
                if(J1->hp == 0) {
                    printf("You are dead. \n");
                }
                else if(M1->hp <= 0) {
                    printf("You defeat the monster ! \n");
                    mat[J1->posY][(J1->posX)-1] = 0;
                    leveling(20,J1);
                }
            }
        }
        // * Healing section
        // ! Not fonctional with item
        else if(actionCombat == 2) {
            printf("Vous avez dÃ©cidÃ© de vous heal ! \n");
            J1->hp = J1->hp + 5;
            printf("Vous regagnez 5 PV ! \n");
        }
    }
    free(M1);
}


// ? Oracle looking for the direction to validate the deplacement
void actionCaseUsed(joueur* J1, int** mat, char dir, int row) {

    int actionChoised;
    // * Menu to show when the future position is already used by a monster
    printf("   -     Action :     - ");
    printf("\n");
    printf("   -     Fight (1)    - ");
    printf("\n");
    printf("   -     Leave (2)    - ");
    printf("\n");
    // * Waiting the player action
    scanf("%d", &actionChoised);
    if(actionChoised > 2 || actionChoised < 1) {
        printf("Choix invalide, rÃ©essayer !");
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
        int codeStatMonster = mat[J1->posY][(J1->posX)+1];
        fightEast(J1,mat,codeStatMonster);
    }
    else if(actionChoised == 1 && dir == 'w') {
        int codeStatMonster = mat[J1->posY][(J1->posX)-1];
        fightWest(J1,mat,codeStatMonster);
    }
    // * Leave a fight
    // ! Not fonctional with %
    else if(actionChoised == 2) {
        printf("Vous avez dÃ©cidÃ© de fuir, comme c'est pitoyable.\n");
        printf("In which direction would you move?\n");
        movement(J1,mat,row);
    }
}

// ? Oracle detect a used cases - Ressources
void actionCaseUsedRessources(joueur *J1,int ** mat, char dir, int row) {
    int actionChoised;
    // * Menu to show when the future position is already used  by a ressources
    printf("   -     Action :     - ");
    printf("\n");
    printf("   -     Harvest (1)  - ");
    printf("\n");
    printf("   -     Leave (2)    - ");
    printf("\n");
    // * Waiting the player action
    scanf("%d", &actionChoised);
    if(actionChoised > 2 || actionChoised < 1) {
        printf("Choix invalide, réessayer !");
        printf("\n");
        scanf("%d", &actionChoised);
    }
    else if(actionChoised == 1 && dir == 's') {
        int codeStatRessources = mat[(J1->posY)+1][J1->posX];
        // harvestSouth(J1,mat,codeStatRessources);
    }
    else if(actionChoised == 1 && dir == 'n') {
        int codeStatRessources = mat[(J1->posY)-1][J1->posX];
        // harvestNorth(J1,mat,codeStatRessources);
    }
    else if(actionChoised == 1 && dir == 'e') {
        int codeStatRessources = mat[J1->posY][(J1->posX)+1];
        // harvestEast(J1,mat,codeStatRessources);
    }
    else if(actionChoised == 1 && dir == 'w') {
        int codeStatRessources = mat[J1->posY][(J1->posX)-1];
        // harvestWest(J1,mat,codeStatRessources);
    }
    // * Leave a detection of ressources
    else if(actionChoised == 2) {
        printf("It’s a shame, a beautiful treasure was there.\n");
        printf("In which direction would you move?\n");
        movement(J1,mat,row);
    }
}

// ? Oracle detect a deplacement out of the map
void fall(joueur* J1, int** mat, int row) {
    char fly;
    printf("Would you go further? (y or n)\n");
    // scanf("%c", &fly);
    do {
        scanf("%c", &fly);
    } while (fly != 'y' && fly != 'n');
    // * Player dying from falling out of the map
    if (fly == 'y') {
        printf("\n");
      
        printf("Vous rï¿½alisï¿½ ce pas de plus, et vous vous rendez compte qu'aucun pouvoir ne vous ai attribuï¿½,\nle seul chemin qui vous attend est celuis qui vous guidera vers l'ï¿½ternelle profondeur des abysses.\n");

        printf("\n");
        printf("You are dead...");
        J1->hp = 0;
    }
    // * Player continue to play
    else if (fly == 'n') {
        printf("Good choise, continue your adventure, Wizard.\n");
        printf("In which direction would you move?\n");
        movement(J1, mat, row);
    }
}

// ? Deplacement Player 1 on the grid - North
void northMov(joueur* J1, int** mat, int row) {
    if ((J1->posY) == 0) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        fall(J1, mat, row);
    }
    // * Player can't pass a wall
    else if (mat[(J1->posY) - 1][J1->posX] == -1) {
        printf("You can't pass througth a wall, Wizard ! \n");
        movement(J1, mat, row);
    }
    else {
        // * Detection of a monster
        if (mat[(J1->posY) - 1][J1->posX] >= 10 && mat[(J1->posY) - 1][J1->posX] <= 20) {
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1, mat, 'n', row);
        }
        // * Detection of a Ressources
        else if (mat[(J1->posY) - 1][J1->posX] >= 100 && mat[(J1->posY) - 1][J1->posX] <= 110) {
            printf("There is a ressource up there ! \n");
        }
        // * Detection of an NPC
        else if (mat[(J1->posY) - 1][J1->posX] == 2) {
            printf("There is a NPC up there ! \n");
        }
        // * Deplacement Valid
        else {
            J1->posY = J1->posY - 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[(J1->posY) + 1][J1->posX] = 0;

        }
    }
}

// ? Deplacement Player 1 on the grid - South
void southMov(joueur* J1, int** mat, int row) {
    if (((J1->posY) + 1 == (row * 3) + 2)) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        // movement(J1,mat,row);
        fall(J1, mat, row);
    }
    // * Player can't pass a wall
    else if (mat[(J1->posY) + 1][J1->posX] == -1) {
        printf("You can't pass througth a wall, Wizard ! \n");
        movement(J1, mat, row);
        // fall(J1);
    }
    else {
        // * Detection of a monster
        if (mat[(J1->posY) + 1][J1->posX] >= 10 && mat[(J1->posY) + 1][J1->posX] <= 20) {
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1, mat, 's', row);
        }
        // * Detection of a Ressources
        else if (mat[(J1->posY) + 1][J1->posX] >= 100 && mat[(J1->posY) + 1][J1->posX] <= 110) {
            printf("There is a ressource up there ! \n");
        }
        // * Detection of an NPC
        else if (mat[(J1->posY) + 1][J1->posX] == 2) {
            printf("There is a NPC up there ! \n");
        }
        // * Detection of a Portal
        else if (mat[(J1->posY) + 1][J1->posX] == -2) {
            if (J1->niveau < 3) {

                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 3 !\n");
            }
            else {
                printf("Téléportation vers la zone 2 !\n");
                teleportationZone(J1, mat);
            }
        }
        else if (mat[(J1->posY) + 1][J1->posX] == -3) {
            if (J1->niveau < 6) {
                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 6 !\n");
            }
            else {
                printf("Téléportation vers la zone 3 !\n");
                teleportationZone(J1, mat);
            }
        }
        // * Deplacement Valid
        else {
            J1->posY += 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[(J1->posY) - 1][J1->posX] = 0;
        }
    }
}

// ? Deplacement Player 1 on the grid - East
void eastMov(joueur* J1, int** mat, int row) {
    if ((J1->posX) == row - 1) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        // movement(J1,mat,row);
        fall(J1, mat, row);
    }
    else {
        // * Detection of a monster
        if (mat[J1->posY][(J1->posX) + 1] >= 10 && mat[J1->posY][(J1->posX) + 1] <= 20) {
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1, mat, 'e', row);
        }
        // * Detection of a Ressources
        else if (mat[J1->posY][(J1->posX) + 1] >= 100 && mat[J1->posY][(J1->posX) + 1] <= 110) {
            printf("There is a ressource up there ! \n");
        }
        // * Detection of an NPC
        else if (mat[J1->posY][(J1->posX) + 1] == 2) {
            printf("There is a NPC up there ! \n");
        }
        // * Deplacement Valid
        else {
            J1->posX += 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[J1->posY][(J1->posX) - 1] = 0;
        }
    }
}

// ? Deplacement Player 1 on the grid - West
void westMov(joueur* J1, int** mat, int row) {
    if ((J1->posX) == 0) {
        printf("Would you learn to fly? One step more and you can do it.\n");
        // movement(J1,mat,row);
        fall(J1, mat, row);
    }
    else {
        // * Detection of a monster
        if (mat[J1->posY][(J1->posX) - 1] >= 10 && mat[J1->posY][(J1->posX) - 1] <= 20) {
            printf("There is a monster up there ! \n");
            actionCaseUsed(J1, mat, 'w', row);
        }
        // * Detection of a Ressources
        else if (mat[J1->posY][(J1->posX) - 1] >= 100 && mat[J1->posY][(J1->posX) - 1] <= 110) {
            printf("There is a ressource up there ! \n");
        }
        // * Detection of an NPC
        else if (mat[J1->posY][(J1->posX) - 1] == 2) {
            printf("There is a NPC up there ! \n");
        }
        // * Detection of a Portal
        else if (mat[J1->posY][(J1->posX) - 1] == -2) {
            if (J1->niveau < 3) {
                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 3 !\n");
            }
            else {
                printf("Téléportation vers la zone 2 !\n");
                teleportationZone(J1, mat);
            }
        }
        else if (mat[J1->posY][(J1->posX) - 1] == -3) {
            if (J1->niveau < 6) {
                printf("Ce portail est réservé au joueur tromphant d'un niveau supérieur à 6 !\n");
            }
            else {
                printf("Téléportation vers la zone 3 !\n");
                teleportationZone(J1, mat);
            }
        }
        // * Deplacement Valid
        else if (mat[J1->posY][(J1->posX) - 1] == 0) {
            J1->posX = J1->posX - 1;
            mat[J1->posY][J1->posX] = J1->name;
            mat[J1->posY][(J1->posX) + 1] = 0;
        }
    }
}

// ? Deplacement Player 1 when he trigger an error like Fall
void movement(joueur* J1, int** mat, int row) {
    char movChoise;
    do {
        scanf("%c", &movChoise);
    } while (movChoise != 'n' && movChoise != 's' && movChoise != 'e' && movChoise != 'w');

    if (movChoise == 'n') {
        northMov(J1, mat, row);
    }
    else if (movChoise == 's') {
        southMov(J1, mat, row);
    }
    else if (movChoise == 'e') {
        eastMov(J1, mat, row);
    }
    else if (movChoise == 'w') {
        westMov(J1, mat, row);
    }
    else if (movChoise == 'n' && J1->posY == 0) {
        fall(J1, mat, row);
    }
    else if (movChoise == 's' && J1->posY == ((row * 3) + 1)) {
        fall(J1, mat, row);
    }
    else if (movChoise == 'e' && J1->posX == row) {
        fall(J1, mat, row);
    }
    else if (movChoise == 'w' && J1->posX == 0) {
        fall(J1, mat, row);
    }
}
