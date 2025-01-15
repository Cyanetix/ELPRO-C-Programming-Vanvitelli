#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100

struct mystruct
{
   char parola[NMAX];
   int pos;
};

typedef struct mystruct Parola;

int leggi(int m[][NMAX], int *r, int *c);
void creastringa(int m[][NMAX], int r, int c, char *s );
void riempivet(char s[], Parola v[], int *n);

int main()
{
    int r,c,m[NMAX][NMAX],errore,n;
    char str[NMAX*NMAX];
    Parola v[NMAX];
    errore=leggi(m,&r,&c);

    if(errore>0)
     {
         memset(str,0,NMAX*NMAX);
         creastringa(m,r,c,str);
         printf("%s\n",str);
         n=0;
         riempivet(str,v,&n);
         for(int i=0;i<n;i++)
            printf("{%s, %d}\n",v[i].parola, v[i].pos);
         FILE *fp=fopen("output.bin","w");
         if(fp!=NULL)
         {
             fwrite(v,sizeof(Parola),n,fp);
             fclose(fp);
         }//if fp
         }//if errore


    return 0;
}


int leggi(int m[][NMAX], int *pr, int *pc)
{
   FILE *fp;
   fp=fopen("input.txt", "r");
   if(fp!=NULL)
   {
     fscanf(fp, "%d %d", pr, pc);
     for(int i=0;i<*pr;i++)
     {
        for(int j=0;j<*pc;j++)
        {

          fscanf(fp, "%d", &m[i][j]);
        }
     }

    fclose(fp);
    }
    else
        return -1;

    return 1;
}
void creastringa(int m[][NMAX], int r, int c, char *s )
{
   char temp;
   for(int i=0;i<r;i++)
   {
      temp=(char)m[i][0];
      for(int j=1;j<c;j++)
        if(m[i][j]>=0)
         s[m[i][j]]=temp;
   }
}

void riempivet(char s[], Parola v[], int *n)
{
   char *pp;
   pp=strtok(s," ");
   while(pp!=NULL)
   {
     strcpy(v[*n].parola,pp);
     v[*n].pos=pp-s;
     *n=*n+1;
     pp=strtok(NULL," ");
   }


}
