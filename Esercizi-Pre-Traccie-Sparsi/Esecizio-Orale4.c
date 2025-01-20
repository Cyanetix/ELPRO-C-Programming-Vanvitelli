/*
    Eliminare colonne costituite solo da zeri in una matrice
    Realizza un sottoprogramma che, data una matrice, rimuova tutte le colonne i cui elementi sono tutti uguali a zero.
*/
#include <stdio.h>
#include <stdlib.h>
int** readMat(int *righe,int* colonne){
	printf("Inserisci il numero di righe della matrice: ");
	scanf("%d",righe);
	
	printf("Inserisci il numero di colonne della matrice: ");
	scanf("%d",colonne);
	
	if (righe <= 0 || colonne <= 0) {
        printf("Le dimensioni della matrice devono essere positive.\n");
        return NULL; // Dimensioni non valide
    }
    
    //allocazione dinamcia matrice
    int** matrix = malloc((*(righe)) * (sizeof(int*)) );
    if(matrix==NULL){
    	perror("Errore allcazione matrice");
    	return NULL;
	}
	
	for(int i=0;i<*righe;i++){
		matrix[i]=malloc((*(colonne))*(sizeof(int)));
		if(matrix[i] == NULL) {
        	perror("Errore nell'allocazione della memoria per le colonne");
			for(int k=0;k<i;k++){
				free(matrix[k]);
			}
			free(matrix);
			return NULL;
		}
	}
	
	printf("Inserisci i valori della matrice:\n");
    for (int i = 0; i < *righe; i++) {
        for (int j = 0; j < *colonne; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

	return matrix;
}
	


void libera_matrice(int** matrice, int righe){
	for(int i=0;i<righe;i++){
		free(matrice[i]);
	}
	free(matrice);
}

// Funzione per stampare una matrice
void stampa_matrice(int** matrice, int righe, int colonne) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");  // Vai a capo dopo ogni riga
    }
}

void removeColMatrix(int** matrix,int righe,int* colonne,int colToRemove){
	if (colToRemove < 0 || colToRemove >= *colonne) {
    	printf("Errore: Indice colonna non valido.\n");
        return; // Esci dalla funzione se l'indice non è valido
    }
	for(int i=0;i<righe;i++){
		for(int j=colToRemove;j<*(colonne)-1;j++){
			matrix[i][j]=matrix[i][j+1];
		}
	}
	//decremento numero colonne
	*(colonne)--;
}
void removeZeroColMatrix(int** matrix,int righe,int* colonne){
	for(int j=0;j<*colonne;j++){
		int i=0;
		int onlyzero=1;
		while(i<righe && onlyzero==1 ){
			//se elemento della colonna non è zero allora cambio valore di onlyzero
			if(matrix[i][j]!=0){
				onlyzero=0;
			}
			i++;
		}
		if(onlyzero==1){
			removeColMatrix(matrix,righe,colonne,j);
			j--;
		}
	}
}

int main(){
	int r,c;
	int** matrix = readMat(&r,&c);
	if(matrix==NULL){
		return -1;
	}
	printf("Matrice %d * %d\n",r,c);
	stampa_matrice(matrix,r,c);
	
	removeZeroColMatrix(matrix,r,&c);
	
	printf("Matrice Rimozione zeri %d * %d\n",r,c);
	stampa_matrice(matrix,r,c);
	
	libera_matrice(matrix,r);
	
	return 0;
}
