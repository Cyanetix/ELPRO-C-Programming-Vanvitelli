/*
Ricerca di tutte le occorrenze di una sottostringa con strstr 
Obiettivo: Trovare tutte le occorrenze di una sottostringa in una stringa usando la 
funzione strstr.
o Compiti:  
? Leggere due stringhe da input. 
? Trovare tutte le occorrenze della seconda stringa nella prima. 
? Stampare la posizione di ogni occorrenza o un messaggio se non ci sono 
occorrenze.
*/
#include <stdio.h>
#include <string.h>
#define NMAX 100
void findsOccurrences(char s1[],char s2[]);
int main(){
	//dichiarazione stringhe
	char s1[NMAX];
	char s2[NMAX];
	
	//lettura stringhe da input
	printf("Inserisci la prima stringa:\n");
	fgets(s1,NMAX,stdin);
	//elimino \n dalla stringa letta con strcspn
	s1[strcspn(s1,"\n")]='\0';
	
	printf("\n");
	
	printf("Inserisci la seconda stringa:\n");
	fgets(s2,NMAX,stdin);
	//elimino \n dalla stringa letta con strcspn
	s2[strcspn(s2,"\n")]='\0';
	
	findsOccurrences(s1,s2);
	return 0;
}
void findsOccurrences(char s1[],char s2[]){
	int pos;//posizione occorenza
	char *c;
	//strstr restituisce come risultato puntatore a carattere
	//null se non trova la s2 in s1 e non null se trova s2 in s1
	char *currentTex = s1;
	int found=0;
	//stampare posizione di ogni occorrenza trovata o un messaggio se non ci sono
	while((c = strstr(currentTex,s2))!=NULL){
		pos=c-s1;//posizione di s2 nella stringa s1 è data dalla differenza tra l'indirizzo dell'occorenza e indrizzo iniziale stringa 
		printf("Trovata '%s' alla posizione: %d\n",s2,pos);
		
		//aggiornare il puntatore ogni volta
		currentTex = c + strlen(s2);//sarà uguale alla posizione dell'ultima occorenza + la lunghezza della sottostringa s2 da trovare
		//questo perchè str str restituisce puntatore al primo carattere della parola che è stata trovata
		found=1;
	}
	//se non trovato
	if(!found){
		printf("Nessuna occorrenza di '%s' trovata in '%s'\n",s2,s1);
	}
}
