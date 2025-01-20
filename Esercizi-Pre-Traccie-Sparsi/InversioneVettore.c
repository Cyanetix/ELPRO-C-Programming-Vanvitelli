//Inversione di un vettore di interi
/*
Obiettivo: Inizializzare un vettore di interi chiedendo all'utente le dimensioni e gli
elementi da console.
Compiti:
	? Leggere la dimensione del vettore dall'utente.
	? Leggere gli elementi del vettore dall'utente.
	? Invertire l'ordine degli elementi del vettore.
	? Stampare il vettore originale e il vettore invertito.
*/
#include <stdio.h>
#define NMAX 100
void initVet(int v[], int dim);
void printVet(int v[], int dim);
void reverseVet(int v[], int dim);
int main(){
	int v[NMAX];
	int dim;
	printf("Inserisci la dimensione del vettore:");
	scanf("%d",&dim);
	//controllo se dimensione supera NMAX
	while(dim>NMAX){
		printf("Dimensione superiore a %d, inseriscine una inferiore o uguale:",NMAX);
		scanf("%d",&dim);
	}
	//inizializzo vettore
	initVet(v,dim);
	printf("\n*Stampa array originale*:\n");
	//stampo vettore
	printVet(v,dim);
	
	//inverto vettore
	reverseVet(v,dim);
	//stampo vettore invertito
	printf("\n\n*Stampa array invertito*:\n");
	printVet(v,dim);
	return 0;
}

void initVet(int v[], int dim){
	for(int i=0;i<dim;i++){
		printf("Inserisci elemento %d: \n",i);
		scanf("%d",&v[i]);
	}
}

void printVet(int v[], int dim){
	for(int i=0;i<dim;i++){
		printf("%d ",v[i]);
	}
}

void reverseVet(int v[], int dim){
	int temp;
	for(int i=0;i<dim/2;i++){
		temp=v[i];
		v[i]=v[dim-1-i];
		v[dim-1-i] = temp;
	}
}



