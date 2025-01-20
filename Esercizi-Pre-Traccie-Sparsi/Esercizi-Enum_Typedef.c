/*
Enum e Typedef Esercizi
Esercizio 1: Creazione di un Tipo Enumerato Semplice
Obiettivo: Creare un tipo enumerato per i giorni della settimana e stamparli.
Istruzioni:
Usa typedef per creare un tipo Giorni.
Definisci un enum con i giorni della settimana: LUN, MAR, MER, GIO, VEN, SAB, DOM.
Crea una variabile di tipo Giorni e stampa il giorno corrispondente.

Esercizio 2: Assegnazione Esplicita di Valori
Obiettivo: Assegnare valori espliciti a un enum e stamparli.
Istruzioni:
Crea un tipo Mesi con typedef e enum.
Assegna valori espliciti: GEN=1, FEB=2, ..., DIC=12.
Stampa il valore di un mese a scelta.

Esercizio 3: Uso di typedef e enum con Funzioni
Obiettivo: Creare una funzione che accetta un tipo enumerato e restituisce una stringa.
Istruzioni:
Definisci un tipo Stato con typedef e enum: ACCESO, SPENTO, IN_ATTESA.
Scrivi una funzione stampaStato che prende un parametro di tipo Stato e stampa una stringa descrittiva.
Usa la funzione nel main.

Esercizio 4: Creazione di un Tipo Complesso
Obiettivo: Creare un tipo Data che combina enum e struct.
Istruzioni:
Definisci un tipo Mese con typedef e enum (es. GEN=1, FEB=2, ..., DIC=12).
Crea una struct chiamata Data con campi: int giorno, Mese mese, int anno.
Usa typedef per creare un alias Data per la struct.
Crea una variabile di tipo Data e stampala.
*/
#include <stdio.h>
typedef enum {LUN, MAR, MER, GIO, VEN, SAB, DOM} Giorni;

typedef enum{ACCESO, SPENTO, IN_ATTESA}Stato;

void stampaStato(Stato temp){
	switch (temp) {
        case ACCESO: printf("Lo stato e' ACCESO\n"); break;
        case SPENTO: printf("Lo stato e' SPENTO\n"); break;
        case IN_ATTESA: printf("Lo stato e' IN ATTESA\n"); break;
        default: printf("Stato non valido\n");
    }
}
typedef enum{GEN=1, FEB, MAZ, APR, MAG, GIU, LUG, AGO, SET, OTT, NOV, DIC}Mesi;
typedef struct{
	int giorno;
	Mesi mese;
	int anno;
}Data;

int main(){
	Giorni oggi = GIO;
	printf("Oggi e' il giorno numero %d della settimana",oggi);//Output: 3
	
	Mesi mese = APR;
	printf("\nIl mese corrente e' il numero: %d\n", mese); // Output: 11
	
	Stato s = ACCESO;
    stampaStato(s); // Output: Lo stato è ACCESO
	
	Data date={30,FEB,2025};
	printf("Oggi e' il %d/%d/%d",date.giorno,date.mese,date.anno);// Output: 30/02/2025
	
	return 0;
}
