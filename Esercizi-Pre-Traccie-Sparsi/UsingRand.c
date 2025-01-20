#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(NULL));//Imposta una seed basata sul tempo corrente
    for (int i = 0; i < 5; i++) {
    	//Genera un numero casuale tra 1 e 100
    	int randomNumber = (rand() % 100) + 1;
        printf("%d\n", randomNumber);
    }
    return 0;
}
