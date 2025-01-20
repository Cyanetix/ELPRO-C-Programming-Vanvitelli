/*
Creazione di una lista concatenata
Obiettivo: Definire una struttura Node e creare una lista con 3 elementi.

Copy
typedef struct Node {
    int data;
    struct Node *next;
} Node;
"	Steps:
1.	Allocare i nodi uno per uno.
2.	Collegarli manualmente (es. 10 -> 20 -> 30).
3.	Stampare la lista.
4.	Deallocare tutta la memoria.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

int main(){
	//allcazione di 3 nodi
	Node *first = malloc(sizeof(Node));
	Node *second= malloc(sizeof(Node));
	Node *third= malloc(sizeof(Node));
	
	if(!first || !second || !third){
		perror("Errore in allocazione nodi");
		return -1;
	}
	
	//collego i nodi manualmente
	first->data=10;
	first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

	//stampa lista concatenata
	Node *current = first;
	while(current!=NULL){
		printf("%d",current->data);
		if(current->next!=NULL){
            printf(" -> ");//stampo freccia solo se c'è un nodo successivo
        }
		//passo al nodo successivo
		current = current->next;
	}
	printf("\n");
	
	//deallocazione della memoria
    free(first);
    free(second);
    free(third);	
	return 0;
}
