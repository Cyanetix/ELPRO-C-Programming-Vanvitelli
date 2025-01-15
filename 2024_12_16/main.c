#include <stdio.h>
#include <string.h>

#define N_MAX 100
struct Mystruct {
	int occ;
	int riga;
	int col;
	int len;
	int vettore[N_MAX];
};

int cerca(int m[N_MAX][N_MAX], int r, int c, int v[N_MAX], int n, struct Mystruct *a);


int main()
{
	
	int m[N_MAX][N_MAX],r,c;
	int n, v[N_MAX];
	int l=0;
	struct Mystruct a[N_MAX];
	
	memset(a,0,N_MAX*sizeof(struct Mystruct));
	
	FILE *fp=fopen("input.txt", "r");
	if(fp!=NULL)
	{
		fscanf(fp,"%d %d",&r, &c);
		for(int i=0;i<r;i++)
		 for(int j=0;j<c;j++)
		   fscanf(fp, "%d", &m[i][j]);
		
		fscanf(fp,"%d",&n);
		for(int i=0;i<n;i++)
		  fscanf(fp, "%d",&v[i]);
		fclose(fp);  
		
	
	for(int i=0;i<r;i++)
	{
		 for(int j=0;j<c;j++)
		    printf("%d \t",m[i][j]);
		 printf("\n");
	}
	
	for(int i=0;i<n;i++)
	   printf("%d ", v[i]);
	printf("\n");
    
    l=cerca(m,r,c,v,n,a);
    
    for(int i=0;i<l;i++)
    {
    	printf("{%d,%d,%d,%d, [",a[i].occ, a[i].riga, a[i].col, a[i].len);
    	for(int j=0;j<a[i].len;j++)
    	  printf("%d ", a[i].vettore[j]);
    	printf("]}\n");
    	
    }
    
    
    
    fp=fopen("output.bin", "w");
    if(fp!=NULL){
       fwrite(a,sizeof(struct Mystruct),l,fp);
       fclose(fp);}
	}
	
	
	}
	
	
	int cerca(int m[N_MAX][N_MAX], int r, int c, int v[N_MAX], int n, struct Mystruct *a)
	{
		int alen=0;
		for(int i=0;i<r;i++)
		 for(int j=0;j<c;j++)
		   if(v[0]==m[i][j] &&(r*c-(i*c+j)>=n))
		   {  //ho trovato il primo elemento del vettore nella matrice
		   	  int k=0;
		   	  int x=i,y=j;
		   	  //confronto gli altri elementi
		   	    do{
		   	    	k++;
		   	    	y=(y+1)%c;
		   	    	if(y==0)
		   	    	  x=x+1;
		   	    }while(k<n &&m[x][y]==v[k]);
		   	    if(k==n)
		   	    { //ho trovato tutti gli elementi di v
		   	      a[alen].occ=alen;
		   	      a[alen].riga=i;
		   	      a[alen].col=j;
		   	      a[alen].len=n;
		   	      for(k=0;k<n;k++)
		   	        a[alen].vettore[k]=v[k];
		   	      alen++;
		   	    }
		   	
		   }
		
		return alen;
		
		
		
		
	}
	
	
