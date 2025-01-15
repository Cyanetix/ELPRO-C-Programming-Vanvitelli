#include<stdio.h>
 
int main()
{
 int  ordinato=0;
 int v[100];
 int n, temp;
 
 printf("n?\n");
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
	 printf("v[%d]=?\n",i);
	 scanf("%d", &v[i]);
	 }
 
		for(int i=0;i<n-1 && !ordinato ;i++)
		 {
			  ordinato=1;
			  for(int j=0;j<n-1-i;j++)
				{
					if(v[j]>v[j+1])
					{
						ordinato=0;
						temp=v[j];
						v[j]=v[j+1];
						v[j+1]=temp;
						}
					
					}
			}

 for(int i=0;i<n;i++)
 {
	 printf("%d ", v[i]);
	 }
  printf("\n");
}
