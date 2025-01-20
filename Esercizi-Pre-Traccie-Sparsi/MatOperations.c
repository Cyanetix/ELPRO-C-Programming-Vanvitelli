/*
Manipolazione di una matrice con scambio diagonali, 
eliminazione/aggiunta di righe e colonne
 
? Obiettivo: Implementare funzioni per manipolare una matrice, inclusa lo scambio delle 
diagonali, l'eliminazione e l'aggiunta di righe e colonne. 
? Compiti:  
o Implementare una funzione per leggere le dimensioni e gli elementi della matrice da 
input. 
o Implementare una funzione per stampare la matrice. 
o Implementare una funzione per scambiare gli elementi della diagonale principale con 
quelli della diagonale secondaria. 
o Implementare una funzione per eliminare una riga specificata dalla matrice. 
o Implementare una funzione per aggiungere una nuova riga alla matrice. 
o Implementare una funzione per eliminare una colonna specificata dalla matrice. 
o Implementare una funzione per aggiungere una nuova colonna alla matrice. 
o Testare le funzioni nel main e stampare i risultati intermedi.
*/
#include <stdio.h>
#include <string.h>
#define NMAX 100
//per generalizzare ulteriormente le funzioni mette come parametri sia righe che colonne,
// in modo da poter riutilizzare le funzioni che non sono specifiche delle matrici quadrate
void readMat(int mat[][NMAX],int r,int c);
void printMat(int mat[][NMAX],int r,int c);
void swapDiagonals(int mat[][NMAX],int r);
void swapMatElements(int* a,int* b);
void removeRow(int mat[][NMAX],int *r,int c,int rowToRemove);
void addRow(int mat[][NMAX],int *r,int c);
void removeCol(int mat[][NMAX],int r,int *c,int colsToRemove);
void addCol(int mat[][NMAX], int r, int *c);

int main(){
	int mat[NMAX][NMAX];
	int r;
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
	readMat(mat,r,r);
	
	//stampa matrice
	printf("\nMatrice completa:\n");
	printMat(mat,r,r);
	
	//swap diagonali
	swapDiagonals(mat,r);
	printf("\nMatrice after swap diagonali:\n");
	printMat(mat,r,r);
	
	//lettura riga da eliminare
	int rowToRemove = 0;
	do{
		printf("\nChe riga vuoi rimuovere:");
		scanf("%d",&rowToRemove);
		if(rowToRemove>=r || rowToRemove<0){
			printf("Riga non esistente, prova di nuovo\n");
		}
	}while(rowToRemove>=r || rowToRemove<0);
	
	//rimozione riga
	int c=r;
	removeRow(mat,&r,c,rowToRemove);
	printf("\nMatrice after removing row %d:\n",rowToRemove);
	printMat(mat,r,c);
	
	//aggiunta riga
	addRow(mat,&r,c);
	printf("\nMatrice after adding row:\n");
	printMat(mat,r,c);
	
	//lettura colonna da eliminare
	int colsToRemove = 0;
	do{
		printf("\nChe colonna vuoi rimuovere:");
		scanf("%d",&colsToRemove);
		if(colsToRemove>=c || colsToRemove<0){
			printf("Colonna non esistente, prova di nuovo\n");
		}
	}while(colsToRemove>=c || colsToRemove<0);
	
	//rimozione colonna
	removeCol(mat,r,&c,colsToRemove);
	printf("\nMatrice after removing col %d:\n",colsToRemove);
	printMat(mat,r,c);
	
	//aggiunta colonna
    addCol(mat,r,&c);
    printf("\nMatrice after adding col:\n");
    printMat(mat,r,c);
	
	return 0;
}

//funzione leggi matrice
void readMat(int m[][NMAX],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){ //ora j va fino a r per matrice quadrata
			printf("matrix [%d][%d]: ",i,j);
			scanf("%d",&m[i][j]);
		}
		printf("\n");
	}
}
//funzione stampa matrice
void printMat(int mat[][NMAX],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){ //ora j va fino a r per matrice quadrata
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

void swapDiagonals(int mat[][NMAX],int r){
	for(int i=0;i<r;i++){
		swapMatElements(&mat[i][i],&mat[i][r-1-i]);
	}
}

void swapMatElements(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void removeRow(int mat[][NMAX],int *r,int c,int rowToRemove){
	if(rowToRemove<0 || rowToRemove>=*r) return;
	for(int i=rowToRemove;i<*r-1;i++){
		for(int j=0;j<c;j++){
			mat[i][j] = mat[i+1][j];
		}
	}
	//decrementa numero righe
	(*r)--;
}

void addRow(int mat[][NMAX],int *r,int c){
	//se r è il numero massimo di righe non è possibile aggiungerle quindi errore
	if(*r>=NMAX){
		printf("Non è possibile aggiungere una riga, dimensione massima raggiunta");
	}else{
		printf("\nInserisci i valori della riga:\n");
		for(int j=0;j<c;j++){
			printf("Elemento [%d][%d]:",*r,j);
			scanf("%d",&mat[*r][j]);
			printf("\n");
		}
		//incrementa numero righe
		(*r)++;
	}
}

void removeCol(int mat[][NMAX],int r,int *c,int colsToRemove){
	if(colsToRemove<0 || colsToRemove>=*c) return;
	for(int i=0;i<r;i++){
		for(int j=colsToRemove;j<*c-1;j++){
			mat[i][j] = mat[i][j+1];
		}
	}
	//decrementa numero colonne
	(*c)--;
}

void addCol(int mat[][NMAX],int r,int *c){
	//se c è il numero massimo di colonne non è possibile aggiungerle quindi errore
	if(*c>=NMAX){
		printf("Non è possibile aggiungere una colonna, dimensione massima raggiunta");
	}else{
		printf("\nInserisci i valori della colonna:\n");
		for(int i=0;i<r;i++){
			printf("Elemento [%d][%d]:",i,*c);
			scanf("%d",&mat[i][*c]);
		}
		//incrementa numero righe
		(*c)++;
	}
}
/*
Esempio di input e output del programma:

Input:
Matrice iniziale (5x5):
  1   2   3   4   5
  6   7   8   9  10
 11  12  13  14  15
 16  17  18  19  20
 21  22  23  24  25

Dopo lo scambio delle diagonali:
  5   2   3   4   1
  6   9   8   7  10
 11  12  13  14  15
 16  19  18  17  20
 25  22  23  24  21

Dopo l'eliminazione della riga 2:
  5   2   3   4   1
 11  12  13  14  15
 16  19  18  17  20
 25  22  23  24  21

Dopo l'aggiunta di una nuova riga alla fine:
  5   2   3   4   1
 11  12  13  14  15
 16  19  18  17  20
 25  22  23  24  21
 30  31  32  33  34

Dopo l'eliminazione della colonna 3:
  5   2   4   1
 11  12  14  15
 16  19  17  20
 25  22  24  21
 30  31  33  34

Dopo l'aggiunta di una nuova colonna alla fine:
  5   2   4   1   40
 11  12  14  15   41
 16  19  17  20   42
 25  22  24  21   43
 30  31  33  34   44
*/


