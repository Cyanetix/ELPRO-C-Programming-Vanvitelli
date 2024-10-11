#include <stdio.h>
#include <math.h>
#define MAXROWS 36
#define MAXCOLS 40
#define PI 3.14
int main()
{
	int n=0;
	double x;
	int p;
	while(n<MAXROWS)
	{
		x = (2*PI/MAXROWS)*n;
		x = cos(x);
		
		
		x = (x+1)*MAXCOLS/2;
		//printf("%f\n",x);
		p=0;
		while(p<MAXCOLS)
		{	if((p<x) && (p+1 >=x))
				printf("*%f",x);
			else
				printf(" ");
			p++;
			}
		printf("\n");
		n++;
		}
	
	
	}
