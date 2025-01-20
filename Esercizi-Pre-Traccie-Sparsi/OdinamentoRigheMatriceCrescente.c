/*
Ordinamento degli elementi di una riga di una matrice
o Obiettivo: Ordinare gli elementi di ciascuna riga di una matrice in ordine crescente. 
o Compiti:  
? Leggere le dimensioni della matrice (r, c). 
? Leggere gli elementi della matrice. 
? Ordinare gli elementi di ciascuna riga in ordine crescente.
*/
#include <stdio.h>
#include <string.h>//libreria che contiene memset
#define NMAX 100
void readMat(int m[][NMAX],int r,int c);
void printMat(int m[][NMAX],int r,int c);
void sortInRow(int m[][NMAX],int r,int c);//funzione ordina righe
void selectionSort(int m[],int c);//selection sort array

int main(){
	int mat[NMAX][NMAX];
	int r,c;//righe e colonne
	
	//azzeramento della matrice con memset
    memset(mat,0,sizeof(mat));
    
    do{
		printf("Inserisci il numero di righe(> 0 e < %d):\n",NMAX);
		scanf("%d",&r);
		if(r<=0 || r>=NMAX){
			printf("Hai inserito una dimensione errata\n");
		}
		printf("\n");
	}while(r<=0 || r>=NMAX);
	
	//acquisizione numero colonne valido
	do{
		printf("Inserisci il numero di colonne(> 0 e < %d):\n",NMAX);
		scanf("%d",&c);
		if(c<=0 || c>=NMAX){
			printf("Hai inserito una dimensione errata\n");
		}
		printf("\n");
	}while(c<=0 || c>=NMAX);
	
	//lettura matrice
	printf("Inserisci gli elementi della matrice:\n");
	readMat(mat,r,c);
	
	//stampa matrice
	printf("\nMatrice:\n");
	printMat(mat,r,c);
	
	//ordinamento crescente righe matrice
	sortInRow(mat,r,c);
	
	printf("\nMatrice Ordinata:\n");
	printMat(mat,r,c);
	
	return 0;
}

//funzione lettura matrice
void readMat(int m[][NMAX],int r,int c){
	for(int i=0;i<r;i++){
		printf("\nRiga:%d\n",i);
		for(int j=0;j<c;j++){
			printf("Inserisci elemento [%d][%d]: ",i,j);
			scanf("%d",&m[i][j]);
		}
		printf("\n");
	}
}

//funzione stampa matrice
void printMat(int m[][NMAX],int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%4d ",m[i][j]);
		}
		printf("\n");
	}
}
/*
//versione per intero della funzione ordina per righe

void sortInRow(int m[][NMAX],int r,int c){
	//ordinamento crescente delle singole righe matrice
	//richiamo la funzione che ordina array con selection sort per tutte le righe della matrice passandole come array distinti
	int posmin;
	for(int i=0;i<r;i++){
		for(int j=0;j<c-1;j++){
			posmin=j;
			for(int k=j+1;k<c;k++){
				if(m[i][posmin]>m[i][k]){
					posmin=k;
				}
			}
			int temp = m[i][j];
			m[i][j] = m[i][posmin];
			m[i][posmin] = temp;
		}
	}
}
*/

void sortInRow(int m[][NMAX],int r,int c){
	//ordinamento crescente delle singole righe matrice
	//richiamo la funzione che ordina array con selection sort per tutte le righe della matrice passandole come array distinti
	for(int i=0;i<r;i++){
		selectionSort(m[i],c);	
	}
}

void selectionSort(int v[],int c){
	int posmin;
	for(int i=0;i<c-1;i++){
		posmin = i;
		for(int j=i+1;j<c;j++){
			if(v[posmin]>v[j]){
				posmin=j;
			}
		}
		//scambio
		int temp = v[i];
		v[i] = v[posmin];
		v[posmin] = temp;
	}
}


