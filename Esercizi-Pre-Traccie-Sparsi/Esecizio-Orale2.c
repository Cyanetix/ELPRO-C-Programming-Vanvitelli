/*
  Invertire due righe o due colonne specifiche
    Crea un sottoprogramma che, dati due indici (ad esempio 2 e 4) e un flag (es. 'r' per righe o 'c' per colonne), scambi la posizione delle due righe o delle due colonne specificate.
*/
#include <stdio.h>
#define NMAX 100

void swapElements(int* val1, int* val2){
	int temp = *val1;
	*val1=*val2;
	*val2=temp;
}

void swapRows(int mat[][NMAX],int c,int row1,int row2){
	if (row1 < 0 || row1 >= NMAX || row2 < 0 || row2 >= NMAX) {
        printf("Indici non validi per le righe.\n");
        return;
    }

	for(int j=0;j<c;j++){
		swapElements(&mat[row1][j],&mat[row2][j]);
	}
}

void swapCols(int mat[][NMAX],int r,int col1,int col2){
	if (col1 < 0 || col1 >= NMAX || col2 < 0 || col2 >= NMAX) {
        printf("Indici non validi per le colonne.\n");
        return;
    }

	for(int i=0;i<r;i++){
		swapElements(&mat[i][col1],&mat[i][col2]);
	}
}

void swapRowsOrColumns(int mat[][NMAX],int r,int c,int pos1,int pos2,char flag){
	if(flag=='r' || flag=='R'){
		swapRows(mat,c,pos1,pos2);
	}else if(flag=='c' || flag=='C'){
		swapCols(mat,r,pos1,pos2);
	}else{
		printf("Opzione non valida. Inserire 'r' per righe o 'c' per colonne.\n");
	}
}

void printMat(int mat[][NMAX],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int mat[NMAX][NMAX]={
	{5,9,2,4},
	{3,4,6,1},
	{5,6,4,0}
	};
	int rows=3;
	int cols=4;
	char option;
	int indice1,indice2;
	
	printf("Matrice originale:\n");
	printMat(mat,rows,cols);
	
	printf("Invertire righe (r) o colonne (c)? ");
	scanf("%c",&option);
	printf("Inserisce primo indice:");
	scanf("%d",&indice1);
	
	printf("\nInserisce secondo indice:");
	scanf("%d",&indice2);
	
	printf("\nMatrice modificata:\n");
	swapRowsOrColumns(mat,rows,cols,indice1,indice2,option);
	printMat(mat,rows,cols);
	
	return 0;
}
