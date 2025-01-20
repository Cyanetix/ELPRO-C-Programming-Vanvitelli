/*
Calcolo del Massimo Comun Divisore (MCD) 
o Obiettivo: Calcolare il Massimo Comun Divisore tra due numeri interi positivi inseriti 
dall'utente. 
o Compiti:  
? Leggere due numeri interi positivi dall'utente. 
? Implementare l'algoritmo di Euclide per calcolare il MCD. 
? Gestire il caso in cui l'input non rispetti le precondizioni (a, b > 0). 
? Stampare il risultato.
*/
#include <stdio.h>
int calcoloMCD(int a,int b);
int main(){
	int a,b,mcd;
	do{
		printf("Inserisci il primo numero:");
		scanf("%d",&a);
		printf("Inserisci il secondo numero:");
		scanf("%d",&b);
		if(a<=0 || b<=0){
			printf("\nDevi inserire due numeri positivi!\n");
		}
	}while(a<=0 || b<=0);
	mcd = calcoloMCD(a,b);
	printf("MCD(%d,%d)=%d",a,b,mcd);
return 0;
}

int calcoloMCD(int a,int b){
	int temp,r;
	//algoritmo di Euclide per calcolo MCD
	if(b>a){
		//se b è maggiore di a, scambio a con b
		temp=a;
		a=b;
		b=temp;
	}
	
	while(b!=0){
		//calcolo resto divisione tra a e b
		r=a%b;
		//assegno ad 'a' il valore di 'b'
		a=b;
		//assegno a 'b' il valore del resto 'r'
		b=r;
	}
return a;
}
