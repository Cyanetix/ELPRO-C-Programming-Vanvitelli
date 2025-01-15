//algoritmo che riconsoce quando carattere uguale al successivo prende indice e lo da all'algoritmo per eliminare elemento dall'array
#define DIM 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char frase[DIM];
	printf("Inserisci una frase in cui vuoi eliminare le doppie\n");
	
	fgets(frase,DIM,stdin);//funzione di libreria stdlib che permette di leggere da file e lo stdinput come terminale viene visto come file
	
	puts(frase);
	printf("\n");
	int i = 0;
	int j = 0;
	for(i = 0; i < strlen(frase); i++){
		if(frase[i] == frase[i+1]){
			for(j = i; j < strlen(frase); j++){
				frase[j] = frase[j+1];
			}
		}
	}
	puts(frase);
	return 0;
}
