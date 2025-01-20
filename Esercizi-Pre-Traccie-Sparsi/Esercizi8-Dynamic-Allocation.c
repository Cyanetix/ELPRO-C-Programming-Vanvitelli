/*
Allocazione di un array di stringhe
Obiettivo:
1.	Allocare un array di 5 stringhe (array di char*).
2.	Ogni stringa deve essere allocata dinamicamente con lunghezza variabile (es. "Ciao", "Mondo").
3.	Stampare tutte le stringhe.
4.	Deallocare tutta la memoria.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 100
int main(){
	int numStrings = 5; 
	//allocato un array di puntatori a carattere di dimensione 5
	char** strings = malloc(numStrings*sizeof(char*));
	if(strings==NULL){
		perror("Errore allocazione array di puntatori a carattere");
		return -1;
	}
	
	//allocazione dinamica con lunghezza variabile delle stringhe lette da input
	for(int i=0;i<numStrings;i++){
		char buffer[BUF_SIZE];
		
		printf("Inserisci stringa %d:\n",i);
		//lettura stringa
		fgets(buffer,BUF_SIZE,stdin);
		//rimozione carattere new line
		buffer[strcspn(buffer,"\n")]='\0';
		//alloco spazio per la stringa letta
		strings[i]=malloc((strlen(buffer)+1)*sizeof(char));//+1 perchè strlen escluse carattere terminatore dal conteggio
		if(strings[i]==NULL){
			perror("Errore di allocazione della memoria per la stringa");
			//dealloco memoria fino ad adesso allocata
			for(int j=0;j<i;j++){
				free(strings[j]);
			}
			free(strings);
			return -1;
		}
		
		//copio stringa buffer nell'array di stringhe
		strcpy(strings[i],buffer);
	}
	
	//stampa stringhe
	printf("\nStringhe inserite:\n");
	for(int i=0;i<numStrings;i++){
		printf("%d: %s\n",i+1,strings[i]);
	}
	
	//deallocare memoria
	for(int j=0;j<numStrings;j++){
		free(strings[j]);
	}
	free(strings);
	
	return 0;
}
