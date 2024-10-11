/* Trovare prima posizione della x
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
    
    printf("x?\n");
	scanf("%d",&x);
	
	i=0;
	while(v[i]!=x && i<n)
	  i=i+1;
	
	if(i==n)
	   printf("x non presente in v\n");
	 else
	   printf("%d trovato alla posizione %d", x, i);
	     
	
     
	
	
	
	
	}
