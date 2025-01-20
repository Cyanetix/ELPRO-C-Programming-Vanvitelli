//Matrice delle ricorrenze
#include <stdio.h>

int main(){
	int mat_o[3][3] ={ {1,2,5},{21,13,15},{7,1,9} };
	int mat_test[3][3] ={ {1,0,7},{4,9,3},{12,9,1} };
	int mat_ric[3][3];
	int i,j;
	int cont = 0;
	
	for(i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if(mat_test==mat_o){
				cont++;
			}
			mat_ric = cont;
		}
	}
	
return 0;
}
