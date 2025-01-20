//Calcolo del MCD tra due numeri con algoritmo di euclide
#include <stdio.h>
int main(){
	int a;
	int b;
	int MCD;
	int r;
	//Acquisizione di a e b
	//lettura dei due numeri fin tanto che viene inserito come valore 0 o un numero negativo
	do{
		printf("Inserire il numero a:\n");
		scanf("%d",&a);	
	}while(a<=0);
	
	do{
		printf("Inserire il numero b:\n");
		scanf("%d",&b);	
	}while(b<=0);
    
    if(b>a){
    	int temp = a;
    	a = b;
    	b = temp;
	}
	
	while(b!=0){
		r = a % b;
		a = b;
		b = r;
		if(b==0){
			MCD = a;
		}
	}
	
	printf("\nIl MCD tra i due numeri inseriti e': %d\n",MCD);
	
return 0;
}
