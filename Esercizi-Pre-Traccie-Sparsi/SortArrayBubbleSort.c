/*
Ordinamento di un vettore con bubble sort 
o Obiettivo: Ordinare un vettore di interi usando l'algoritmo bubble sort. 
o Compiti:
? Leggere la dimensione del vettore dall'utente. 
? Leggere gli elementi del vettore dall'utente. 
? Ordinare il vettore in ordine crescente utilizzando il bubble sort. 
? Stampare il vettore ordinato.
*/
#include <stdio.h>
#define NMAX 100
void readVet(int v[],int dim);
void printVet(int v[],int dim);
void bubbleSort(int v[],int dim);
void swapElements(int v[],int index1,int index2);

int main(){
	int v[NMAX];
	int dim;
	
	do{
		//lettura dimensione da utente rispettando precondizioni
		printf("\nInserisci una dimensione per il vettore, che non superi %d:",NMAX);
		scanf("%d",&dim);
		if(dim>=NMAX || dim<=0){
			printf("\nHai inserito una dimensione errata, inseriscine una positiva e minore di %d\n",NMAX);
		}
	}while(dim>=NMAX || dim<=0);
	
	//lettura elementi vettore da utente
	readVet(v,dim);
	
	//stampa elementi vettore
	printf("\nVettore:\n");
	printVet(v,dim);
	printf("\n");
	
	bubbleSort(v,dim);
	//stampa elementi vettore
	printf("\nVettore Ordinato BubbleSort:\n");
	printVet(v,dim);
	printf("\n");
	
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

void bubbleSort(int v[],int dim){
	for(int i=0;i<dim-1;i++){
		for(int j=0;j<dim-1-i;j++){
			if(v[j]>v[j+1]){
				//scambio
				swapElements(v,j,j+1);
			}
		}
	}
}

void swapElements(int v[],int index1,int index2){
	int temp = v[index1];
	v[index1] = v[index2];
	v[index2] = temp;
}
