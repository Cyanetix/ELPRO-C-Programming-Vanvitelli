#include <stdio.h>
#define N 1024
int main(){
	
	char s[N], *temp;
	float m, nchars;
	int cont = 0;
	FILE *fp;
	
	fp = fopen("input2.txt","r");
	if(fp!=NULL){
		
		do{
			temp = fgets(s,N,fp);
			if(temp!=NULL){
				nchars = strlen(s);
				if(nchars>5)
				{
					m+=nchars;
					cont++;
				}
				
			}
		}while(temp!=NULL);
		
		fclos(fp);
		m = m / cont;
		printf("lunghezza %f\n", m);
		
	}
	
	
return 0;
}
