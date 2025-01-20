/*
Ricerca di un vettore in una matrice e salvataggio in struct 
o Obiettivo: Cercare un vettore all'interno di una matrice e salvare le occorrenze in un 
vettore di struct. 
o Compiti:
? Leggere le dimensioni e gli elementi della matrice e del vettore dal file 
"input.txt". 
? Cercare il vettore nella matrice, scorrendola per riga. 
? Per ogni occorrenza del vettore, creare una struttura mystruct con:  
? occ: numero di occorrenza 
? riga: indice della riga del primo elemento dell'occorrenza 
? col: indice di colonna del primo elemento dell'occorrenza 
? len: lunghezza del vettore 
? vettore: il vettore cercato 
? Salvare il vettore di struct nel file "output.bin".
*/
#include <stdio.h>
#include <string.h>
#define N_MAX 100
typedef struct{
	int occ;
	int riga;
	int col;
	int len;
	int vettore[N_MAX];
} Mystruct;

int countVectorOccurrence(Mystruct* vet,int mat[][N_MAX],int r, int c,int v[],int dimVet);//funziona che conta il numero di occorrenze vettore
void printMatrix(int mat[][N_MAX],int r,int c);
void printVet(int v[],int dim);
void printStruct(Mystruct* vet, int dimStruct);

int main(){
	Mystruct vet[N_MAX];
	int mat[N_MAX][N_MAX];
	int v[N_MAX];
	int r,c,dim;
	memset(mat,0,sizeof(mat));
	memset(vet,0,sizeof(Mystruct)*N_MAX);
	
	//lettura da file di testo dim e elementi matrice e vettore
	FILE *fp;
	char filename[]="input3.txt";
	
	//apertura file
	fp=fopen(filename,"r");
	if(fp!=NULL){
		//file aperto correttamente
		fscanf(fp,"%d %d",&r,&c);//lettura numero riga e colonna
		//lettura elementi matrice
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				fscanf(fp,"%d",&mat[i][j]);
			}
		}
		
		fscanf(fp,"%d",&dim);//lettura dimensione vettore
		//lettura elementi vettore
		for(int i=0;i<dim;i++){
			fscanf(fp,"%d",&v[i]);
		}
			
		//chiusura file
		fclose(fp);
		
		printf("Matrice letta da file:\n");
		printMatrix(mat,r,c);
		printf("\n");
		
		printf("Vettore letto da file:\n");
		printVet(v,dim);
		printf("\n");
		
		//cercare vettore nella matrice scorrendo riga per riga e contare quante volte è contenuto
		int numOccurrence=countVectorOccurrence(vet,mat,r,c,v,dim);
		printf("\nNumero occorenze: %d",numOccurrence);
		
		//stampa struct
		printf("\nVettore Struct:\n");
		printStruct(vet,numOccurrence);
		
		//salvataggio della struct su file bin
		FILE *fp_bin;
		char filename_bin[]="output3.bin";

		fp_bin=fopen(filename_bin,"wb");
		if(fp_bin==NULL) {
			printf("Errore nell'apertura del file binario");
			return 1;
		}

		fwrite(vet,sizeof(Mystruct),numOccurrence,fp_bin);
		
		//chiusura file
		fclose(fp_bin);	
		
	}
	
	return 0;
}


int countVectorOccurrence(Mystruct* vet,int mat[][N_MAX],int r, int c,int v[],int dimVet){
	int k=0;
	int contOccurrence=0;
	int  indexStr=0;
	int riga,col;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]==v[k] && k<dimVet){
				k++;
				//se è il primo elemento quindi k=1 allora salvo posizione indici
				if(k==1){
					riga=i;
					col=j;
				}
			}else{
				k=0;
				//se elemento corrente è inizio vettore incremento k di nuovo
				if(mat[i][j]==v[k]){
					k++;
				}
			}
			if(k==dimVet){//se k arrivato a dimivet vuol dire che sono state riconosciute tutte le cifre
				contOccurrence++;//incremento contatore occorrenze vettore
				k=0;//resetto k a 0
				
				//riempio vettore struct
				vet[indexStr].len=dimVet;
				vet[indexStr].occ=contOccurrence;
				vet[indexStr].col=col;
				vet[indexStr].riga=riga;
				
				//salvo vettore
				for(int x=0;x<dimVet;x++){
					vet[indexStr].vettore[x]=v[x];
				}
				//incremento indirizzo vettore struct
				indexStr++;
			}
		}
	}
	return contOccurrence;
}

void printMatrix(int mat[][N_MAX],int r,int c){
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void printVet(int v[],int dim){
	printf("[");
	for(int i=0;i<dim;i++){
		printf("%d\t",v[i]);
	}
	printf("]");
}

void printStruct(Mystruct* vet, int dimStruct){
    for(int i=0;i<dimStruct;i++){
    	printf("{%d, %d, %d, %d, [",vet[i].occ,vet[i].riga,vet[i].col,vet[i].len);
        for(int j=0;j<vet[i].len;j++){
            printf("%d",vet[i].vettore[j]);
            if(j<vet[i].len - 1){
            	printf(" ");
            }
        }
        printf("] }\n");
    }
}


