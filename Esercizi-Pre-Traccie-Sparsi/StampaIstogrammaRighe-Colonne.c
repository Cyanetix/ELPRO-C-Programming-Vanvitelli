/*
Traccia d'esame: Stampa di un istogramma a colonne 
o Obiettivo: Stampare a console un istogramma a colonne, i cui valori sono contenuti in 
un vettore di interi. 
o Compiti: 
o Leggere un vettore di interi. 
o Stampare l'istogramma a colonne. 
o Visualizzare i valori in cima alle colonne.
*/
#include <stdio.h>
#define NMAX 100
void readVet(int v[],int dim);
void printVet(int v[],int dim);
void printHistogramCols(int v[],int dim);
void printHistogramRows(int v[],int dim);
int maxVet(int v[],int dim);

int main(){
	int v[NMAX];
	int dim;
	do{
		//lettura dimensione da utente rispettando precondizioni
		printf("Inserisci il numero degli elementi che vuoi inserire( < %d):",NMAX);
		scanf("%d",&dim);
		printf("\n");
		if(dim>NMAX || dim<=0){
			printf("\nHai inserito una dimensione errata, inseriscine una positiva e minore di %d\n",NMAX);
		}
	}while(dim>=NMAX || dim<=0);

	//lettura elementi array di interi
	printf("Inserimento elementi array:\n");
	readVet(v,dim);
	
	printf("\n\n");
	printf("Vettore:\n");
	//stampa elementi vettore
	printVet(v,dim);
	
	printf("\n\n");
	printf("Istogramma a colonne:\n");
	//stampa istogramma a colonne
	printHistogramCols(v,dim);
	
	printf("\n\n");
    printf("Istogramma a righe:\n");
    //stampa istogramma a righe
    printHistogramRows(v, dim);
    
return 0;
}
void readVet(int v[],int dim) {
    for(int i=0;i<dim;i++){
        do{
            printf("\nInserisci elemento %d (positivo):",i);
            scanf("%d",&v[i]);
            if(v[i]<0){
                printf("Errore: inserire un valore positivo.\n");
            }
        }while(v[i] < 0);//Impedisco inserimento valori negativi
    }
}

void printVet(int v[],int dim){
	printf("[ ");
	for(int i=0;i<dim;i++){
		printf("%d ",v[i]);
	}
	printf("]\n");
}
int maxVet(int v[],int dim){
	int max=v[0];
	for(int i=1;i<dim;i++){
		if(max<v[i]){
			//aggiorno max
			max=v[i];
		}
	}
return max;	
}

void printHistogramRows(int v[],int dim){
	//ciclo esterno itera sugli elementi del vettore
	for(int i=0;i<dim;i++){
		//stampo valore elemento corrente
		printf("%3d: ",v[i]);
		
		//ciclo interno che stampa tanti asterischi quanto il valore corrente
		for(int j=0;j<v[i];j++){
			printf("*");
		}
		printf("\n");	
	}
}

void printHistogramCols(int v[],int dim){
	int numRighe = maxVet(v,dim);
	
    //Stampa numeri sopra le colonne
    for(int j=0;j<dim;j++){
        printf("%4d",v[j]);
    }
    printf("\n");
	
	//ciclo esterno per iterare su tutte le righe per segnare l'istogramma
	for(int i=numRighe;i>0;i--){
		//ciclo interno per iterare i singoli elementi del vettore
		for(int j=0;j<dim;j++){
			
			if(v[j]<i){
				printf("    ");
			}else{
				printf("   *");
			}
			/* 
			se il valore dell'elemento del vettore è minore 
			della riga in cui siamo allora stampo spazio, 
			altrimenti stampoasterisco
			*/
		}
		printf("\n");
	}
}

