/*
Ripasso delle funzioni libreria stdlib.h
*/
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atof */ /* atoi */ /* atol */
int main ()
{
	
	/* atof example*/
	char string[]="3.1415926535";
	double pi;//tipo di ritorno è double
	pi = atof(string);
	printf("Double: %g\n",pi);
	
	/* atoi example */
	char string2[] = "39543";
	int n;//tipo ritorno è integer
	n = atoi(string2);
	printf("Integer: %d\n",n);
	
	/* atol example */
	char string3[] = "39543999";
	long int n2;//tipo ritorno è long
	n2 = atol(string3);
	printf("Long: %ld\n",n2);
	
	/* strtod example */ //similmente per strtof
	char szOrbits[] = "365.24 29.53";
	char* pEnd;
	double d1, d2;
	d1 = strtod (szOrbits, &pEnd); //restituisce puntatore alla parte restante della stringa
	d2 = strtod (pEnd, NULL);
	printf ("The moon completes %.2f orbits per Earth year.\n", d1/d2);
	
	//successive funzioni di conversione da stringa saltate
	
	//pointers
	
	
	//Gestione dinamica della memoria //vedi esercizi Dynamic allocation
	int *ptr = (int*)malloc(sizeof(int)*10);//oppure int *ptr=(int*)calloc(10,sizeof(int));
	if(ptr==NULL){
		return -1;
	}
	free(ptr);
	return 0;
}
