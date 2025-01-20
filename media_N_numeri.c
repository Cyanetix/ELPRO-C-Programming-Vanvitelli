//Calcolo della media dei primi numeri che l’utente inserisce prima dello 0
#include <stdio.h>
int main(){
	int num;
	float media = 0;
	int cont = 0;
	do{
		printf("Inserisci un numero o premi 0 per interrompere:\n");
		scanf("%d",&num);
		if(num!=0){
			cont++;
		    media = num + media;//media in questo blocco di codice rappresenta la somma degli n numeir inseriti
		}
	}while(num!=0);
	
	if(cont == 0){
		printf("\nNon hai inserito numeri validi\n");
	}else{
		media = media/cont;
		printf("La media del/dei %d numero/i che hai inserito e': %f",cont,media);	
	}

return 0;
}
