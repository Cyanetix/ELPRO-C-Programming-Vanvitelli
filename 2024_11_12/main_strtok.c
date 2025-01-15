#include<stdio.h>
#include<string.h>


#define N_MAX 100
	struct Mystruct
	{
		int id;
		int chars;
		int words;
		float meanc;
		float meanw;
							
	};
	
void ordina(struct Mystruct v[],int n);
int parole(char *s);	
	
int main()
{
	FILE * fp;
	char s[1024], *temp, *frase;
	struct Mystruct v[N_MAX];
	int n=0;
	float totalchars=0, totalwords=0;
	
	memset(v,0,sizeof(struct Mystruct)*N_MAX);
	
	fp=fopen("input.txt", "r");
	if(fp!=NULL)
	{
		
		do{
		   temp=fgets(s,1024,fp);
		   if(temp!=NULL)
		       {
				   if(s[strlen(s)-1]=='\n')
				      s[strlen(s)-1]='\0';
				   //puts(s);
				  
				  frase = strtok(s,".!?");

				  while(frase!=NULL){
					 
						 v[n].id=n;
						 v[n].chars=strlen(frase);
						 v[n].words= parole(frase);
						 totalchars += v[n].chars;
						 v[n].meanc=totalchars/(n+1);
						 totalwords += v[n].words;
						 v[n].meanw=totalwords/(n+1);
						 n++;
						 puts(frase);
						 frase=strtok(NULL,".!?");					  
					  } 
				   
				  
				   
				   
				   
			   }
		}while(temp!=NULL);
		
		
		
		
		fclose(fp);
		
		
		ordina(v,n);
		
		
		
		printf("%d\n",n);
		for(int i=0;i<n;i++)
		{
			printf("{%d, %d, %d, %.2f, %2.f}\n", v[i].id, v[i].chars, v[i].words, v[i].meanc, v[i].meanw);
			
			}
		
		fp=fopen("output.bin", "w");
		if(fp!=NULL)
		{
			fwrite(v,sizeof(struct Mystruct),n,fp);
			fclose(fp);
			}
		
		
		}
	
	
	
	}

int parole(char *s)
{
	int i=0,cont=0;
	while(s[i]!='\0')
	{
		if(s[i]!=' ' && (s[i+1]==' ' ||s[i+1]=='\0' ))
		   cont++;
		i++;
		}
	   return cont;
	}


void ordina(struct Mystruct v[],int n){
	
	struct Mystruct temp;
	
	for(int i=0;i<n-1;i++)
	  for(int j=0;j<n-1-i;j++)
	    if(v[j].chars< v[j+1].chars)
	    {
			temp=v[j];
			v[j]=v[j+1];
			v[j+1]=temp;
			
			}
	
}
	
	
	
