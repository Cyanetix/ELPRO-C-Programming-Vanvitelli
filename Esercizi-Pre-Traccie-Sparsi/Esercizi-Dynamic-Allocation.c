/*
Allocazione di un singolo intero
Obiettivo: Allocare memoria per un singolo intero, assegnargli un valore, stamparlo e deallocare.
"	Steps:
1.	Usa malloc per allocare spazio per un int.
2.	Assegna un valore (es. 42).
3.	Stampa il valore.
4.	Dealloca la memoria con free.
*/
#include <stdlib.h>
#include <stdio.h>
int main(){
	/*
	//Esercizio 1
	//alloco blocco di memoria per un intero
	int *ptr=malloc(sizeof(int));
	if(ptr==NULL){
		printf("errore allocazione");
		return -1;
	}
	*ptr = 67;
	printf("Stampa valore intero: %d\n",*ptr);
	printf("Stampa indirizzo del valore intero: %p",ptr);
	free(ptr);
	*/
	
	/*
	//Esercizio 2
	int dim;
	printf("Inserire dimensione array:\n");
	scanf("%d",&dim);
	
	//allcazione dinamica dell'array
	int *arr = malloc(sizeof(int)*dim);
	
	if(arr==NULL){
		printf("errore allocazione");
		return -1;		
	}
	
	//riempimento con valori crescenti da 0 a dim
	for(int i=0;i<dim;i++){
		arr[i]=i;
	}
	
	//stampa array
	printf("[");
	for(int i=0;i<dim;i++){
		printf("%d ",arr[i]);
	}
	printf("]");
	
	free(arr);
	*/
	
	/*
	//Esercizio 3
	//allocazione di array di 10 interi inizializzati a zero
	int *arr2 = calloc(10,sizeof(int));
	if(arr2==NULL){
		printf("errore allocazione array 2");
		return -1;
	}
	//modifica di un elemento
	arr2[4]=4;
	
	//stampa array
	printf("[");
	for(int i=0;i<10;i++){
		printf("%d ",arr2[i]);
	}
	printf("]\n");
	free(arr2);
	*/
	
	/*
	//Esercizio 4
	//alloco un array di 5 elementi
	int *arr3 = malloc(sizeof(int)*5);
	if(arr3==NULL){
		printf("errore allocazione array 3");		
		return -1;
	}
	
	for(int i=0;i<5;i++){
		arr3[i]=i;
	}
	
	//ridimensiono array a 10 elementi con realloc
	int *new_arr3 = realloc(arr3,10*sizeof(int));
	if(new_arr3==NULL){
		free(arr3);//libero memoria arr3
		return -1;
	}
	arr3 = new_arr3;
	for(int i=5;i<10;i++){
		arr3[i]=i;
	}
	printf("[");
	for(int i=0;i<10;i++){
		printf("%d ",arr3[i]);
	}
	printf("]\n");
	free(arr3);
	*/
	
	return 0;
}
