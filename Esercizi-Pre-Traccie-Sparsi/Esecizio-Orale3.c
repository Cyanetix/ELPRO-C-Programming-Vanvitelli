/*
Lunghezza della parola più lunga in una stringa
    Scrivi un sottoprogramma che, data una stringa, ne calcoli la lunghezza della parola più lunga.
*/
#include <stdio.h>
int lunghezzaParolaPiuLunga(char* str){
	int LenWords = 0;
	int LenWordsMax = 0;
	int i=0;
	while(str[i]!='\0'){
		if( !(str[i]== ' ') ){
			LenWords++;
		}else{
			if(LenWords>LenWordsMax){
				LenWordsMax = LenWords;
			}
			LenWords=0;
		}
		i++;
	}
	
	if(LenWords>LenWordsMax){
		LenWordsMax = LenWords;
	}
	
	return LenWordsMax;
}
int main() {
    char stringa1[] = "Questa è una frase di esempio";
    char stringa2[] = "Parola";
    char stringa3[] = "  Parola con spazi iniziali e finali  ";
    char stringa4[] = ""; // Stringa vuota
    char stringa5[] = "Parola1 parola2moltopiulunga parola3";

    printf("Stringa: \"%s\"\nLunghezza parola più lunga: %d\n\n", stringa1, lunghezzaParolaPiuLunga(stringa1));
    printf("Stringa: \"%s\"\nLunghezza parola più lunga: %d\n\n", stringa2, lunghezzaParolaPiuLunga(stringa2));
    printf("Stringa: \"%s\"\nLunghezza parola più lunga: %d\n\n", stringa3, lunghezzaParolaPiuLunga(stringa3));
    printf("Stringa: \"%s\"\nLunghezza parola più lunga: %d\n\n", stringa4, lunghezzaParolaPiuLunga(stringa4));
    printf("Stringa: \"%s\"\nLunghezza parola più lunga: %d\n\n", stringa5, lunghezzaParolaPiuLunga(stringa5));

    return 0;
}
