#include <stdio.h>
#define N 100

int main(){
	int v[N];
	int i,n,x;
	
	printf("Quanti elementi vuoi inserire?\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("v[%d]?\t",i);
		scanf("%d",&v[i]);
	}
	
	printf("x?\n");
	scanf("%d",&x);
	
	i=0;
	while(v[i]!=x && i<n){
		i=i+1;
	}
	if(i==n){
		printf("x non presente in v");
	}else{
		printf("Valore %d trovato alla posizione %d",x,i);
	}
return 0;	
}
