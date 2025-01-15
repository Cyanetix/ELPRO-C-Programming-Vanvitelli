#include <stdio.h>
#include <stdlib.h>

struct mystruct
{
int n_val_sinistra;
int n_val_destra;
int somma;
};

int main()
{
    int temp, somma_left,somma_right, valori_letti,n,cont1, cont2;
    char c;
    struct mystruct v[100];
    n=0;
    FILE *fp=fopen("input.txt", "r");
    if(fp!=NULL)
    {
      do{
        // leggi parte sinistra
        somma_left=0;
        cont1=0;
        do{
           fscanf(fp,"%d%c",&temp,&c);
           cont1++;
             somma_left+=temp;

        }while(c=='+');

        // leggi parte destra
        somma_right=0;
        cont2=0;
        do{
           fscanf(fp,"%d%c",&temp,&c);
            cont2++;
             somma_right+=temp;

        }while(c=='+');
        printf("%d, %d\n",somma_left,somma_right);
        if(somma_left==somma_right)
        {
          v[n].n_val_sinistra=cont1;
          v[n].n_val_destra=cont2;
          v[n].somma=somma_left;
          printf("{%d, %d, %d}\n", v[n].n_val_sinistra, v[n].n_val_destra, v[n].somma);
          n++;

        }

        valori_letti=fscanf(fp,"%c",&c);
      }while(c=='\n'&& valori_letti==1);

    }


    return 0;
}
