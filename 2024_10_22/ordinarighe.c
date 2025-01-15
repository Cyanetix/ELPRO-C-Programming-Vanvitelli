/*
 * Ordinare le righe di una matrice di interi per valori crescenti
 * 
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
	 
	     
	
	// ordina righe matrice
	
	for(i=0;i<r;i++)
	{
		//ordinamento riga i con bubble sort
		
		for(int k=0;k<c-1;k++)
		  for(j=0;j<c-k-1;j++)
		    if(m[i][j]>m[i][j+1])
		    {
				temp=m[i][j];
				m[i][j]=m[i][j+1];
				m[i][j+1]=temp;
				
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
