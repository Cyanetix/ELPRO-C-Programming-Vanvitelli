#include <stdio.h>
#include <string.h>
#define N_MAX 100

//struct declaration
typedef struct{
	int pos;//posizione della prima lettera della parola nella stringa
	char type;//carattere specifica se una sequenza di sole lettere, di lettere e numeri o di soli numeri (‘a’,’b’,’c’)
	int len;//lunghezza parola
} Mystruct;

//leggere da file di testo input.txt la stringa
void readFile(char *s);

//riconoscere le diverse parole della stringa e per ciascuna instanziare struct
int recognizeWords(char *s,Mystruct vet[]);
//funzione che riconosce il tipo di una parola
char whichType(char *s);

//ordinare il vettore di struct per lunghezza della parola
void sortStructLen(Mystruct* vet,int dim);

//stampa struct
void printStruct(Mystruct* vet,int dim);

//ordinare il vettore di struct rispetto alla posizione
void sortStructPos(Mystruct* vet,int dim);

//stampare a video tutte le parole composte da sole lettere, da sole cifre o da lettere e cifre
void printWordsByType(Mystruct* vet,int dim,char type,char *original_string);

//salvare l’array di strutture in un file di binario “output.bin” 
void saveStruct(Mystruct* vet,int dim);

int main(){
	char s[N_MAX];
	Mystruct vet[N_MAX];
	memset(vet,0,sizeof(vet));
	
	readFile(s);
	printf("Stringa letta dal file: %s\n", s);
	
	int numParole = recognizeWords(s,vet);
	printf("Numero di parole: %d\n",numParole);
	
	//stampa struct
	printf("Struct:\n");
	printStruct(vet,numParole);
	
	//riordino vettore struct per lunghezza
	sortStructLen(vet,numParole);
	printf("\nStruct ordinata per lunghezza:\n");
	printStruct(vet,numParole);
	
	
	sortStructPos(vet,numParole);
	printf("\nStruct ordinata per posizione:\n");
	printStruct(vet,numParole);
	
	//stampa parole per tipo
	printf("\nParole composte da sole lettere:\n");
	printWordsByType(vet, numParole, 'a', s); // Passa anche la stringa originale 's'
	printf("\nParole composte da lettere e numeri:\n");
	printWordsByType(vet, numParole, 'b', s); // Passa anche la stringa originale 's'
	printf("\nParole composte da sole cifre:\n");
	printWordsByType(vet, numParole, 'c', s); // Passa anche la stringa originale 's'
	
	saveStruct(vet,numParole);
	return 0;
}

void readFile(char *s){
	FILE *fp;
	char filename[]="input4.txt";
	
	fp=fopen(filename,"r");
	if(fp==NULL){
		fprintf(stderr,"Errore nell'apertura del file");
		return;
	}
	
	char *pt = fgets(s,N_MAX,fp);
	if(pt==NULL){
		fprintf(stderr,"Errore lettura stringa");
	}
	fclose(fp);
}

int recognizeWords(char *s,Mystruct vet[]){
	//copio la stringa usando strcpy
	char stringa_copia[N_MAX];
	strcpy(stringa_copia,s);
	/*
	printf("\n--- Inizio recognizeWords ---\n"); // Indicatore inizio funzione
	printf("Stringa copia: \"%s\"\n", stringa_copia); // Mostra la stringa su cui lavora strtok	
	*/
	char *token;
	int contaParole=0;
	token=strtok(stringa_copia," ");
	/*
	printf("\n--- Ciclo di tokenizzazione ---\n"); // Indicatore inizio ciclo
	*/
	while(token!=NULL){
		//printf("\nParola estratta (token): \"%s\"\n", token); // Mostra la parola estratta da strtok
		
		
		//riconosciuta parola
		//salvo in vettore di struct la parola
		vet[contaParole].len=strlen(token);
		
		//printf("  Lunghezza calcolata: %d\n", vet[contaParole].len); // Mostra la lunghezza calcolata
		
		vet[contaParole].type=whichType(token);
		
		//printf("  Tipo determinato: %c\n", vet[contaParole].type); // Mostra il tipo determinato
		
		//la posizione non è altro che la differenza tra indirizzo della parola corrente meno indirizzo del primo carattera della stringa
		vet[contaParole].pos=token-stringa_copia;
		
		//printf("  Posizione calcolata: %d\n", vet[contaParole].pos); // Mostra la posizione calcolata
		
		//printf("  Struct vet[%d] riempita: {pos: %d, type: %c, len: %d}\n",contaParole, vet[contaParole].pos, vet[contaParole].type, vet[contaParole].len);
		
		contaParole++;
		token=strtok(NULL," ");
		
	}
	//printf("--- Fine recognizeWords ---\n\n"); // Indicatore fine funzione
	return contaParole;
}

char whichType(char *s){
	// 'a' -> Parola composta SOLO da lettere
    // 'b' -> Parola composta da LETTERE e NUMERI
    // 'c' -> Parola composta SOLO da NUMERI
	int flagnum=0,flagchar=0;
	int i=0;
	while(s[i]!='\0'){
		if(s[i]>='0' && s[i]<='9'){
			flagnum=1;
		}else{
			flagchar=1;
		}
		i++;
	}
	
	if(flagnum==1 && flagchar==0){
		//costituita da soli numeri
		return 'c';
	}
	
	if(flagnum==1 && flagchar==1){
		//costituita da lettere e numeri
		return 'b';
	}
	return 'a';
}


void sortStructLen(Mystruct* vet,int dim){
	for(int i=0;i<dim-1;i++){
		for(int j=0;j<dim-1-i;j++){
			if(vet[j].len>vet[j+1].len){
				//swap
				Mystruct temp = vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=temp;
			}
		}
	}
}

void sortStructPos(Mystruct* vet,int dim){
	for(int i=0;i<dim-1;i++){
		for(int j=0;j<dim-1-i;j++){
			if(vet[j].pos>vet[j+1].pos){
				//swap
				Mystruct temp = vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=temp;
			}
		}
	}	
}

void printStruct(Mystruct* vet,int dim){
	for(int i=0;i<dim;i++){
		printf("{%d,%c,%d}\n", vet[i].pos, vet[i].type, vet[i].len);
	}
}

void saveStruct(Mystruct* vet,int dim){
	FILE *fp;
	fp=fopen("output.bin","wb");
	if(fp==NULL){
		fprintf(stderr,"Errore apertura file binario");
		return;
	}
	
	fwrite(vet,sizeof(Mystruct),dim,fp);
	
	fclose(fp);
}

void printWordsByType(Mystruct* vet,int dim,char type,char *original_string){
    printf("Parole di tipo '%c':\n",type);
    for(int i=0;i<dim;i++){
        if(vet[i].type == type){
            //estraggo la parola dalla stringa originale usando pos e len
            char word[N_MAX];
            strncpy(word, original_string + vet[i].pos,vet[i].len);
            word[vet[i].len] = '\0'; // Termina la stringa estratta con null

            printf("Parola: \"%s\", Struct: {%d,%c,%d}\n", word, vet[i].pos, vet[i].type, vet[i].len);
        }
    }
}



