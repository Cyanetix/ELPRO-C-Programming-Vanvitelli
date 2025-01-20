/*
Gestione di una matrice con struct (ordinamento, eliminazione righe 
dispari) 
o Obiettivo: Leggere una matrice, ordinarla per somme di righe, eliminare righe 
specifiche e salvare le righe rimanenti in un vettore di struct. 
o Compiti:  
? Leggere le dimensioni e gli elementi di una matrice dal file "input2.txt". 
? Calcolare la somma di ogni riga della matrice. 
? Ordinare le righe della matrice per valori decrescenti della loro somma. 
? Eliminare le righe con somma dispari che hanno indice dispari. 
? Creare un vettore di strutture Mystruct, dove ogni struttura rappresenta una riga 
della matrice modificata e contiene:  
? rig: l'indice della riga 
? c: il numero di elementi della riga 
? elementi: i valori degli elementi della riga 
? Salvare il vettore di struct nel file binario "output.bin". 
*/

#include <stdio.h>
#include <string.h>
#define N_MAX 100
struct Mystruct{
	int rig;
	int c;
	int elementi[N_MAX];
};

void readMatFile(int mat[][N_MAX],int *r,int *c);//funzione lettura matrice da file
void printMatrix(int mat[][N_MAX],int r,int c);//funzione stampa a video matrice
void ordinaMatSommaR(int mat[][N_MAX],int r,int c);
void scambiaRighe(int mat[][N_MAX],int row1,int row2,int c);
int calcSommaRiga(int v[],int c);
void swapMatElements(int* a,int* b);
void eliminaRigheSommaDispari(int mat[][N_MAX], int *r, int c);
void removeRow(int mat[][N_MAX],int *r,int c,int rowToRemove);
void salvaStructBinario(struct Mystruct v[],int n);

void stampaFileBinario(){
    FILE *fp;
    char filename[] = "output2.bin";
    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Errore nell'apertura file %s\n", filename);
        return;
    }
    
    struct Mystruct v[N_MAX];
    int numStruct = 0;
    
    // Leggo le struct dal file fino a raggiungere la fine o il limite dell'array statico
    while(fread(&v[numStruct], sizeof(struct Mystruct), 1, fp) == 1){
        numStruct++;
        if(numStruct == N_MAX)
            break;
    }
    fclose(fp);
    
    // Stampo il contenuto del file binario: per ogni struct stampo {rig, c, [elementi]}
    for(int i = 0; i < numStruct; i++){
        printf("{%d, %d, [", v[i].rig, v[i].c);
        for(int j = 0; j < v[i].c; j++){
            printf("%d", v[i].elementi[j]);
            if(j < v[i].c - 1)
                printf(", ");
        }
        printf("]}\n");
	}
}

int main(){
	int mat[N_MAX][N_MAX];
	struct Mystruct v[N_MAX];
	int r,c;
	memset(mat,0,sizeof(mat));
	memset(v,0,sizeof(struct Mystruct)*N_MAX);
	
	//lettura matrice da file
	readMatFile(mat,&r,&c);
	
	printf("Matrice letta da file:\n");
	printMatrix(mat,r,c);
	printf("\n");
	
	ordinaMatSommaR(mat,r,c);
	printf("Matrice dopo scambi righe:\n");
	printMatrix(mat,r,c);
	printf("\n");
	
	eliminaRigheSommaDispari(mat,&r,c);
	printf("Matrice dopo eliminazione righe con somma e indice dispari:\n");
	printMatrix(mat,r,c);
	printf("\n");
	
	//vettore di struct, una per ogni riga della matrice modificata
	for(int i=0;i<r;i++){
		v[i].rig=i;//riga corrente
		v[i].c=c;//numero elementi , quindi numero colonne matrice
		//salvataggio elementi della riga
		for(int j=0;j<c;j++){
			v[i].elementi[j]=mat[i][j];
		}
	}
	
	//salvataggio vettore struct in file binario “output.bin”
	salvaStructBinario(v,r);
	
	stampaFileBinario();
	return 0;
}

void readMatFile(int mat[][N_MAX],int *r,int *c){
	FILE *fp;
	char filename[]="input2.txt";
	fp=fopen(filename,"r");
	if(fp==NULL){
		printf("Errore nell'apertura file %s\n",filename);
		return;
	}
	
	//lettura numero righe e colonne
	fscanf(fp,"%d %d",r,c);
	
	//lettura elementi matrice da file
	for(int i=0;i<*r;i++){
		for(int j=0;j<*c;j++){
			fscanf(fp,"%d",&mat[i][j]);
		}
	}
	
	//chiusura file
	fclose(fp);
}

void printMatrix(int mat[][N_MAX],int r,int c){
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void ordinaMatSommaR(int mat[][N_MAX],int r,int c){
	for(int i=0;i<r-1;i++){
		for(int j=0;j<r-1-i;j++){
			if( calcSommaRiga(mat[j],c)<calcSommaRiga(mat[j+1],c)){
				scambiaRighe(mat,j,j+1,c);
			}
		}
	}
}

void scambiaRighe(int mat[][N_MAX],int row1,int row2,int c){
	for(int j=0;j<c;j++){
		swapMatElements(&mat[row1][j],&mat[row2][j]);
	}
}

void eliminaRigheSommaDispari(int mat[][N_MAX], int *r, int c){
	int rowToDelete[N_MAX];
	int count = 0;
	//individuazione righe da eliminare
	for(int i=1;i<*r;i+=2){
		//se somma e indice dispari allora aggiungo l'indice della riga nell'elenco di quelli da eliminare
		if(calcSommaRiga(mat[i],c)%2!=0){
			rowToDelete[count]=i;
			count++;
		}
	}
	
	//eliminazione righe
	int old_r=*r;
	//problema con eliminazione riga perchè poi sposta tutti in alto quindi gli indici nuovi non corrispondono ai precedenti
	//soluzioni iterare al contrario o cambiare l'indice da rimuovere in base al cambiamento
	/*
	for(int i=0;i<count;i++){
		removeRow(mat,r,c,rowToDelete[i]-(old_r-*r));
	}
	*/
	for(int i=count-1;i>=0;i--){
		removeRow(mat,r,c,rowToDelete[i]);
	}
}

void salvaStructBinario(struct Mystruct v[],int n){
	FILE *fp;
	char filename[]="output2.bin";
	fp=fopen(filename,"wb");
	
	if(fp==NULL){
		printf("Errore nell'apertura file %s\n",filename);
		return;
	}
	
	//file aperto correttamente, necessaria scrittura
	fwrite(v,sizeof(struct Mystruct),n,fp);
	//chiusura file
	fclose(fp);
}

void removeRow(int mat[][N_MAX],int *r,int c,int rowToRemove){
	for(int i=rowToRemove;i<*r;i++){
		for(int j=0;j<c;j++){
			mat[i][j]=mat[i+1][j];
		}
	}
	//decrementa numero righe
	(*r)--;
}

void swapMatElements(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int calcSommaRiga(int v[],int c){
	int somma = 0;
	for(int j=0;j<c;j++){
		somma+= v[j];
	}
	return somma;
}


