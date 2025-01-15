/*
 * Scambiare le righe di una matrice di interi 
 * in modo che i valori della prima colonna risultino ordinati in senso crescente
 * */

#include<stdio.h>
#define NMAX 100

int main()
{
	int m[NMAX][NMAX];
	int r,c, temp;
	int i,j;
	
	printf("inserici r e c\n");
	scanf("%d %d", &r, &c);
	
	for(i=0;i<r;i++)
	   for(j=0;j<c;j++)
	     {
			 printf("inserisci m[%d][%d]:\n",i,j);
			 scanf("%d", &m[i][j]); 
			 }
	
	// stampa matrice
	for(i=0;i<r;i++)
	{
	   for(j=0;j<c;j++)
	    {
			 printf("%d\t", m[i][j]);
		 }
	     printf("\n");
	 }
	 
	     
	
	// scambio righe matrice
	
    for( i=0;i<r-1;i++)
    {
      for( j=0;j<r-1-i;j++)
         if(m[j][0]>m[j+1][0])
          {
			  
			
			
			for(int k=0;k<c;k++)
			{
				temp=m[j][k];
			    m[j][k]=m[j+1][k];
			    m[j+1][k]=temp;
				}
		  }
	  }
			
			
	 
	
	// stampa matrice
	printf("\nmatrice ordinata\n");
	for(i=0;i<r;i++)
	{
	   for(j=0;j<c;j++)
	    {
			 printf("%d\t", m[i][j]);
		 }
	     printf("\n");
	 }
	     
	
	
	}
