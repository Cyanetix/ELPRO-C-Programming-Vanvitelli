/* Trovare ultima posizione della x
 * 
 */

#include<stdio.h>
#define N 100
int main()
{
	int v[100];
	int i, n,x;
	printf("n?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	 { printf("v[%i]?",i);
	  scanf("%d", &v[i]);
     }
    
     for(i=0;i<n/2;i++)
     {
		 x=v[i];
		 v[i]=v[n-1-i];
		 v[n-1-i]=x;
		 
		 }
  
	 for(i=0;i<n;i++)
	   printf("%d ", v[i]);
	 printf("\n");  
	
     
	
	
	
	
	}
