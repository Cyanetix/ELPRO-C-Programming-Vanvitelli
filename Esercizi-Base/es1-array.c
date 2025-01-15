//creazione di un array, riempiamo l'array con numeri dati dall'utente, 
#define DIM 100
#include <stdio.h>
int main(){
	int d = 0;
	int vet[DIM];
	
	printf("Quanto deve essere grande il vettore?\n");
	scanf("%d",&d);
	
	int i;
	//riempimento array
	for(i = 0; i < d; i++ ){
		printf("Inserisci l'elemento di posto %d: ",i);
		scanf("%d",&vet[i]);
		printf("\n");
	}
	
	printf("\nArray:\n");
	//stampa array
	printf("[ ");
	for(i = 0; i < d; i++ ){
		printf("%d ",vet[i]);
	}
	printf("]");
	
	//richoesta indice in cui si vuole aggiungere elemento
	int index_value_to_be_added = 0;
	printf("\nA che indice vuoi aggiungere l'elemento\n");
	scanf("%d",&index_value_to_be_added);
	
	int value_to_be_added = 0;
	printf("Che valore vuoi aggiungere?\n");
	scanf("%d",&value_to_be_added);
	printf("\n");
	
	for(i = d-1; i >= index_value_to_be_added; i--){
		vet[i+1] = vet[i];
	}
	vet[index_value_to_be_added] = value_to_be_added;
	d++;
	
	//stampa array
	printf("\nArray aumentato di un elemento\n");
	printf("[ ");
	for(i = 0; i < d; i++ ){
		printf("%d ",vet[i]);
	}
	printf("]");
	
	//eliminazione del primo elemento
	int index_to_be_removed = 0;
	printf("\nInserisci l'indice dell'elemento da rimuovere:\n");
	scanf("%d",&index_to_be_removed);
	
	for(i = index_to_be_removed; i < d; i++){
		vet[i] = vet[i+1];
	}
	d--;
	
	//stampa array
	printf("\nArray dopo eliminazione elemento\n");
	printf("[ ");
	for(i = 0; i < d; i++ ){
		printf("%d ",vet[i]);
	}
	printf("]");
	
	return 0;
}
