#include <stdio.h>
#include <string.h>

#define N_MAX 100

struct Mystruct
{
    int rig;
    int c;
    int elementi[N_MAX];
};

void stampa(int m[N_MAX][N_MAX], int r,int c);
void elimina(int m[N_MAX][N_MAX], int* r, int c, int x);


int main()
{
	struct Mystruct v[N_MAX];
    int m[N_MAX][N_MAX],r,c;
    int somme[N_MAX];
    FILE *fp;
    
    memset(v,0,N_MAX*sizeof(struct Mystruct));
    
    fp=fopen("input.txt", "r");
    if(fp!=NULL)
    {
		fscanf(fp, "%d", &r);
		fscanf(fp, "%d", &c);
		for(int i=0;i<r;i++)
		  for(int j=0;j<c;j++)
		    fscanf(fp, "%d",&m[i][j]);
		fclose(fp);
		
	stampa(m, r,c);
	
	// calcolo lesomme delle righe
	for(int i=0;i<r;i++)
	{
		somme[i]=0;
		for(int j=0;j<c;j++)
		  somme[i]+=m[i][j];
		
		}
	
	//scambio
	int temp;
	for(int i=0;i<r-1;i++)
	  for(int j=0;j<r-1-i;j++)
	  {
		  if(somme[j] < somme[j+1])
		  {
			  temp=somme[j];
			  somme[j]=somme[j+1];
			  somme[j+1]= temp;
			  // scambio le righe
			  for(int k=0;k<c;k++)
			  {
				  temp=m[j][k];
				  m[j][k]=m[j+1][k];
				  m[j+1][k]=temp;
				  
				  }
			  
			  
			  }
		  }
	
	stampa(m, r,c);
	int oldr=r;
	for(int i=0;i<oldr;i++)
	{
		if((i%2==1) && (somme[i]%2==1))
		{
			elimina(m,&r,c,i-(oldr-r));
			} 
		
		
		}
	
	stampa(m,r,c);
	
	for(int i=0;i<r;i++)
	{
		v[i].rig=i;
		v[i].c=c;
		for(int j=0;j<c;j++)
		   v[i].elementi[j]=m[i][j];
		
		}
	
	fp=fopen("output.bin","w");
	if(fp!=NULL)
	{
		fwrite(v, sizeof(struct Mystruct),r,fp);
		fclose(fp);
		
	}

		}
    




}


void stampa(int m[N_MAX][N_MAX], int r,int c)
{
	for(int i=0;i<r;i++)
	{
	 for(int j=0;j<c;j++)
	   printf("%d \t",m[i][j]);
	 printf("\n");
   }
		printf("------------------------\n");

	}

void elimina(int m[N_MAX][N_MAX], int* pr, int c, int x)
{
	for(int i=x;i<*pr-1;i++)
	 for(int j=0;j<c;j++)
	   m[i][j]=m[i+1][j];
	
	*pr=*pr-1;
	
	
	}

