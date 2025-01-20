#include <stdio.h>
int main(){
	
	/*
	Giorno della settimana
	Scrivi un programma che chieda all'utente di inserire un numero da 1 a 7, 
	e usi uno switch per stampare il giorno della settimana corrispondente.
    Esempio di input: 3
    Esempio di output: Mercoledì
    Se il numero non è tra 1 e 7, stampa "Numero non valido"
	*/
	int num;
	printf("Inserisci un numero da 1 a 7:");
	scanf("%d",&num);
	printf("\n");
	switch(num){
		case 1:
			printf("*Lunedi*\n");
			break;
		case 2:
			printf("*Martedi*\n");
			break;
		case 3:
			printf("*Mercoledi*\n");
			break;
		case 4:
			printf("*Giovedi*\n");
			break;
		case 5:
			printf("*Venerdi*\n");
			break;
		case 6:
			printf("*Sabato*\n");
			break;
		case 7:
			printf("*Domenica*\n");
			break;
		default:
			printf("*Numero non valido*\n");
			break;
	}
	
	return 0;
}



	/*
	Chiedere all'utente di inserire un numero.
	Controllare il valore inserito utilizzando una struttura di selezione multipla.
	Associare a ciascun valore compreso tra 0 e 5 una stampa del numero in lettere.
	Gestire i valori non compresi nell'intervallo con un messaggio predefinito.
	*/
	/*
	int num;
	printf("Inserisci un numero:");
	scanf("%d",&num);
	printf("\n");
	
	switch(num){
		case 0: 
			printf("zero");
			break;
		case 1:
			printf("uno");
			break;
		case 2: 
			printf("due");
			break;
		case 3:
			printf("tre");
			break;
		case 4:
			printf("quattro");
			break;
		case 5:
			printf("cinque");
			break;
		default: printf("non compreso");
	}
	*/
	
		/*
	Chiedere all'utente di inserire un carattere.
	Leggere il carattere inserito.
	Utilizzare una selezione multipla per distinguere tra cifre pari, dispari o altre.
	Stampare un messaggio appropriato in base alla categoria del carattere.
	*/
	/*
	char c;
	printf("Inserisci carattere:");
	scanf("%c",&c);
	switch(c){
		case '2':
		case '4':
		case '6':
			printf("Pari\n");
			break;
		case '1':
		case '3':
		case '5':
			printf("Dispari\n");
			break;	
		default:
			printf("altro");
			break;
	}
	*/
