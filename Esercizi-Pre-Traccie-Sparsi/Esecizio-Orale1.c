/*
Invertire tutte le righe di una matrice
Scrivi un sottoprogramma che, ricevuta in ingresso una matrice, inverta l’ordine degli elementi in ciascuna riga.


Invertire righe o colonne in base a un parametro
Realizza un sottoprogramma che, a seconda di un parametro (ad esempio, una lettera 'r' per righe o 'c' per colonne), inverta l’ordine delle righe oppure quello delle colonne di una matrice.
*/
#include <stdio.h>
#define NMAX 100
void swapElements(int* val1,int* val2){
	int temp = *val1;
	*val1 = *val2;
	*val2=temp;
}

// Funzione per invertire le righe
void reverseMatRows(int mat[][NMAX],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c/2;j++){
			swapElements(&mat[i][j],&mat[i][c-j-1]);
		}
	}
}

// Funzione per invertire le colonne
void reverseMatCols(int mat[][NMAX],int r,int c){
	for(int j=0;j<c;j++){
		for(int i=0;i<r/2;i++){
			swapElements(&mat[i][j],&mat[r-1-i][j]);
		}
	}
}

// Funzione principale per invertire righe o colonne
void reverseMatrix(int mat[][NMAX], int rows, int cols, char option) {
	if( option == 'c' || option == 'C' ){
		reverseMatCols(mat,rows,cols);
	}else if( option == 'r' || option == 'R'){
		reverseMatRows(mat,rows,cols);
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
	
	printf("Matrice originale:\n");
	printMat(mat,rows,cols);
	
	printf("Invertire righe (r) o colonne (c)? ");
	scanf("%c",&option);
	reverseMatrix(mat,rows,cols,option);
	
	printf("\nMatrice modificata:\n");
	printMat(mat,rows,cols);
	
	return 0;
}
