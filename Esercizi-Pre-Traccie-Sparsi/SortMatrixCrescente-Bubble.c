/*
Ordinamento di una matrice con bubble sort
o Obiettivo: Ordinare una matrice di interi per valori crescenti usando l'algoritmo bubble sort.
o Compiti:
    ? Leggere le dimensioni (righe e colonne) della matrice dall'utente.
    ? Leggere gli elementi della matrice dall'utente.
    ? Ordinare la matrice in ordine crescente utilizzando il bubble sort.
    ? Stampare la matrice ordinata.
*/
#include <stdio.h>
#include <string.h>
#define NMAX 100
void readMat(int m[][NMAX],int r,int c);
void printMat(int m[][NMAX],int r,int c);
void matrixInArray(int m[][NMAX],int r,int c,int v[]);
void sortMatBubble(int m[][NMAX],int r,int c,int v[]);
void swapElements(int v[],int index1,int index2);

int main(){
	int mat[NMAX][NMAX];
	int r,c;//righe e colonne
	int v[NMAX*NMAX];
	memset(mat,0,sizeof(mat));
	
	//acquisizione numero righe
	do{
		printf("Inserisci il numero di righe(> 0 e < %d):\n",NMAX);
		scanf("%d",&r);
		if(r<=0 || r>=NMAX){
			printf("Hai inserito una dimensione errata\n");
		}
		printf("\n");
	}while(r<=0 || r>=NMAX);
	
	//acquisizione numero colonne
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
	
	//ordinamento matrice
	sortMatBubble(mat,r,c,v);
	printf("\nMatrice Ordinata:\n");
	printMat(mat,r,c);
	
	return 0;
}

void readMat(int m[][NMAX],int r,int c){
	for(int i=0;i<r;i++){
		printf("\nRiga:%d\n",i);
		for(int j=0;j<c;j++){
			printf("matrix [%d][%d]: ",i,j);
			scanf("%d",&m[i][j]);
		}
		printf("\n");
	}
}

void printMat(int m[][NMAX],int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
}

void matrixInArray(int m[][NMAX],int r,int c,int v[]){
	int index=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			v[index]=m[i][j];
			index++;
		}
	}
}

void arrayInMatrix(int v[],int r,int c,int m[][NMAX]){
    int index=0;
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
            m[i][j]=v[index];
            index++;
        }
    }
}

void bubbleSort(int v[],int dim){
	for(int i=0;i<dim-1;i++){
		for(int j=0;j<dim-1-i;j++){
			if(v[j]>v[j+1]){
				swapElements(v,j,j+1);
			}
		}
	}
}

void swapElements(int v[],int index1,int index2){
	int temp = v[index1];
	v[index1] = v[index2];
	v[index2] = temp;
}

void sortMatBubble(int m[][NMAX],int r,int c,int v[]){
	matrixInArray(m,r,c,v);
	bubbleSort(v,r*c);
	arrayInMatrix(v,r,c,m);
}

