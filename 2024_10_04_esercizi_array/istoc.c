#include <stdio.h>

int main()
{
	int v[]={1,10,3,4,5};
	int i,j,nrighe,vmax;
	
	//cercare il massimo
	vmax=v[0];
	for(i=1;i<5;i++)
	{
		if(vmax<v[i])
		{
			vmax=v[i];
			}
		}
	
	nrighe=vmax;
	
	for(i=0;i<nrighe;i++)
	{
		//stampa riga
		for(j=0;j<5;j++)
		{
			if(v[j]>=vmax-i)
			   printf("*");
			else
			   printf(" ");
			}
			
		printf("\n");	
		
		}
	
	
	}
