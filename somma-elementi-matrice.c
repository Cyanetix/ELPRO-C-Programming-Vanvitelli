//Somma degli elementi di una matrice
#include <stdio.h>

int main(){
	int somma = 0;
	int sommaStar = 0;
	int i,j;
	int lastElement;
	//test int mat[3][3] ={ {1,2,3},{4,4,4},{7,8,9} };
	int mat[3][3] ={ {10,5,21},{7,14,8},{3,10,20} };
	
	for(i = 0;i < 3; i++){
		for(j = 0; j < 3; j++){
			
			if(mat[i][j] > lastElement){
				sommaStar = sommaStar + mat[i][j];
			}
			
			lastElement = mat[i][j];
			somma = somma + lastElement;
		}
	}
	printf("Somma di tutti gli elementi: %d \n",somma);
	printf("Somma Star degli elementi maggiori del precedente: %d\n",sommaStar);
return 0;
}
