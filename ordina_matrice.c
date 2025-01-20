#include <stdio.h>
#define N 20
void leggi_matrice(int m[][N], int dim);
void stampa_matrice(int m[][N], int dim);
void ordina_matrice();

int main(){
	int mat[N][N];
	int array[N*N];
	int dim;
	printf("Inserisci la dimensione della matrice quadrata:\n");
	scanf("%d",&dim);
	leggi_matrice(mat,dim);
	printf("\nMatrice fornita:");
	stampa_matrice(mat,dim);
	printf("\nMatrice ordinata:");
	ordina_matrice(mat,dim,array);
	stampa_matrice(mat,dim);
return 0;
}
//lettura matrice
void leggi_matrice(int m[][N], int dim){
	int i,j;
	for(i=0; i < dim; i++){
		for(j=0;j < dim;j++){
			printf("Inserisci l'elemento %d %d:\n",i,j);
			scanf("%d",&m[i][j]);
		}
	}	
}

//stampa matrice
void stampa_matrice(int m[][N], int dim){
	int i,j;
	printf("\n");
	for(i=0; i < dim; i++){
		for(j=0;j < dim;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}	
}

//matrice in array
void matriceToArray(int m[][N], int dim, int array[]){
	int i,j;
	int index = 0;
	for(i=0;i<dim;i++){ ,, 
		for(j=0;j<dim;j++){
			array[index] = m[i][j];
			index++;
		}
	}
}

void arrayToMatrice(int m[][N], int dim, int array[]){
	int i,j;
	int index = 0;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			m[i][j] = array[index];
			index++;
		}
	}
} 


