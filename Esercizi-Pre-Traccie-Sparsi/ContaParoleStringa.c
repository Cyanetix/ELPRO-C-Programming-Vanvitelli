/*
Conta parole in una stringa 
o Obiettivo: Contare il numero di parole presenti in una stringa inserita dall'utente. 
o Compiti:  
? Leggere una stringa da input (usando fgets). 
? Contare le parole presenti nella stringa. 
? Stampare il numero di parole. 
*/
#include<stdio.h>
#include<string.h>
#define NMAX 200
int contaParole(char s[]);
int main(){
	char s[NMAX];
	int words = 0;
	////lettura stringa da console con fgets
	printf("Inserisci una stringa di cui vuoi contare il numero di parole:\n");
	fgets(s,NMAX,stdin);
	words = contaParole(s);
	printf("\n");
	printf("Il numero di parole nella stringa e': %d\n", words);
return 0;	
}

int contaParole(char s[]){
	int i=0;
	int contWords=0;
	/*
	while(s[i]!='\0'){
		if(s[i]!=' '){
			if(s[i+1]==' ' || s[i+1]=='\0'){
				contWords++;
			}
		}
		i++;
	}*/
	
	//versione con strtok
	char *token=strtok(s," \n\t");
	while(token!=NULL){ //quando arriva alla fine della stringa passata come argomento alla funzione, strtok restituisce NULL
		printf("Token: %s\n", token);
		contWords++;
		token=strtok(NULL," \n\t");
	}
	
	return contWords;
}
