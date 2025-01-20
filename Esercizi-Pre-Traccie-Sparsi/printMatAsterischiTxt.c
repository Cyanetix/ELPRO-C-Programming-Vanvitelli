/*
Stampa di una matrice con asterischi in posizioni specifiche (file di
testo)
o Obiettivo: Leggere da un file di testo le dimensioni di una matrice e le posizioni dove
stampare un asterisco, visualizzando la matrice.
o Compiti:
? Leggere dal file "sm.txt" le dimensioni della matrice (r, c) e le coppie di indici (l,
k).
? Stampare una matrice di caratteri dove le posizioni indicate nel file di testo
contengono un asterisco ('*') e le altre posizioni contengono uno spazio vuoto (' ').
*/
/*
Esempio:
3 4
0 0
1 3
1 2
2 1
*/
#include<stdio.h>
#include<string.h>
#define NMAX 100
void printMatrix(char matrix[NMAX][NMAX],int rows,int cols);
int main(){
	int r,c;//riga e colonna
	char filename[]="sm.txt";
	char mat[NMAX][NMAX];
	
	//matrice impostata a ' '
	memset(mat,' ',sizeof(mat));
	
	FILE *fp;
	//lettura file di testo
	fp = fopen(filename,"r");
	
	if(fp==NULL){
		printf("Errore apertura file %s",filename);
		return -1;
	}
	
	//lettura riga e colonna da file di testo
	if( fscanf(fp,"%d %d",&r,&c)!=2){
		printf("Errore lettura numero rige e colonne da file %s",filename);
		return -1;
	}
	
	if (r <= 0 || r > NMAX || c <= 0 || c > NMAX) {
        printf("Dimensioni della matrice non valide. Devono essere positive e <= %d.\n",NMAX);
        fclose(fp);
        return -1;
    }
	
	//variabile contenete le due componenti coordinate di dove inserire '*'
	int x,y;
	while(fscanf(fp,"%d %d",&x,&y)==2){
		//controllo la validità delle coordinate
		if(x >= 0 && x < r && y >= 0 && y < c){
			mat[x][y]='*';	
		}
	}
	
	fclose(fp);
    printf("\nMatrice risultante:\n");
    printMatrix(mat,r,c);;	
	
	return 0;
}

void printMatrix(char matrix[NMAX][NMAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n"); // Nuova riga dopo ogni riga della matrice
    }
}
