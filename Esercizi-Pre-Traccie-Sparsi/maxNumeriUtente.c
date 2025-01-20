/*
 Calcolo del massimo di n numeri 
o Obiettivo: Calcolare il massimo di n numeri con n scelto dall'utente 
o Compiti:  
? Leggere il numero n dall'utente. 
? Leggere n numeri dall'utente. 
? Calcolare il massimo dei numeri inseriti. 
? Stampare il massimo.
*/
#include<stdio.h>
#define NMAX 100
void readVet(int v[],int dim);
void printVet(int v[],int dim);
int findMaxVet(int v[],int dim);
int main(){
	int max=0;
	int v[NMAX];
	int dim;//numero di numeri che utente vuole inserire
	do{
		printf("Quanti numeri vuoi inserire? (<%d)\n",NMAX);
		scanf("%d",&dim);
		if(dim>=NMAX || dim<=0){
			printf("\nHai inserito un valore superiore a %d o negativo, inserisci un numero positivo inferiore a %d\n\n",NMAX,NMAX);
		}
	}while(dim>=NMAX || dim<=0);
	readVet(v,dim);
	printf("\nI numeri inseriti dall'utente sono:\n");
	printVet(v,dim);
	printf("\n");
	max=findMaxVet(v,dim);
	printf("Il massimo tra questi e' %d",max);
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

int findMaxVet(int v[],int dim){
	int max=v[0];//il max iniziale è il primo
	for(int i=1;i<dim;i++){
		if(max<v[i]){
			max=v[i];//se trovo un elemento per il quale il max è minore di questo elemento, aggiorno il max
		}
	}
	return max;
}
