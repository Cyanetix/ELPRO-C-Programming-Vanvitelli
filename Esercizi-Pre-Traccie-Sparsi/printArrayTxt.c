/*
Stampa di una matrice con asterischi in posizioni specifiche (file di
testo)
o Obiettivo: Leggere da un file di testo le dimensioni di una matrice e le posizioni dove
stampare un asterisco, visualizzando la matrice.
o Compiti:
? Leggere dal file "sm.txt" le dimensioni della matrice (r, c) e le coppie di indici (l,
k).
? Stampare una matrice di caratteri dove le posizioni indicate nel file di testo
contengono un asterisco ('*') e le altre posizioni contengono uno spazio vuoto (' ').
*/
#include <stdio.h>
/*
    #include <stdio.h>
    // Questa linea include la libreria standard di input/output (stdio.h) in C.
    // Questa libreria fornisce funzioni per operazioni di input e output,
    // come la lettura da tastiera, la scrittura su schermo e, in questo caso,
    // la gestione dei file. Tra le funzioni utili per i file di testo fornite da stdio.h troviamo:
    // - fopen: Apre un file.
    // - fclose: Chiude un file.
    // - fprintf: Scrive dati formattati su un file (come printf, ma su file).
    // - fscanf: Legge dati formattati da un file (come scanf, ma da file).
    // - fgets: Legge una riga di testo da un file.
    // - fputs: Scrive una stringa di testo su un file.
    // - fgetc: Legge un singolo carattere da un file.
    // - fputc: Scrive un singolo carattere su un file.
*/
int main(){

    /*
        int main(){
        // La funzione main() è il punto di ingresso principale di ogni programma C.
        // L'esecuzione del programma inizia da questa funzione.
        // 'int' indica che la funzione main restituisce un valore intero al sistema operativo
        // al termine dell'esecuzione. Convenzionalmente, restituire 0 indica che il programma
        // è stato eseguito con successo, mentre un valore diverso da zero indica un errore.
    */
	int v[]={3,6,7,8,21,4};
    /*
        int v[]={3,6,7,8,21,4};
        // Dichiarazione e inizializzazione di un array di interi di nome 'v'.
        // Questo array contiene i numeri che verranno scritti nel file di testo.
    */
	//stampa vettore su file di testo
	FILE *fp;
    /*
        FILE *fp;
        // Dichiarazione di un puntatore a FILE. 'FILE' è un tipo di dato definito in stdio.h che rappresenta un flusso di file.
        // 'fp' è una variabile puntatore che conterrà l'indirizzo della struttura FILE che verrà creata da 'fopen'.
        // Questo puntatore è necessario per operare sul file (leggere, scrivere, chiudere).
    */
	char filename[]="fileVet.txt";
    /*
        char filename[]="fileVet.txt";
        // Dichiarazione di un array di caratteri (stringa) di nome 'filename' e inizializzazione con il valore "fileVet.txt".
        // Questo array contiene il nome del file di testo che verrà creato o aperto.

        // File di Testo: Nozioni Teoriche
        // I file di testo sono file che contengono dati rappresentati come sequenze di caratteri.
        // Questi caratteri sono tipicamente codificati usando standard come ASCII o UTF-8, che permettono
        // la rappresentazione di lettere, numeri, simboli di punteggiatura e altri caratteri leggibili dagli umani.
        // Caratteristiche principali dei file di testo:
        // 1. Leggibilità Umana: Progettati per essere facilmente letti e compresi da persone utilizzando editor di testo.
        // 2. Struttura Lineare: Organizzati in righe, separate da caratteri di newline ('\n').
        // 3. Portabilità: Generalmente portabili tra diversi sistemi operativi e applicazioni, grazie agli standard di codifica.
        // 4. Meno Efficienti per Dati Strutturati: Meno efficienti dei file binari per salvare dati numerici o strutture complesse,
        //    poiché i numeri e le strutture devono essere convertiti in rappresentazioni testuali (stringhe).
        // 5. Utilizzo: Ideali per file di configurazione, log, documenti di testo, dati tabulari semplici (CSV, TSV) e qualsiasi dato
        //    che debba essere facilmente ispezionabile e modificabile da un utente umano.

        // Differenza tra File di Testo e File Binari:
        // - File di Testo: Contengono dati formattati come testo leggibile. Ogni byte (o sequenza di byte in codifiche multibyte come UTF-8)
        //   rappresenta un carattere. Le funzioni di I/O per file di testo (come fprintf, fscanf, fgets, fputs) si occupano della
        //   conversione tra la rappresentazione interna dei dati (numeri, stringhe) e la loro forma testuale.
        // - File Binari: Contengono dati in forma grezza, così come sono memorizzati in memoria dal computer. Non c'è conversione di formato.
        //   Le funzioni di I/O per file binari (come fread, fwrite) leggono e scrivono blocchi di byte direttamente dalla memoria al file e viceversa.
        //   I file binari sono più efficienti per salvare dati strutturati e numerici, ma non sono direttamente leggibili o modificabili con editor di testo standard.
    */
	int numElementi;
    /*
        int numElementi;
        // Dichiarazione di una variabile intera di nome 'numElementi'.
        // Questa variabile verrà utilizzata per memorizzare il numero di elementi presenti nell'array 'v'.
    */

	fp = fopen(filename,"w");
    /*
        fp = fopen(filename,"w");
        // 'fopen()' è una funzione che apre un file. In questo caso, apre il file il cui nome è contenuto nella variabile 'filename' ("fileVet.txt").
        // La modalità di apertura è "w", che sta per "write" (scrittura) in modalità testo.

        // Modalità di Apertura File di Testo (e loro implicazioni):
        // Le modalità di apertura specificano come il file verrà utilizzato (lettura, scrittura, append) e se il file è trattato come testo o binario.
        // Per i file di testo, le modalità principali sono:
        // - "r":  Lettura (read). Apre il file solo per la lettura.
        //   - Il file deve esistere, altrimenti fopen fallisce e restituisce NULL.
        //   - La posizione di inizio lettura è all'inizio del file.
        // - "w":  Scrittura (write). Apre il file per la scrittura.
        //   - Se il file non esiste, viene creato.
        //   - Se il file esiste, il suo contenuto viene troncato (cancellato) e sovrascritto.
        //   - La posizione di inizio scrittura è all'inizio del file.
        // - "a":  Append (aggiunta). Apre il file per la scrittura in modalità append (aggiunta alla fine).
        //   - Se il file non esiste, viene creato.
        //   - Se il file esiste, la scrittura inizia alla fine del file, preservando il contenuto esistente.
        //   - Utile per aggiungere dati a un file di log o registrazioni senza sovrascrivere i dati precedenti.
        // - "r+": Lettura e Scrittura (read and write). Apre il file per lettura e scrittura.
        //   - Il file deve esistere, altrimenti fopen fallisce.
        //   - La posizione di inizio è all'inizio del file.
        //   - Permette sia leggere che scrivere nel file aperto. Attenzione alla posizione corrente del file dopo operazioni di lettura/scrittura.
        // - "w+": Lettura e Scrittura (write and read). Apre il file per lettura e scrittura, troncando il file o creandolo.
        //   - Se il file non esiste, viene creato.
        //   - Se il file esiste, il suo contenuto viene troncato (cancellato) e sovrascritto.
        //   - Simile a "w" per la scrittura iniziale, ma permette anche la lettura dal file.
        // - "a+": Lettura e Append (append and read). Apre il file per lettura e scrittura in modalità append.
        //   - Se il file non esiste, viene creato.
        //   - La scrittura avviene sempre alla fine del file. La lettura può avvenire da qualsiasi punto del file.
        //   - Utile per leggere un file e aggiungere dati alla fine.

        // Per tutti questi modi testuali, è possibile aggiungere 'b' (es. "rb", "wb", "ab", "r+b", "w+b", "a+b") per specificare la modalità binaria.
        // In modalità binaria, la gestione dei caratteri di newline e la conversione di formato sono diverse rispetto alla modalità testo.

        // La funzione 'fopen()' restituisce un puntatore a FILE se l'apertura ha successo, altrimenti restituisce NULL in caso di errore.
        // È importante controllare sempre il valore restituito da 'fopen()' per verificare se l'apertura del file è andata a buon fine.
    */

	if(fp==NULL){
        /*
            if(fp==NULL){
            // Verifica se il puntatore al file 'fp' è NULL.
            // Se 'fp' è NULL, significa che 'fopen()' ha fallito nell'apertura del file per qualche motivo (es., file non trovato, permessi insufficienti).
        */
		printf("Errore apertura %s",filename);
        /*
            printf("Errore apertura %s",filename);
            // Stampa un messaggio di errore a video, indicando che c'è stato un problema nell'apertura del file.
            // '%s' è uno specificatore di formato che viene sostituito con il valore della stringa 'filename'.
        */
		return -1;
        /*
            return -1;
            // 'return -1;' termina la funzione 'main()' e restituisce il valore -1 al sistema operativo.
            // In C, convenzionalmente, un valore di ritorno diverso da 0 da 'main()' indica che il programma è terminato con un errore.
        */
	}


	numElementi = sizeof(v)/sizeof(int);
    /*
        numElementi = sizeof(v)/sizeof(int);
        // Calcola il numero di elementi presenti nell'array 'v'.
        // 'sizeof(v)' restituisce la dimensione totale in byte dell'array 'v'.
        // 'sizeof(int)' restituisce la dimensione in byte di un singolo intero.
        // Dividendo la dimensione totale dell'array per la dimensione di un singolo elemento, si ottiene il numero di elementi.
    */
	for(int i=0;i<numElementi;i++){
        /*
            for(int i=0;i<numElementi;i++){
            // Inizio di un ciclo 'for' che itera su tutti gli elementi dell'array 'v'.
            // La variabile 'i' viene inizializzata a 0 e incrementata di 1 ad ogni iterazione, fino a quando 'i' è minore di 'numElementi'.
        */
		fprintf(fp,"%d ",v[i]);
		
	}
        /*
            fprintf(fp,"%d ",v[i]);
            // 'fprintf()' è una funzione utilizzata per scrivere dati formattati su un file di testo.
            // È l'equivalente per i file di testo della funzione 'printf()' che stampa a video.
            // Sintassi di fprintf: fprintf(file_pointer, format_string, arguments...);
            // - 'fp': è il file pointer, indica il file di testo su cui scrivere (ottenuto da 'fopen').
            // - '"%d "': è la stringa di formato, che specifica come i dati devono essere formattati per la scrittura.
            //   '%d' è uno specificatore di formato per stampare un intero decimale con segno.
            //   ' ' (spazio) dopo '%d' aggiunge uno spazio dopo ogni numero scritto nel file, rendendoli separati e più leggibili.
            // - 'v[i]': è l'argomento da formattare e scrivere. In questo caso, è l'elemento corrente dell'array 'v' (un intero).

            // Altre Opzioni per la Scrittura di File di Testo:
            // 1. fputs(const char *str, FILE *stream): Scrive una stringa su un file.
            //    - 'str': Puntatore alla stringa da scrivere.
            //    - 'stream': Puntatore al file (FILE *).
            //    - Scrive la stringa *senza* aggiungere automaticamente un carattere di newline alla fine.
            //    - Restituisce un valore non negativo in caso di successo, EOF in caso di errore.
            //    Esempio: fputs("Questa è una riga di testo.\n", fp);

            // 2. fputc(int char, FILE *stream): Scrive un singolo carattere su un file.
            //    - 'char': Il carattere da scrivere (promosso a int).
            //    - 'stream': Puntatore al file (FILE *).
            //    - Scrive un singolo carattere alla volta. Utile per la scrittura carattere per carattere o in cicli.
            //    - Restituisce il carattere scritto in caso di successo, EOF in caso di errore.
            //    Esempio: fputc('A', fp);

            // Scelta tra fprintf, fputs e fputc:
            // - fprintf: Più versatile per la scrittura formattata di dati misti (stringhe, numeri, ecc.) e per controllare il formato di output.
            // - fputs: Ottimale per scrivere stringhe intere, specialmente se si hanno già stringhe pronte da scrivere. Più semplice e potenzialmente più efficiente di fprintf per stringhe pure.
            // - fputc: Utile quando si deve scrivere carattere per carattere, ad esempio in elaborazioni di testo a basso livello o quando si controlla ogni singolo carattere scritto.
        }
        // Fine del ciclo 'for'. Dopo ogni iterazione, il prossimo elemento dell'array 'v' viene scritto nel file.
    */

	fclose(fp);
    /*
        fclose(fp);
        // 'fclose()' è una funzione che chiude un file precedentemente aperto con 'fopen()'.
        // È fondamentale chiudere sempre i file dopo aver terminato di operarvi, sia in scrittura che in lettura.
        // Chiusura del file:
        // - Libera le risorse di sistema associate al file, rendendole disponibili per altri usi.
        // - Assicura che tutti i dati in buffer (specialmente in scrittura) vengano effettivamente scritti su disco.
        // - Aggiorna le informazioni del file (data di ultima modifica, ecc.).
        // Mancare di chiudere un file può causare perdita di dati, corruzione del file o altri problemi.
    */
	printf("Vettore scritto correttamente nel file di testo %s\n", filename);
    /*
        printf("Vettore scritto correttamente nel file di testo %s\n", filename);
        // Stampa un messaggio di successo a video, indicando che il vettore è stato scritto correttamente nel file di testo.
        // '%s' è uno specificatore di formato che viene sostituito con il valore della stringa 'filename'.
    */
	return 0;
    /*
        return 0;
        // 'return 0;' indica che la funzione 'main()' termina la sua esecuzione e restituisce il valore 0 al sistema operativo.
        // In C, convenzionalmente, un valore di ritorno 0 da 'main()' indica che il programma è terminato con successo.
    */
}
