#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 100

struct Mystruct
{
    char data1[11];
    char data2[11];
    int giorni;
    float media[2];
};

int get_giorni_mese(int mese)
{
	int length[]={31,28,31,30,31,31,31,31,30,31,30,31};
	return length[mese-1];
	
	
	}
void printstruct(struct Mystruct m)
{
	printf("%s, %s, %d, %.2f, %.2f}\n",m.data1,m.data2,m.giorni,m.media[0],m.media[1]);
	}

// Funzione per calcolare la differenza in giorni tra due date
int differenzaGiorni(const char *data1, const char *data2)
{
    // Implementazione necessaria per il tuo specifico formato di data
    // In questo esempio, supponiamo che il formato sia "YYYY/MM/DD"

    // Estrai giorni, mesi e anni dalle due date
    int giorno1, mese1, anno1;
    int giorno2, mese2, anno2;

    sscanf(data1, "%d/%d/%d", &anno1, &mese1, &giorno1);
    sscanf(data2, "%d/%d/%d", &anno2, &mese2, &giorno2);

    // Calcola la differenza in giorni ignorando gli anni bisestili
    int giorni = 0;

    while (anno1 < anno2 || mese1 < mese2 || giorno1 < giorno2)
    {
        giorni++;

        // Aggiorna la data1 alla data successiva
        giorno1++;
        if (giorno1 > get_giorni_mese(mese1))
        {
            giorno1 = 1;
            mese1++;
            if (mese1 > 12)
            {
                mese1 = 1;
                anno1++;
            }
        }
    }

    return giorni;
}

// Funzione di confronto per l'ordinamento del vettore di struct per valori crescenti di media
void ordina( struct Mystruct *vettore, int n)
{
    struct Mystruct temp;
    for(int i=0;i<n-1;i++)
      for(int j=0;j<n-1-i;j++)
        if(vettore[j].giorni > vettore[j+1].giorni)
        {
			temp=vettore[i];
			vettore[i]=vettore[i+1];
			vettore[i+1]=temp;
			}
}

int main()
{
    FILE *inputFile, *outputFile;
    struct Mystruct vettore[N_MAX];
    int n = 0;

    // Apri il file di input
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        perror("Errore nell'apertura del file di input");
        return EXIT_FAILURE;
    }

    // Leggi i dati dal file di input
    int anno1, mese1, giorno1, anno2, mese2, giorno2;
    float v11,v12,v21,v22;
    char line[N_MAX],*ptemp;
    memset(vettore,0,N_MAX*sizeof(struct Mystruct));
    ptemp = fgets(line,N_MAX,inputFile);
    
    
    while(ptemp!=NULL) 
    {
		strncpy(vettore[n].data1,line,10);
		sscanf(line, "%d/%d/%d,%f,%f",  &anno1, &mese1,&giorno1,&v11,&v12);
		ptemp = fgets(line,N_MAX,inputFile);
		if(ptemp!=NULL)
		{
		  strncpy(vettore[n].data2,line,10);
		  sscanf(line, "%d/%d/%d,%f,%f",  &anno2, &mese2,&giorno2,&v21,&v22);
		
		  vettore[n].giorni = differenzaGiorni(vettore[n].data1, vettore[n].data2);
		  vettore[n].media[0]=(v21-v11)/ vettore[n].giorni;
		  vettore[n].media[1]=(v22-v21)/ vettore[n].giorni;
			// Incrementa il contatore
			n++;

			// Verifica che il vettore non sia pieno
			if (n == N_MAX)
			{
				fprintf(stderr, "Il vettore è pieno. Aumentare la dimensione massima del vettore.\n");
				break;
			}
		}
    }

    // Chiudi il file di input
    fclose(inputFile);

	
    // Ordina il vettore per valori crescenti del campo media
    ordina(vettore, n);
	for(int i=0;i<n;i++)
	  printstruct(vettore[i]);
    // Apri il file di output binario
    outputFile = fopen("output.bin", "wb");
    if (outputFile == NULL)
    {
        perror("Errore nell'apertura del file di output binario");
        return EXIT_FAILURE;
    }

    // Scrivi il vettore di struct nel file binario
    fwrite(vettore, sizeof(struct Mystruct), n, outputFile);

    // Chiudi il file di output binario
    fclose(outputFile);

    return 0;
}
