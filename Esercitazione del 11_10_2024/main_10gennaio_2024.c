#include <stdio.h>
#include <stdlib.h>
#define N_MAX 100

struct Mystruct
{
    int indice;
    int n;
    int valori[N_MAX];
    float nmass;
};

// Dichiarazione delle funzioni
int leggi_matrice(int mat[N_MAX][N_MAX], int *n_righe, int *n_colonne);
void stampa_matrice(int mat[N_MAX][N_MAX], int n_righe, int n_colonne);
void elimina_colonna(int mat[N_MAX][N_MAX], int n_righe, int *n_colonne, int indx_colonna);
void elimina_colonne_palindromiche(int mat[N_MAX][N_MAX], int n_righe, int *n_colonne);
int trova_massimo_globale(int mat[N_MAX][N_MAX], int n_righe, int n_colonne);
void riempi_struct(struct Mystruct vet[], int mat[N_MAX][N_MAX], int n_righe, int n_colonne, int massimo);
void ordina_vettore(struct Mystruct vet[], int n_righe);
int salva_su_file(struct Mystruct vet[], int n_righe);
void stampa_struct(struct Mystruct vet[], int n_righe, int n_colonne);

int main()
{
    int mat[N_MAX][N_MAX];
    int n_righe = 0;
    int n_colonne = 0;

    if (leggi_matrice(mat, &n_righe, &n_colonne) == -1) {
        printf("Errore nella apertura del file");
        return -1;
    }

    stampa_matrice(mat, n_righe, n_colonne);

    elimina_colonne_palindromiche(mat, n_righe, &n_colonne);
    stampa_matrice(mat, n_righe, n_colonne);

    struct Mystruct vet[N_MAX];
    int massimo = trova_massimo_globale(mat, n_righe, n_colonne);

    riempi_struct(vet, mat, n_righe, n_colonne, massimo);

    // Stampa del vettore prima dell'ordinamento
    stampa_struct(vet, n_righe, n_colonne);

    ordina_vettore(vet, n_righe);
    printf("\n");
    // Stampa del vettore dopo l'ordinamento
    stampa_struct(vet, n_righe, n_colonne);

    if(salva_su_file(vet, n_righe)==-1){
        printf("errore nella scrittura su file");
    }

    return 0;
}

// Funzione per leggere la matrice da file
int leggi_matrice(int mat[N_MAX][N_MAX], int *n_righe, int *n_colonne)
{
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        return -1;
    }
    fscanf(fp, "%d %d", n_righe, n_colonne);
    for (int i = 0; i < *n_righe; i++) {
        for (int j = 0; j < *n_colonne; j++) {
            fscanf(fp, "%d", &mat[i][j]);
        }
    }
    fclose(fp);
    return 0;
}

// Funzione per stampare la matrice
void stampa_matrice(int mat[N_MAX][N_MAX], int n_righe, int n_colonne)
{
    printf("\n");
    for (int i = 0; i < n_righe; i++) {
        for (int j = 0; j < n_colonne; j++) {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

// Funzione per eliminare una colonna specifica
void elimina_colonna(int mat[N_MAX][N_MAX], int n_righe, int *n_colonne, int indx_colonna)
{
    for (int i = 0; i < n_righe; i++) {
        for (int j = indx_colonna; j < *n_colonne - 1; j++) {
            mat[i][j] = mat[i][j + 1];
        }
    }
    (*n_colonne)--;
}

// Funzione per eliminare colonne palindromiche
void elimina_colonne_palindromiche(int mat[N_MAX][N_MAX], int n_righe, int *n_colonne)
{
    int is_palindroma;
    for (int j = 0; j < *n_colonne; j++) {
        is_palindroma = 1;
        for (int i = 0; i < n_righe / 2; i++) {
            if (mat[i][j] != mat[n_righe - 1 - i][j]) {
                is_palindroma = 0;
            }
        }
        if (is_palindroma) {
            elimina_colonna(mat, n_righe, n_colonne, j);
            j--;
        }
    }
}

// Funzione per trovare il massimo globale della matrice
int trova_massimo_globale(int mat[N_MAX][N_MAX], int n_righe, int n_colonne)
{
    //inizializzo massimo al primo elemento della matrice
    int massimo = mat[0][0];
    for (int i = 0; i < n_righe; i++) {
        for (int j = 0; j < n_colonne; j++) {
            if (mat[i][j] > massimo) {
                massimo = mat[i][j];
            }
        }
    }
    return massimo;
}

// Funzione per aggiornare il vettore di strutture
void riempi_struct(struct Mystruct vet[], int mat[N_MAX][N_MAX], int n_righe, int n_colonne, int massimo)
{
    int massimo_locale;
    for (int i = 0; i < n_righe; i++) {
        vet[i].indice = i;
        vet[i].n = n_colonne;
        massimo_locale = mat[i][0];
        for (int j = 0; j < n_colonne; j++) {
            vet[i].valori[j] = mat[i][j];
            if (mat[i][j] > massimo_locale) {
                massimo_locale = mat[i][j];
            }
        }
        vet[i].nmass = (float)massimo_locale / (float)massimo;
    }
}

// Funzione per ordinare il vettore di strutture
void ordina_vettore(struct Mystruct vet[], int n_righe)
{
    struct Mystruct temp;
    int indx_to_swap;

    for (int i = 0; i < n_righe - 1; i++) {
        indx_to_swap = i;
        for (int j = i + 1; j < n_righe; j++) {
            if (vet[indx_to_swap].nmass > vet[j].nmass) {
                indx_to_swap = j;
            }
        }
        temp = vet[i];
        vet[i] = vet[indx_to_swap];
        vet[indx_to_swap] = temp;
    }
}

// Funzione per salvare i dati su file binario
int salva_su_file(struct Mystruct vet[], int n_righe)
{
    FILE *fp2 = fopen("output.bin", "wb");
    if (fp2 == NULL) {
        printf("Errore di apertura del file output");
        return -1;
    }
    fwrite(vet, sizeof(struct Mystruct), n_righe, fp2);
    fclose(fp2);
    return 0;
}

// Funzione per stampare il vettore di struct
void stampa_struct(struct Mystruct vet[], int n_righe, int n_colonne)
{
    for (int i = 0; i < n_righe; i++) {
        printf("{%d, %d, %f, [", vet[i].indice, vet[i].n, vet[i].nmass);
        for (int j = 0; j < n_colonne; j++) {
            printf("%d", vet[i].valori[j]);
            if (j < n_colonne - 1) {
                printf(", ");
            }
        }
        printf("]}\n");
    }
}
