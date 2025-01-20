/*
Ricerca dell'ultima occorrenza di un elemento in un vettore e inversione 
o Obiettivo: Trovare l'ultima posizione di un elemento specificato in un vettore di interi e 
invertire il vettore. 
o Compiti:  
? Leggere la dimensione del vettore dall'utente. 
? Leggere gli elementi del vettore dall'utente. 
? Invertire l'ordine degli elementi del vettore. 
? Stampare il vettore invertito.
*/
#include<stdio.h>
#define NMAX 100
void readVet(int v[],int dim);
void printVet(int v[],int dim);
int lastOccurrence(int v[],int dim,int toFind);
void reverseVet(int v[], int dim);
int main(){
	int v[NMAX];
	int dim;
	int toFind;
	int pos;
	do{
		//lettura dimensione da utente rispettando precondizioni
		printf("\nInserisci una dimensione per il vettore, che non superi %d:",NMAX);
		scanf("%d",&dim);
		if(dim>NMAX || dim<=0){
			printf("\nHai inserito una dimensione errata, inseriscine una positiva e minore di %d\n",NMAX);
		}
	}while(dim>NMAX || dim<=0);
	
	//lettura elementi vettore da utente
	readVet(v,dim);
	
	//lettura elemento da cercare da utente
	printf("Inserisci l'elemento da cercare:\n");
	scanf("%d",&toFind);

	//stampa elementi vettore
	printf("\nVettore:\n");
	printVet(v,dim);
	printf("\n");
	//trovo ultima occorrenza nel vettore
	pos=lastOccurrence(v,dim,toFind);
	//Stampa occorenza se c'è
	if(pos!=-1){
		printf("\nL'ultima occorrenza dell'elemento %d si trova in posizione %d",toFind,pos);
	}else{
		printf("\nL'elemento %d non e' presente nel vettore",toFind);
	}
	printf("\n");
	//inverto vettore
	reverseVet(v,dim);
	//stampo elementi vettore invertito
	printf("\nVettore invertito:\n");
	printVet(v,dim);
return 0;
}

void readVet(int v[],int dim){
	for(int i=0;i<dim;i++){
		printf("Inserisci elemento %d:\n",i);
		scanf("%d",&v[i]);
	}
}

void printVet(int v[],int dim){
	printf("[ ");
	for(int i=0;i<dim;i++){
		printf("%d ",v[i]);
	}
	printf("]");
}

int lastOccurrence(int v[],int dim,int toFind){
	int i=dim-1;
	do{
		if(v[i]==toFind){
			return i;
		}
		i--;
	}while(i>=0);
return -1;
}

void reverseVet(int v[], int dim){
	int temp;
	for(int i=0;i<dim/2;i++){
		temp=v[i];
		v[i]=v[dim-1-i];
		v[dim-1-i] = temp;
	}
}
