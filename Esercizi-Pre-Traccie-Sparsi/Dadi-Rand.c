/*
Consegna dell'Esercizio
Titolo: Simulazione di un Gioco di Dadi
Descrizione:
Devi creare un programma in C che simuli il lancio di due dadi per due giocatori. Il programma dovrà:

Generare un numero casuale tra 1 e 6 per ciascun dado (simulando il lancio).

Assegnare i risultati ai due giocatori.

Determinare il vincitore in base alla somma dei valori dei dadi.

Gestire il caso di pareggio.

Utilizzare srand() per garantire che i numeri casuali siano diversi ogni volta che il programma viene eseguito.

Dettagli:
Il programma deve chiedere all'utente i nomi dei due giocatori.

Utilizzare rand() per generare i numeri casuali.

Utilizzare srand() con un seed basato sul tempo corrente (time(NULL)) per garantire casualità.

Stampare i risultati di ciascun lancio e dichiarare il vincitore.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMAX 20
int main(){
	srand(time(NULL));//inizializzo seed
	char name1[NMAX];
	char name2[NMAX];
	
	//lettura nomi
	printf("Inserisci il nome del Giocatore 1:");
	scanf("%s",name1);
	printf("Inserisci il nome del Giocatore 2:");
	scanf("%s",name2);
	
	//Lancio dei due dadi per ciascuno
	int dado1_1 = rand() % 6 + 1;
	int dado1_2 = rand() % 6 + 1;
	
	int dado2_1 = rand() % 6 + 1;
	int dado2_2 = rand() % 6 + 1;
	
	//totale punteggio
	int tot1 = dado1_1 + dado1_2;
	int tot2 = dado2_1 + dado2_2;
	
	//Output risultati
    printf("\nLancio dei dadi:\n");
    printf("- %s ha lanciato un %d e un %d (Totale: %d)\n", name1, dado1_1, dado1_2, tot1);
    printf("- %s ha lanciato un %d e un %d (Totale: %d)\n", name2, dado2_1, dado2_2, tot2);
	
	if(tot1>tot2){
		printf("\nRisultato: %s vince!\n", name1);
	}else if(tot2>tot1){
		printf("\nRisultato: %s vince!\n", name2);
	}else{
		printf("\nRisultato: Pareggio!\n");
	}
	
	return 0;
}
