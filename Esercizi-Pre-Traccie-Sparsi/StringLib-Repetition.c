/*
Ripasso delle funzioni libreria string.h
*/
#include <string.h>
#include <stdio.h>
int main(){
	
	/*Copying*/
	//function memcpy usabile per qualsiasi tipo come le altre con i byte
	printf("\n*Copying*\n");
	int src[]={1,3,4,63,5};
	int dest[5];
	
	printf("Array src:\n");
	for(int i=0;i<5;i++){
		printf("%d ", src[i]); // Output: 1,3,4,63,5
	}
	//utilizzo memcpy per copiare il blocco di n byte di src in dest
	memcpy(dest,src,sizeof(src));//non gestisce sovrapposizione dei blocchi(src e dest se sono vicini potrebbe sovrascrivere)
	
	printf("\nArray dest:\n");
	for(int i=0;i<5;i++){
		printf("%d ", dest[i]); // Output: 1,3,4,63,5
	}
	
	//function memmove
	char s[]="ABC1345D";
	memmove(s+2,s,3);//sposto ABC sovrapposizione 
	
	printf("\ns:%s\n",s);//Output: ABABC45D
	
	//function strcpy
	char s_copy[8];
	strcpy(s_copy,s);
	
	printf("s_cpy:%s\n",s_copy);//Output: ABABC45D
	
	//function strncpy
	char s_ncopy[4];
	strncpy(s_ncopy,s,4);
	printf("s_ncpy:%s\n",s_ncopy);//Output: ABAB
	
	/*Concatenation*/
	printf("\n*Concatenation*\n");
	
	//function strcat
	char str_dest[20]="Hello ";
	strcat(str_dest,s_ncopy);//Output: Hello ABAB
	printf("str_dest:%s\n", str_dest);
	
	//function strncat
	strncat(str_dest,"!!!",3);
	printf("strn_dest:%s\n", str_dest);
	
	/*Comparison*/
	printf("\n*Comparison*\n");
	
	//function memcmp
	int arr1[]={1,2,3,4,5};
	int arr2[]={1,2,3,4,5};
	int result = memcmp(arr1,arr2,sizeof(arr1));
	printf("Risultato: %d\n", result);// Output: <0 (arr1 < arr2) >0 (arr1>arr2) =0 (arr1=arr2)
	
	//function strcmp
	int result_str = strcmp(s,s_copy);
	printf("Risultato confronto stringhe %s e %s: %d\n",s,s_copy,result_str);//// Output: <0 (str1 < str2) >0 (str1>str2) =0 (str1=str2)
	
	//function strncmp
	char s3[] = "apple";
    char s4[] = "application";
    
    result = strncmp(s3, s4, 3); // Confronta i primi 3 caratteri
    printf("Risultato confronto n chars, %s e %s: %d\n",s3,s4,result); // Output: 0 (app == app)
    
    //function strlen
    int len = strlen(s3);
    printf("Stringa %s e' costituita da %d chars\n",s3,len);
    
    /*Searching*/
	printf("\n*Searching*\n");
    
    //function memchr
    char str4[] = "Hello-_-World!";
    char *result1 = (char*)memchr(str4,'W',strlen(str4));
    char *result2 = (char*)memchr(str4, 'd', strlen(str4));
    printf("%s\n",str4);
    if (result1 != NULL) {
        printf("Trovato 'W' in posizione: %ld\n", result1 - str4); // Output: 8
    } else {
        printf("Carattere non trovato.\n");
    }
    
    if (result2 != NULL) {
        printf("Trovato 'd' in posizione: %ld\n", result2 - str4); // Output: 12
    } else {
        printf("Carattere non trovato.\n");
    }
    
    //function strchr
    char *p = strchr(str4,'_');
    if (p != NULL) {
        printf("Trovato 'd' in posizione: %ld\n", p - str4); // Output: 6
    } else {
        printf("Carattere non trovato.\n");
    }
    
    //function strcspn
    size_t len2 = strcspn(str4,"d");
    printf("Lunghezza fino al primo carattere: %zu\n", len2);
    
    //function strpbrk
    result1 = strpbrk(str4, "_-!");
    
    if (result1 != NULL) {
        printf("Trovato carattere in posizione: %ld\n", result1 - str4); // Output:  5
    } else {
        printf("Nessun carattere trovato.\n");
    }
    
    //function strrchr
    p = strrchr(str4,'o');
    if (p != NULL) {
        printf("Ultima occorenza carattere 'o' in posizione: %ld\n", p - str4); // Output: 9
    } else {
        printf("Carattere non trovato.\n");
    }
    
    //function strstr
    char str5[]="World";
    p = strstr(str4,str5);
    if (p != NULL) {
        printf("Occorenza %s in %s in posizione: %ld\n",str5,str4, p - str4); // Output: 8
    } else {
        printf("Carattere non trovato.\n");
    }
    
    //function strtok
    char str[] = "Ciao,Mondo! Questo e' un test.";
    char *token = strtok(str, " ,!");
    
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ,!");
    }
    
    return 0;
}

