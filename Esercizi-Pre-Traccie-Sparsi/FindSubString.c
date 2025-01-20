/*
Ricerca di una sottostringa 
o Obiettivo: Verificare se una sottostringa è presente in una stringa. 
o Compiti:
? Leggere due stringhe da input. 
? Verificare se la seconda stringa è una sottostringa della prima. 
? Stampare "trovato" se la sottostringa è presente.
*/
#include <stdio.h>
#include <string.h>
#define NMAX 100
int isSubString(char s1[],char s2[]);
int main(){
	//dichiarazione delle due stringhe
	char s1[NMAX];
	char s2[NMAX];
	
	//lettura prima stringa
	printf("Inserisci la prima stringa:\n");
	fgets(s1,NMAX,stdin);
	//rimozione carattere di nuova linea se presente
    if(s1[strlen(s1)-1]=='\n'){
    	s1[strlen(s1)-1]='\0';
    }
    
	printf("\n");
	//lettura seconda stringa
	printf("Inserisci la seconda stringa:\n");
	fgets(s2,NMAX,stdin);
	//rimozione carattere di nuova linea se presente
    if(s2[strlen(s2)-1]=='\n'){
    	s2[strlen(s2)-1]='\0';
    }
	
	if(isSubString(s1,s2)){
		printf("\nLa stringa '%s' e' sottostringa di '%s'",s2,s1);
	}else{
		printf("\n\nLa stringa '%s' non e' sottostringa di '%s'",s2,s1);
	}
	
	return 0;
}
int isSubString(char s1[],char s2[]){
	int i=0,j,temp;
	while(s1[i]!='\0'){
		j=0;
		temp=i;
		while(s1[temp]!='\0'&& s2[j]!='\0'&& s1[temp]==s2[j]){
			temp++;
			j++;
		}
		if(s2[j]=='\0'){
			return 1;//è sottostringa
		}
		i++;
	}
return 0;//non è sottostringa
}

