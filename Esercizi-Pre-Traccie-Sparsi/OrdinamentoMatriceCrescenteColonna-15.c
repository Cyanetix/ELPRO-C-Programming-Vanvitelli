/*
Ordinamento righe di una matrice per valori crescenti della prima 
colonna
o Obiettivo: Ordinare le righe di una matrice in base ai valori crescenti della prima 
colonna. 
o Compiti:  
? Leggere le dimensioni della matrice (r, c). 
? Leggere gli elementi della matrice. 
? Ordinare le righe della matrice in modo che i valori nella prima colonna siano in 
ordine crescente. 
? Stampare la matrice ordinata.
*/
#include <stdio.h>
#include <string.h>//libreria che contiene memset
#define NMAX 100
void readMat(int m[][NMAX],int r,int c);
void printMat(int m[][NMAX],int r,int c);
void swapRows(int m[][NMAX],int row1,int row2,int c);//funzione per scambio delle righe
void sortRows(int m[][NMAX],int r,int c);//funzione ordina righe

int main(){
	int mat[NMAX][NMAX];
	int r,c;//righe e colonne
	
	//azzeramento della matrice con memset
    memset(mat,0,sizeof(mat));
	//acquisizione numero righe valido
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
	
	/*
	Test azzeramento matrice
	memset(mat,0,sizeof(mat));
	printf("\nMatrice 0:\n");
	printMat(mat,r,c);
	*/
	
	//ordino matrice
	sortRows(mat,r,c);
	
	printf("\nMatrice Ordinata:\n");
	printMat(mat,r,c);
	
	return 0;
}
//funzione che legge la matrice
void readMat(int m[][NMAX],int r, int c){
	for(int i=0;i<r;i++){
		printf("\nRiga:%d\n",i);
		for(int j=0;j<c;j++){
			printf("Inserisci elemento [%d][%d]: ",i,j);
			scanf("%d",&m[i][j]);
		}
		//prossima riga da leggere quindi vado a capo
		printf("\n");
	}
}

void printMat(int m[][NMAX],int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%4d ",m[i][j]);
		}
		printf("\n");
	}
}

//funzione per scambio delle righe
void swapRows(int m[][NMAX],int row1,int row2,int c){
	int temp;
	for(int i=0;i<c;i++){
		temp = m[row1][i];
		m[row1][i]=m[row2][i];
		m[row2][i]=temp;
	}
}

//funzione ordina righe
void sortRows(int m[][NMAX], int r,int c) {
    for(int i=0;i<r-1;i++){
        int row_min = i;
        for(int j=i+1;j<r;j++){
            if(m[row_min][0]>m[j][0]){
                row_min=j;
            }
        }
        //trovato riga in cui c'è minimo
        swapRows(m,i,row_min,c);
    }
}

