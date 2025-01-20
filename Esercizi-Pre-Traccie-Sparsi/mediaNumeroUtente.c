/*
Calcolo della media di n numeri 
o Obiettivo: Calcolare la media di n numeri, con n scelto dall'utente. 
o Compiti:  
? Leggere il numero n dall'utente. 
? Leggere n numeri dall'utente. 
? Calcolare la media dei numeri inseriti. 
? Stampare la media.
*/
#include<stdio.h>
int main(){
	int somma=0;
	float media=0;
	int Nmax=0;
	int n;
	printf("Inserisci il numero di inserimenti che si intende effettuare:\n");
	scanf("%d",&Nmax);
	//se Nmax risulta 0 o negativo non è un valore valido quindi richiedo l'inserimento
	while(Nmax<=0){
		printf("Hai inserito un valore non valido, inseriscine uno positivo(>0):\n");
		scanf("%d",&Nmax);
	}
	
	for(int i=0;i<Nmax;i++){
		printf("Inserisci un numero: ");
		scanf("%d",&n);
		somma = somma+n;
	}	
	media = (float)somma/Nmax;	
	printf("La media dei numeri inseriti e': %.2f\n",media);
return 0;
}
