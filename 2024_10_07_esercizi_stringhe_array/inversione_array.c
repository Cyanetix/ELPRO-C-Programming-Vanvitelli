#include <stdio.h>
#include <stdlib.h>

#define n 100
/***
 *   Inizializzare 1 vettore di interi,
 *   chiedendo all'utente dimensioni e elementi da console.
 *   invertire gli elementi dell'array in modo che risulti riempito al contrario.
 *
 */
int main()
{
    int vet[n];
    int r, i, temp;

    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d",&r);
    for(i=0;i<r;i++)
    {
       printf("inserisci l'elemento vet[%d]\n", i);
       scanf("%d",&vet[i]);
    }

    for(i=0;i<r;i++)
      printf("%d ",vet[i]);

    printf("\n");

    for(i=0;i<r/2;i++)
     {
        temp = vet[i];
        vet[i]= vet[r-1-i];
        vet[r-1-i] = temp;
     }

    for(i=0;i<r;i++)
      printf("%d ",vet[i]);

    printf("\n");
    return 0;
}
