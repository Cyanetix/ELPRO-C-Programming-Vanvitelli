#include <stdio.h>
#define N 100
int main(){
	
	int r,c,m[N][N],i,j;
	FILE *fp;
	
	fp = fopen("input.txt","r");
	if(fp!=NULL){
		fscanf(fp,"%d",&r);
		fscanf(fp,"%d",&c);
		printf("%d  %d\n",r,c);
		for(i = 0; i < r; i++){
			for(j=0; j < c;j++){
				fscanf(fp,"%d",&m[i][j]);
			}
		}
		
		for(i = 0; i < r; i++){
			for(j=0; j < c;j++){
				printf("%d\t",m[i][j]);
			}
			printf("\n");
		}
		
	}
	
	
return 0;
}
