/*
Stampa della diagonale principale di una matrice
o Obiettivo: Stampare gli elementi della diagonale principale di una matrice.
o Compiti:
? Leggere le dimensioni della matrice e i suoi elementi da input.
? Stampare gli elementi della diagonale principale.
*/
#include <stdio.h>
#include <string.h>
#define NMAX 100
void readMat(int m[][NMAX],int r);
void printMat(int m[][NMAX],int r);
void printMatDiagonal(int m[][NMAX],int r);
void printMatAntiDiagonal(int m[][NMAX],int r);
int main(){
	int mat[NMAX][NMAX];
	int r;//righe e colonne (ora uguali per matrice quadrata)
	memset(mat,0,sizeof(mat));

	//acquisizione dimensione matrice quadrata
	do{
		printf("Inserisci la dimensione della matrice quadrata (righe e colonne, > 0 e < %d):\n",NMAX);
		scanf("%d",&r);
		if(r<=0 || r>=NMAX){
			printf("Hai inserito una dimensione errata\n");
		}
		printf("\n");
	}while(r<=0 || r>=NMAX);


	//lettura matrice
	printf("Inserisci gli elementi della matrice:\n");
	readMat(mat,r);

	//stampa matrice
	printf("\nMatrice completa:\n");
	printMat(mat,r);

	//stampa diagonale principale matrice
	printf("\nDiagonale principale:\n");
	printMatDiagonal(mat,r);

	//stampa diagonale secondaria matrice
	printf("\nDiagonale secondaria:\n");
	printMatAntiDiagonal(mat,r);


	return 0;
}

//modifica readMat e printMat per accettare solo 'r' come dimensione (matrice quadrata)
void readMat(int m[][NMAX],int r){
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){ //ora j va fino a r per matrice quadrata
			printf("matrix [%d][%d]: ",i,j);
			scanf("%d",&m[i][j]); //correzione: aggiunta & per indirizzo di memoria
		}
		printf("\n");
	}
}

void printMat(int m[][NMAX],int r){
	for(int i=0;i<r;i++){
		for(int j=0;j<r;j++){ //ora j va fino a r per matrice quadrata
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
}

void printMatDiagonal(int m[][NMAX],int r){
	for(int i=0;i<r;i++){
		for(int k=0;k<i;k++){
			printf("\t");
		}
		printf("%d\n",m[i][i]);
	}
	printf("\n");
}

void printMatAntiDiagonal(int m[][NMAX],int r){
	for(int i=0;i<r;i++){
		for(int k=0;k<r-1-i;k++){
			printf("\t");
		}
		printf("%d\n",m[i][r-1-i]);
	}
	printf("\n");
}

/*
Matrice esempio:

   1   2   3   4
   5   6   7   8
   9  10  11  12
  13  14  15  16
*/

/*
Antidiagonale esempio:

  			  4
		  7
	  10
  13
   
*/



/*
Diagonale:

1
	6
		11	
			16
*/
