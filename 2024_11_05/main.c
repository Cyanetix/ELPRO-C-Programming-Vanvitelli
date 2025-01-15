#include<stdio.h>
#define N_MAX 100
struct Mystruct
{
	int indice;
	int n;
	int valori[N_MAX];
	float media;
};

float mediacolonna(int m[][N_MAX], int r, int ic);
void print_struct( struct Mystruct s);
void ordina(struct Mystruct v, int n);

int main()
{
	struct Mystruct v[N_MAX];
	FILE *fp;
	int r, c, m[N_MAX][N_MAX];
	
	fp=fopen("input.txt", "r");
	if(fp!=NULL)
	{
		fscanf(fp,"%d %d",&r,&c);
		for(int i=0;i<r;i++)
		  for(int j=0;j<c;j++)
		    fscanf(fp, "%d",&m[i][j]); 
		
		fclose(fp);
		
	
	
	for(int j=0;j<c;j++)
	{
		v[j].indice=j;
		v[j].n=r;
		for(int i=0;i<r;i++)
		  v[j].valori[i]=m[i][j];
		v[j].media=mediacolonna(m,r,j);	
		}
	
	 ordina(v,n);
	 for(int i=0;i<c;i++)
	   print_struct(v[i]);
	
     fp=fopen("output.bin", "w");
     if(fp!=NULL)
     {
		 fwrite(v, sizeof(struct Mystruct),c, fp);
		 fclose(fp);
		 
		 }	
	
        }
       else printf("Attenzione input.txt not found\n");
	
	}
	

void print_struct( struct Mystruct s)
{
	printf("{%d, %d, %f, [",s.indice, s.n, s.media);
	for(int i=0;i<s.n;i++)
	  printf(" %d ",s.valori[i]);
	printf("]}\n");
	
	}


float mediacolonna(int m[][N_MAX], int r, int ic){
	float media=0;
	for(int i=0;i<r;i++)
	  media += m[i][ic];
	media =media/r;
	return media;
	
	}


void ordina(struct Mystruct v, int n)
{
	struct Mystruct temp;
	for(int i=0;i<n-1;i++)
	  for(int j=0;j<n-1-i;j++)
	    {
			if(v[j].media<v[j+1].media)
			{  
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
				
				}
			
			}
	
	
	
	
	}
