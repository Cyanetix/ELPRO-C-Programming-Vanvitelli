/*
Analisi di testo con struct (conteggio parole, caratteri e medie) 
o Obiettivo: Analizzare un testo, individuare le frasi e calcolarne il numero di caratteri, 
parole, e le medie. 
o Compiti:  
? Leggere un testo dal file "testo.txt". 
? Individuare le frasi usando i caratteri di terminazione ('.', '!', '?'). 
? Per ogni frase, creare una struttura Mystruct con i seguenti campi:  
? id: indice della frase 
? chars: numero di caratteri della frase 
? words: numero di parole della frase 
? meanc: numero medio di caratteri per frase fino alla frase corrente 
? meanw: numero medio di parole per frase fino alla frase corrente 
? Ordinare il vettore di struct per valori decrescenti del campo chars. 
? Salvare il vettore di struct nel file binario "output.bin".
*/
#include <stdio.h>
#include <string.h>
#define N_MAX 100
struct Mystruct{
	int id;
	int chars;
	int words;
	float meanc;
	float meanw;
};

int contaParole(char *s);//funziona che data una stringa conta le parole in essa
void ordinaStruct(struct Mystruct v[],int n);

int main(){
	FILE *fp;
	char s[1024];
	char *temp,*frase;
	int n=0;
	struct Mystruct v[N_MAX];
	float totalchars=0;
	float totalwords=0;
	memset(v,0,sizeof(struct Mystruct)*N_MAX);
	
	//lettura file di testo
	char filename[]= "testo.txt";
	//apertura file di testo
	fp = fopen(filename,"r");
	if(fp==NULL){
		printf("Errore nell'aperture file %s",filename);
		return -1;
	}
	
	//file aperto correttamente
	//leggo tutte le righe
	do{
		//lettura intera riga
		temp = fgets(s,sizeof(s),fp);
		if(temp!=NULL){
			//se l'ultimo carattere della riga letta è un accapo lo sostituisco con carattere '\0'
			if(s[strlen(s)-1]=='\n'){
				s[strlen(s)-1]='\0';
			}
			
			//suddivisione in frasi con strtok
			frase=strtok(s,".!?");
			while(frase!=NULL){
				//per ogni frase inizializzo struct
				v[n].id=n;
				v[n].chars=strlen(frase);
				v[n].words=contaParole(frase);
				totalchars+=v[n].chars;
				v[n].meanc=totalchars/(n+1);
				totalwords+=v[n].words;
				v[n].meanw=totalwords/(n+1);
				n++;//incremento contatore frasi
				puts(frase);
				frase=strtok(NULL,".!?");//passo alla prossima parola
			}	
		}
	}while(temp!=NULL);//fgets restituisce null alla EOF o se non è riuscito a leggere
	
	//chiusura file
	fclose(fp);
	
	//ordina vettore struct
	ordinaStruct(v,n);//n è il numero di frasi del file
	
	//stampa struct
	printf("Structs: %d\n",n);
	for(int i=0;i<n;i++){
		printf("{%d, %d, %d, %.2f, %.2f}\n",v[i].id,v[i].chars,v[i].words,v[i].meanc,v[i].meanw);
	}
	
	//salvataggio struct in file binario output.bin
	fp=fopen("output.bin","wb");//apertura in modalità scrittura binaria
	if(fp==NULL){
		printf("Errore nell'aperture file output.bin");
		return -1;
	}
	
	//file bin aperto correttamente
	int num=fwrite(v,sizeof(struct Mystruct),n,fp);
	//se elementi scritti nel file bin non sono tutti e n allora errore
	if(num!=n){
		printf("Errore scrittura su file output.bin");
		return -1;
	}
	
	fclose(fp);	
	return 0;
}

int contaParole(char *s){
	int i=0;
	int contWords=0;
	
	while(s[i]!='\0'){
		if(s[i]!=' ' && s[i+1]==' ' || s[i+1]=='\0'){
			contWords++;
		}
		i++;
	}
	return contWords;
}

void ordinaStruct(struct Mystruct v[],int n){
	struct Mystruct temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(v[j].chars < v[j+1].chars){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}


