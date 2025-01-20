/*
Prima programma con file bin
*/
#include <stdio.h>

/*
    #include <stdio.h>
    // Questa linea include la libreria standard di input/output (stdio.h) in C.
    // Questa libreria fornisce funzioni per operazioni di input e output,
    // come la lettura da tastiera, la scrittura su schermo e, in questo caso,
    // la gestione dei file.
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

	int num_da_scrivere; // Variabile intera per memorizzare il numero inserito dall'utente da scrivere nel file.
	char filename[] = "firstFileBin.bin"; // Array di caratteri (stringa) che memorizza il nome del file binario che verrà creato o letto.
	printf("\n--Fase di scrittura su file--\n"); // Stampa un messaggio all'utente per indicare l'inizio della fase di scrittura sul file.
	printf("Inserisci il numero da scrivere su file: "); // Chiede all'utente di inserire un numero.
	scanf("%d",&num_da_scrivere); // Legge un numero intero inserito dall'utente dalla tastiera e lo memorizza nella variabile 'num_da_scrivere'.

	/*
        //prima di operare sui file è necessario aprirlo e poi quando finito ricordare di chiuderlo
        //- fopen - fclose
        // Prima di poter leggere o scrivere su un file in C, è necessario "aprirlo".
        // L'apertura di un file crea un collegamento tra il programma e il file fisico sul disco.
        // La funzione 'fopen()' è utilizzata per aprire un file.
        // Una volta terminate le operazioni sul file, è fondamentale "chiuderlo" utilizzando 'fclose()'.
        // Chiudere il file libera le risorse di sistema associate al file e garantisce che tutti i dati
        // in sospeso vengano scritti correttamente sul disco.

        //lettura e scrittura su file binario
        //- fread   - fwrite
        // Per la lettura e scrittura di dati binari (cioè i dati così come sono rappresentati in memoria,
        // senza conversione in formato testo), si utilizzano le funzioni 'fread()' e 'fwrite()'.
        // 'fwrite()' scrive blocchi di dati binari su un file.
        // 'fread()' legge blocchi di dati binari da un file.
        // Questo è diverso dalla lettura/scrittura di file di testo, dove i dati sono interpretati come caratteri.
	*/

	FILE *fp; // Dichiarazione di un puntatore a FILE. 'FILE' è un tipo di dato definito in stdio.h che rappresenta un flusso di file.
                // 'fp' è una variabile puntatore che conterrà l'indirizzo della struttura FILE che verrà creata da 'fopen'.
                // Questo puntatore è necessario per operare sul file (leggere, scrivere, chiudere).

	fp = fopen(filename,"wb"); // 'fopen()' apre il file specificato dal nome in 'filename' ("firstFileBin.bin") nella modalità "wb".
                                 // "wb" significa "write binary" (scrittura binaria). Questa modalità apre il file per la scrittura in formato binario.
                                 // Se il file non esiste, 'fopen' lo crea. Se esiste, il contenuto precedente viene sovrascritto.
                                 // 'fopen()' restituisce un puntatore al file aperto (di tipo FILE*) se l'apertura ha successo.
                                 // Se l'apertura fallisce (es. permessi insufficienti, disco pieno, file non trovato in modalità lettura),
                                 // restituisce NULL.

	/*
        //FILE *fp;//puntatore a una struttura di tipo file
        // La dichiarazione 'FILE *fp;' definisce 'fp' come un puntatore a una struttura di tipo 'FILE'.
        // In C, i file sono gestiti tramite puntatori a questa struttura.
        // La struttura 'FILE' (definita in stdio.h) contiene informazioni sullo stato del file,
        // come la posizione corrente di lettura/scrittura, i buffer, ecc.
        // Il puntatore 'fp' è ciò che si usa per interagire con il file attraverso le funzioni di I/O.

        //char filename[] = "1_filebinario.bin";//nome file binario
        // 'char filename[] = "1_filebinario.bin";' dichiara un array di caratteri 'filename' e lo inizializza
        // con la stringa "1_filebinario.bin". Questa stringa rappresenta il nome del file su cui si andrà ad operare.
        // In questo caso, si tratta di un file binario. L'estensione ".bin" è convenzionale per indicare file binari,
        // ma non è obbligatoria e non influenza il modo in cui il file viene trattato dal sistema operativo o dalle funzioni C.

        //fopen apre il file di nome specificato e
	    //restituisce la variabile puntatore (file pointer) al file di nome specificato
	    //se file non esiste la funzione fopen ritorna un file pointer NULL
	    //fopen ("nome file","modalità apertura")
        // Come già accennato, 'fopen()' è la funzione chiave per aprire i file. Prende due argomenti:
        // 1. Il nome del file (una stringa).
        // 2. La modalità di apertura (una stringa che specifica cosa si vuole fare con il file).
        //    Modalità comuni:
        //    - "r":  Lettura (read) - apre un file di testo per la lettura. Il file deve esistere.
        //    - "w":  Scrittura (write) - apre un file di testo per la scrittura. Se il file esiste, lo sovrascrive; se non esiste, lo crea.
        //    - "a":  Append (aggiunta) - apre un file di testo per la scrittura in modalità append. Scrive alla fine del file. Se il file non esiste, lo crea.
        //    - "rb": Lettura binaria (read binary).
        //    - "wb": Scrittura binaria (write binary).
        //    - "ab": Append binaria (append binary).
        //    - "r+": Lettura e scrittura (read and write) - apre un file di testo per lettura e scrittura. Il file deve esistere.
        //    - "w+": Lettura e scrittura (write and read) - apre un file di testo per lettura e scrittura. Se il file esiste, lo sovrascrive; se non esiste, lo crea.
        //    - "a+": Lettura e append (append and read) - apre un file di testo per lettura e append. Se il file non esiste, lo crea.
        //    Aggiungendo 'b' alla modalità (es. "rb", "wb", "ab", "r+b", "w+b", "a+b") si specifica che il file è binario.
        // Se 'fopen()' non riesce ad aprire il file (per vari motivi come file non trovato, permessi negati, ecc.),
        // restituisce 'NULL'. È cruciale controllare sempre il valore restituito da 'fopen()' per gestire eventuali errori.
	*/


	if(fp==NULL){ // Verifica se il puntatore al file 'fp' è NULL. Se è NULL, significa che 'fopen()' ha fallito nell'apertura del file.
		printf("\nErrore nell'apertura del file %s\n",filename); // Stampa un messaggio di errore indicando che l'apertura del file è fallita.
		return -1; // Restituisce -1 dalla funzione main per segnalare al sistema operativo che il programma è terminato con un errore.
	}

	printf("\nApertura file avvenuta correttamente\n"); // Se 'fp' non è NULL, l'apertura del file è avvenuta con successo. Stampa un messaggio di conferma.
	int numeroScritti = fwrite(&num_da_scrivere,sizeof(int),1,fp); // 'fwrite()' scrive dati binari su un file.
                                                                    // Argomenti di 'fwrite()':
                                                                    // 1. '&num_da_scrivere': Puntatore all'inizio del blocco di dati da scrivere. '&num_da_scrivere' fornisce l'indirizzo di memoria della variabile 'num_da_scrivere'.
                                                                    // 2. 'sizeof(int)': Dimensione in byte di ogni elemento da scrivere. 'sizeof(int)' restituisce la dimensione di un intero sulla piattaforma corrente.
                                                                    // 3. '1': Numero di elementi da scrivere. In questo caso, si vuole scrivere un solo intero.
                                                                    // 4. 'fp': Puntatore al file su cui scrivere (ottenuto da 'fopen()').
                                                                    // 'fwrite()' restituisce il numero di elementi effettivamente scritti con successo.
                                                                    // Questo valore dovrebbe essere uguale al terzo argomento (in questo caso 1) se la scrittura è andata a buon fine.

	/*
        //n = fwrite(&num,sizeof(int),1,fp);
        // La funzione 'fwrite()' è utilizzata per scrivere dati binari su un file.
        // Sintassi: fwrite(ptr, size, count, fp);
        // - ptr: Un puntatore al primo byte dei dati da scrivere. '&num' passa l'indirizzo della variabile 'num'.
        // - size: La dimensione in byte di ogni elemento da scrivere. 'sizeof(int)' fornisce la dimensione di un intero.
        // - count: Il numero di elementi di dimensione 'size' da scrivere. '1' indica che si vuole scrivere un solo intero.
        // - fp: Il file pointer restituito da 'fopen()', che indica il file su cui scrivere.
        // 'fwrite()' restituisce il numero di elementi scritti con successo. In caso di errore, può restituire un valore inferiore a 'count'.

        //if(n!=1){
        //    printf("Errore nella scrittura del numero binario");
        //    fclose(fp);
        //    return -1;
        //}
        // Questo blocco di codice verifica se il numero di elementi scritti da 'fwrite()' (memorizzato in 'n') è diverso da 1.
        // Se 'n' non è uguale a 1, significa che si è verificato un errore durante la scrittura.
        // In tal caso, viene stampato un messaggio di errore, il file viene chiuso con 'fclose(fp)', e la funzione 'main()'
        // restituisce -1 per indicare un errore. È importante controllare il valore di ritorno di 'fwrite()' (e 'fread()')
        // per gestire correttamente gli errori di I/O.
	*/


	if(numeroScritti!=1){ // Verifica se il numero di elementi scritti ('numeroScritti') è diverso da 1.
		printf("Errore nella scrittura del numero binario"); // Se diverso da 1, significa che c'è stato un errore nella scrittura. Stampa un messaggio di errore.
		fclose(fp); // Chiude il file. È importante chiudere il file anche in caso di errore per liberare le risorse.
		return -1; // Restituisce -1 per segnalare errore.
	}

	printf("\nScrittura del numero avvenuto con successo, hai inserito %d elementi",numeroScritti); // Se 'numeroScritti' è 1, la scrittura è avvenuta con successo. Stampa un messaggio di successo.
	fclose(fp); // Chiude il file dopo aver terminato la scrittura. È cruciale chiudere il file per salvare i dati e liberare risorse.

	/*
        //fclose(fp);//garantisci che tutti i dati scriti siano salvati
        // La funzione 'fclose(fp)' chiude il file associato al file pointer 'fp'.
        // È essenziale chiamare 'fclose()' quando si è finito di operare su un file, sia in lettura che in scrittura.
        // 'fclose()' svolge diverse azioni importanti:
        // 1. Scrive su disco tutti i dati che potrebbero essere ancora in buffer di memoria (specialmente nel caso di scrittura).
        // 2. Libera le risorse di sistema associate al file (come i file descriptor).
        // 3. Aggiorna le informazioni del file nel file system (come l'ultima data di modifica).
        // Non chiudere correttamente un file, specialmente dopo operazioni di scrittura, può portare a perdita di dati o corruzione del file.
	*/


	printf("\n--Fase di lettura da file--\n"); // Stampa un messaggio per indicare l'inizio della fase di lettura dal file.
	fp = fopen(filename,"rb"); // Apre nuovamente il file "firstFileBin.bin" in modalità "rb" (read binary - lettura binaria).
                                 // Questa modalità apre il file per la lettura di dati binari. Il file deve esistere per essere aperto in modalità lettura.

	if(fp==NULL){ // Verifica se l'apertura del file per la lettura è avvenuta con successo.
		printf("\nErrore nell'apertura del file %s\n",filename); // Se 'fp' è NULL, l'apertura è fallita. Stampa un messaggio di errore.
		return -1; // Restituisce -1 per segnalare errore.
	}

	int numeroLetti; // Variabile per memorizzare il numero di elementi letti da 'fread()'.
	int num_da_leggere; // Variabile per memorizzare il numero letto dal file.
	printf("\nApertura file avvenuta correttamente\n"); // Se l'apertura ha successo, stampa un messaggio di conferma.
	numeroLetti = fread(&num_da_leggere,sizeof(int),1,fp); // 'fread()' legge dati binari da un file.
                                                              // Argomenti di 'fread()':
                                                              // 1. '&num_da_leggere': Puntatore all'area di memoria in cui memorizzare i dati letti. '&num_da_leggere' fornisce l'indirizzo della variabile 'num_da_leggere'.
                                                              // 2. 'sizeof(int)': Dimensione in byte di ogni elemento da leggere.
                                                              // 3. '1': Numero di elementi da leggere. Si tenta di leggere un solo intero.
                                                              // 4. 'fp': Puntatore al file da cui leggere (ottenuto da 'fopen()').
                                                              // 'fread()' restituisce il numero di elementi effettivamente letti con successo.
                                                              // Se la lettura ha successo e si riesce a leggere il numero richiesto di elementi, il valore restituito sarà uguale al terzo argomento (in questo caso 1).
                                                              // Se si raggiunge la fine del file o si verifica un errore, il valore restituito potrebbe essere inferiore a 1.

	/*
        //int num_letto;
	    //n = fread(&num_letto,sizeof(int),1,fp);
	    // La funzione 'fread()' è utilizzata per leggere dati binari da un file.
	    // Sintassi: fread(ptr, size, count, fp);
	    // - ptr: Un puntatore all'area di memoria in cui memorizzare i dati letti. '&num_letto' fornisce l'indirizzo della variabile 'num_letto'.
	    // - size: La dimensione in byte di ogni elemento da leggere. 'sizeof(int)' fornisce la dimensione di un intero.
	    // - count: Il numero di elementi di dimensione 'size' da leggere. '1' indica che si vuole leggere un solo intero.
	    // - fp: Il file pointer restituito da 'fopen()', che indica il file da cui leggere.
	    // 'fread()' restituisce il numero di elementi letti con successo. Se si raggiunge la fine del file o si verifica un errore,
	    // può restituire un valore inferiore a 'count' (o 0 se non è stato letto nulla).

	    //if(n!=1){
        //    printf("Errore nella lettura del numero da file binario");
        //    fclose(fp);
        //    return -1;
        //}
        // Questo blocco di codice verifica se il numero di elementi letti da 'fread()' (memorizzato in 'n') è diverso da 1.
        // Se 'n' non è uguale a 1, significa che si è verificato un errore durante la lettura (es. fine del file raggiunta prima di leggere 1 intero, errore di I/O).
        // In tal caso, viene stampato un messaggio di errore, il file viene chiuso con 'fclose(fp)', e la funzione 'main()'
        // restituisce -1 per indicare un errore. Anche in questo caso, è fondamentale controllare il valore di ritorno di 'fread()'
        // per gestire correttamente gli errori di I/O.
	*/

	if(numeroLetti!=1){ // Verifica se il numero di elementi letti ('numeroLetti') è diverso da 1.
		printf("Errore nella lettura del numero binario"); // Se diverso da 1, significa che c'è stato un errore nella lettura. Stampa un messaggio di errore.
		fclose(fp); // Chiude il file.
		return -1; // Restituisce -1 per segnalare errore.
	}
	fclose(fp); // Chiude il file dopo la lettura.

	/*
        //fclose(fp);
        // Come per la scrittura, è fondamentale chiudere il file anche dopo la lettura utilizzando 'fclose(fp)'.
        // Questo libera le risorse associate al file e garantisce la corretta gestione del file system.
	*/

	printf("Numero letto dal file: %d\n",num_da_leggere); // Stampa il numero letto dal file, che è stato memorizzato nella variabile 'num_da_leggere'.
	return 0; // Restituisce 0 dalla funzione main per indicare che il programma è terminato con successo.
}
/*
    //return 0;
    // 'return 0;' indica che la funzione 'main()' termina la sua esecuzione e restituisce il valore 0.
    // In C, per convenzione, restituire 0 da 'main()' significa che il programma è stato eseguito con successo.
    // Un valore diverso da zero (solitamente -1 o 1) è usato per segnalare che si è verificato un errore durante l'esecuzione del programma.
*/
