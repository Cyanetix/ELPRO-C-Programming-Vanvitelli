//Verifica palindromia di una stringa
/*
o Obiettivo: Verificare se una stringa inserita dall'utente è palindroma.
o Compiti:
? Leggere una stringa da input.
? Verificare se la stringa è palindroma (si legge uguale da sinistra a destra e
viceversa).
? Stampare a video se la stringa è palindroma o meno.
*/
#include <stdio.h>
#include <string.h>
#define NMAX 100
int isPalindrome(char *s);
int main(){
	char s[NMAX];
	//lettura stringa da console con fgets
	printf("Inserisci una stringa:\n");
	fgets(s,NMAX,stdin);
	//stampa stringa printf("%s",s);
	if(isPalindrome(s)){
		//se palindroma
		printf("\nLa stringa: %s e' palindroma\n",s);
	}else{
		//non palindroma
		printf("\nLa stringa: %s non e' palindroma\n",s);
	}
	
}
int isPalindrome(char *s){
	/*
	//calcolo lunghezza stringa senza utilizza di strlen
	int len=0;
	while(s[len]!='\0'){
		len++;
		printf("char: %c , conteggio: %d\n",s[len-1],len);
	}
	//calcolo lunghezza stringa con funzione strlen
	len = strlen(s);
	*/
	int len = strlen(s);
	if((len>0) && (s[len-1]=='\n')){
		s[len-1]='\0';
		len--;
	}
	//conversione della stringa tutta in minuscolo
	for(int i=0;i<len;i++){
		if(s[i]>='A' && s[i]<='Z'){
			s[i]=s[i]+('a'-'A');//aggiunge la differenza tra maiuscole e minuscole
		}
	}
	
	//controllo se palindroma
	int i=0;
	while(i<len/2){
		if(s[i]!=s[len-1-i]){
			return 0;
		}
		i++;
	}
	return 1;
}
