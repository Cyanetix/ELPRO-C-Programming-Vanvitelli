/*
 Calcolo approssimativo di Pi greco 
o Obiettivo: Calcolare un'approssimazione di Pi greco usando il metodo di Monte Carlo. 
o Compiti:  
? Generare un numero elevato di punti casuali in un quadrato. 
? Contare quanti di questi punti cadono all'interno di un cerchio inscritto nel 
quadrato. 
? Utilizzare la formula pi = 4 * (punti nel cerchio / punti totali) per approssimare Pi 
greco.
? Stampare il valore approssimato di Pi greco.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define n 100000

int main()
{
	double npc=0;//numero punti nel cerchio
	int x, y;//coordinate dei punti
	double d, pi;//d è la distanza del punto dal centro O e pi  il pi greco
	srand(time(NULL));//imposto seme per rand
	
	for(int i=0;i<n;i++)
	{
		x=rand()%1000-500; 
		y=rand()%1000-500; // [-500,499]
		
		d= x*x+y*y; //distanza calcolato come x^2 + y^2 di cui faccio radice quadrata
		d = sqrt(d);
		
		if(d<500)//se distanza minore di 500, il punto si trova nel cerchio
		{
			npc++;//incrementa numero punti nel cerchio
			}	
		}
	//calcolo pi greco come rapporto
	pi  = (npc/n)*4;
	
	printf("pi=%f\n",pi);
	
	}

