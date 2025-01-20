/*
Calcolo della media di numeri inseriti dall'utente 
o Obiettivo: Calcolare la media di una serie di numeri inseriti dall'utente fino a quando 
non viene inserito lo 0. 
o Compiti:  
? Leggere i numeri inseriti dall'utente. 
? Sommare i numeri inseriti fino a che non viene inserito lo 0. 
? Calcolare la media dei numeri inseriti. 
? Stampare la media. 
*/
#include<stdio.h>
int main(){
	int somma=0;
	int count=0;
	float media=0;
	int n;
	printf("Inserisci numeri interi (0 per terminare):\n");
	do{
		printf("Inserisci un numero: ");
		scanf("%d",&n);
		if(n!=0){
			somma = somma+n;
			count++;
		}
	}while(n!=0);
	
	if(count>0){
		media = (float)somma/count;	
		printf("La media dei numeri inseriti e': %.2f\n",media);
	}else{
		printf("\nNon sono stati inseriti numeri validi\n");
	}
	
return 0;	
}
