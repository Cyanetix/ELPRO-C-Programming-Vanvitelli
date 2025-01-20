/*
Copia di un array dinamico
Obiettivo: Creare una funzione int* copy_array(int *src, int size) che copia un array dinamico.
"	Input: Array sorgente e sua dimensione.
"	Output: Nuovo array copiato.
"	Test: Copiare un array di esempio e verificare l'uguaglianza.
*/
#include <stdlib.h>
#include <stdio.h>
//funzione che copia array dinamico
int *copy_array(int* src, int size){
	//src array sorgente //size dimensione array
	
	//creazione array dinamico della stessa dimensione dell'originale
	int *copy = malloc(size*sizeof(int));
	if(copy==NULL) return NULL;
	
	//copia elementi originale in copia
	for(int i=0;i<size;i++){
		copy[i]=src[i];
	}
	
	return copy;
}

void printArray(int* arr,int size){
	printf("[");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("]\n");
}
int main(){
	//Esercizio 5
	int arr[]={5,4,3,2,1,0};
	int *copied = copy_array(arr,6);
	if(copied==NULL){
		perror("Errore nel copiare array");
		return -1;
	}
	
	printf("Array originale:\n");
	printArray(arr,6);
	
	printf("\nCopia array:\n");
	printArray(copied,6);
	
	
	free(copied);
	
	return 0;
}
