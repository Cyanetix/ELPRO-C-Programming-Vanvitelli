/*
Modifica di una matrice con sostituzione di elementi nulli 
? Obiettivo: Modificare le colonne di una matrice, sostituendo gli elementi nulli con il minimo 
della colonna successiva e il massimo della colonna successiva 
? Compiti:  
o Leggere le dimensioni e gli elementi della matrice dal file "input.txt". 
o Modificare le colonne della matrice sostituendo gli elementi nulli nel modo indicato:  
? il primo elemento nullo della colonna deve essere sostituito con l’elemento 
minimo della colonna successiva. 
? il secondo elemento nullo della colonna deve essere sostituito con l’elemento 
massimo.
*/
#include <stdio.h>
#define NMAX 100
void readMatFile(int mat[][NMAX],int* r, int* c);
int findMinCol(int mat[][NMAX],int r, int col_index);
int findMaxCol(int mat[][NMAX],int r, int col_index);
void modifyMatrixColumns(int mat[][NMAX],int r,int c);
void printMatrix(int mat[][NMAX],int r,int c);
int main(){
	int mat[NMAX][NMAX];
	int r,c;
	readMatFile(mat,&r,&c);
	if(r<=0 || r>NMAX || c<=0 || c>NMAX){
		printf("Dimensioni matrice non valide (righe e colonne devono essere tra 1 e %d)\n", NMAX);
		return -1;
	}
	printf("Righe:%d ; Colonne: %d\n",r,c);
	//stampa matrice
	printf("Matrice:\n");
	printMatrix(mat,r,c);

	//modifico matrice come richiesto
	modifyMatrixColumns(mat,r,c);
	//stampa matrice
	printf("Matrice modificata:\n");
	printMatrix(mat,r,c);
	
	
	return 0;
}

void readMatFile(int mat[][NMAX],int* r, int* c){
	FILE *fp;
	char filename[]="input.txt";
	
	fp = fopen(filename,"r");
	if(fp==NULL){
		printf("Errore nell'apertura file %s\n",filename);
		return;
	}
	
	int num = fscanf(fp,"%d %d",r,c);
	if(num!=2){
		printf("Errore nella lettura del numero righe e colonne da file");
		//chiusura file
		fclose(fp);
		return;
	}
	
	//lettura elementi matrice da file
	for(int i=0;i<*r;i++){
		for(int j=0;j<*c;j++){
			num = fscanf(fp,"%d",&mat[i][j]);
			if(num!=1){
				printf("Errore lettura elemento matrice da file");
				fclose(fp);
				return;
			}
		}
	}
	
	fclose(fp);
}


int findMinCol(int mat[][NMAX],int r, int col_index){
	//trovare il minimo di una colonna data
	int min = mat[0][col_index];
	for(int i=1;i<r;i++){
		if(min>mat[i][col_index]){
			min = mat[i][col_index];
		}
	}
	return min;
}

int findMaxCol(int mat[][NMAX],int r, int col_index){
	//trovare il massimo di una colonna data
	int max = mat[0][col_index];
	for(int i=1;i<r;i++){
		if(max<mat[i][col_index]){
			max = mat[i][col_index];
		}
	}
	return max;
}

void modifyMatrixColumns(int mat[][NMAX],int r,int c){	
	for(int j=0;j<c-1;j++){
		int numNulli = 0;
		for(int i=0;i<r;i++){
			if(mat[i][j]==0){
				if(numNulli==0){
					//se l'elemento è nullo ed è il primo nullo ovvero numero nulli è 0 allora sostituisco con minimo della colonna successiva				
					mat[i][j] = findMinCol(mat,r,j+1);
					numNulli++;
				}else if(numNulli==1){
					mat[i][j] = findMaxCol(mat,r,j+1);
					numNulli++;
				}
			}
		}
	}
}

void printMatrix(int mat[][NMAX],int r,int c){
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
