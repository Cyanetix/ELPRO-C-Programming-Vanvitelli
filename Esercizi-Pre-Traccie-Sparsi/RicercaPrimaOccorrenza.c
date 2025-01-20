/*
Ricerca della prima occorrenza di un elemento in un vettore
o Obiettivo: Trovare la prima posizione di un elemento specificato in un vettore di interi. 
o Compiti: 
? Leggere la dimensione del vettore dall'utente. 
? Leggere gli elementi del vettore dall'utente. 
? Leggere l'elemento da cercare dall'utente. 
? Trovare la prima occorrenza dell'elemento nel vettore. 
? Stampare la posizione dell'elemento o un messaggio se l'elemento non è 
presente.
*/
#include<stdio.h>
#define NMAX 100
void readVet(int v[],int dim);
void printVet(int v[],int dim);
int firstOccurrence(int v[],int dim,int toFind);
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
	printVet(v,dim);

	//trovo prima occorrenza nel vettore
	pos=firstOccurrence(v,dim,toFind);
	//Stampa occorenza se c'è
	if(pos!=-1){
		printf("\nLa prima occorrenza dell'elemento %d si trova in posizione %d",toFind,pos);
	}else{
		printf("\nL'elemento %d non e' presente nel vettore",toFind);
	}
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

/*
int firstOccurrence(int v[],int dim,int toFind){
	int i=0;
	int pos=-1;
	do{
		printf("it:%d",i);
		if(v[i]==toFind){
			pos=i;
		}
		i++;
		
	}while(pos==-1 && i<dim);
return pos;
}
*/


int firstOccurrence(int v[],int dim,int toFind){
	int i=0;
	do{
		if(v[i]==toFind){
			return i;
		}
		i++;
	}while(i<dim);
return -1;
}
