#include <stdio.h>
#include <stdlib.h>

//Structure du joueur
struct joueur {
    int niveau;
    float experience;
    int hp;
    int hpMAX;
    int inventaire[10][2];
    int** position;
};

//Déclaration de notre structure joueur
typedef struct joueur joueur;

void attack(){
    
}

void droite(int **mat) {

}

int main() {
    int **mat, row, col, i, j, n;

    printf("Welcome to Malloc World !");
    printf("\n");

    //printf("How many rows you want to create?");
    printf("Choose a size for your game grid :");
    printf("\n");
    scanf("%d", &row);
    mat = (int **)malloc(row*sizeof(int *));

    //printf("How many column you want to create?");
    //scanf("%d", &col);

    col = row;

    for(i=0;i<row;i++) {
        mat[i]=(int *)malloc(col*sizeof(int));
    }

    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if (i == 0)
            {
                mat[i][j] = 1;
            }
            else if (i == row-1){
                mat[i][j] = 1;
            }
            else if (j == 0){
                mat[i][j] = 1;
            }
            else if (j == col-1){
                mat[i][j] = 1;
            }
            else if (j == 1 && i == 1){
                mat[i][j] = 3;
            }
            else {
                n = rand()%10 + 4;
                mat[i][j] = n;
            }
        }
    }

    for(i=0;i<row;i++) {
        for(j=0;j<row;j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}