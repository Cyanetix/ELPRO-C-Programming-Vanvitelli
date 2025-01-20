/*
Matrice dinamica (array di array)
Obiettivo: Allocare una matrice 3x3, riempirla con valori crescenti (1-9) e stamparla.
"	Suggerimento: Usa un doppio puntatore (int **matrix).
"	Bonus: Scrivi una funzione per deallocare la matrice.
*/
#include <stdio.h>
#include <stdlib.h>
void printMat(int **mat,int rows,int cols){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	//alloco matrice 3*3
	int rows=3,cols=3;
	int **matrix = malloc(rows*sizeof(int*));//alloco prima un array di puntatori a intero pari al numero di righe
	if(matrix==NULL){
		perror("Errore allocazione matrice");	 
		return -1;
	}
	
	for(int i=0;i<rows;i++){
		//alloco per ciascun puntatore un array di interi
		matrix[i]=malloc(cols*sizeof(int));
		if(matrix[i]==NULL){
			perror("Errore allocazione array di interi");
			//in caso di errore dealloco tutto lo spazio allocato fino ad ora
			for(int j=0;j<i;j++){
				free(matrix[j]);
			}
			free(matrix);//dealloco array di puntatori
			return -1;
		}
	}
	
	//riempo con valori crescenti
	int n=1;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			matrix[i][j]=n;
			n++;
		}
	}
	
	//stampo matrice
	printMat(matrix,rows,cols);
	
	//deallocare matrice
	//dealloco ogni riga
	for(int i=0;i<rows;i++){
		free(matrix[i]);
	}
	//dealloco array di puntatori
	free(matrix);
	return 0;
}
