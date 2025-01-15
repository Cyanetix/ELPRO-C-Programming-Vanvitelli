#include <stdio.h>
#include <string.h>

#define N_MAX 100

struct Mystruct
{
    int index;
    int n;
    float elems[N_MAX];
    float media;
};


void print_mat(float [][N_MAX], int, int);
void print_struct(struct Mystruct);
void modifica_matrice(float [][N_MAX], int, int);
void crea_structs(float [][N_MAX], int, int, struct Mystruct[]);
float media(float[], int);


int main(int argc, char** argv)
{
    float mat[N_MAX][N_MAX]; //Matrice
    struct Mystruct righe[N_MAX]; //Array di struct
    int i, j; //Indici di scorrimento della matrice
    int r, c; //Numero di righe e colonne della matrice letta

    FILE* fp_in;
    FILE* fp_out;

    //Inizializzazione dell'area di memoria relativa all'array di struct
    memset(righe, 0, sizeof(struct Mystruct)* N_MAX);

    //Apertura del file di input
    fp_in = fopen("input.txt", "r");
    if(fp_in != NULL)
    {
        //Lettura dei dati (dimensioni e elementi) della matrice dal file di input
        fscanf(fp_in, "%d", &r);
        fscanf(fp_in, "%d", &c);
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
                fscanf(fp_in, "%f", &mat[i][j]);
        }
        //Chiusura del file di input
        fclose(fp_in);

        //Modifica della matrice letta
        /*Completare il codice mediante la funzione modifica_matrice*/

        //Creazione delle structs
        /*Completare il codice mediante la funzione crea_structs*/

        //Scrittura delle structs sul file di output .bin
        fp_out = fopen("output.bin", "wb");
        if (fp_out != NULL)
        {
            fwrite(righe, sizeof(struct Mystruct), r, fp_out);
            fclose(fp_out);
        }
    }
    else
        printf("Errore apertura file");
    return 0;
}


/*Funzione per la stampa a video di una matrice di interi, con parametri:
- mat: matrice da stampare
- r: numero di righe
- c: numero di colonne*/
void print_mat(float mat[][N_MAX], int r, int c)
{
    int i, j;
    for(i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
            printf("%5.2f\t", mat[i][j]);
        printf("\n");
    }
}

/*Funzione per la stampa a video di una struct di tipo Mystruct, con parametri:
- colonna: struct di tipo Mystruct da stampare*/
void print_struct(struct Mystruct riga)
{
  int i;

  printf("{%d, %d, [", riga.index, riga.n);
  for(i=0; i<riga.n; i++)
    printf(" %.2f ", riga.elems[i]);
  printf("], %.2f}\n", riga.media);
}


/*Funzione per la modifica della matrice in base al secondo punto della traccia, con parametri:
- mat: matrice in input
- r: numero di righe della matrice
- c: numero di colonne della matrice*/
void modifica_matrice(float mat[][N_MAX], int r, int c)
{
 /*Completare il codice con l'implementazione della funzione*/
}


/*Funzione per la creazione delle structs di tipo Mystruct, con parametri:
- mat: matrice in input
- r: numero di righe della matrice
- c: numero di colonne della matrice
- righe: array di structs di tipo Mystruct.*/
void crea_structs(float mat[][N_MAX], int r, int c, struct Mystruct righe[])
{
/*Completare il codice con l'implementazione della funzione*/
}

/*Funzione per il calcolo della media di un vettore di float, con parametri:
- vet: vettore di float di cui calcolare la media
- n: dimensione del vettore.
La funzione restituisce un float che rappresenta la media del vettore.*/
float media(float vet[], int n)
{
/*Completare il codice con l'implementazione della funzione*/
}
