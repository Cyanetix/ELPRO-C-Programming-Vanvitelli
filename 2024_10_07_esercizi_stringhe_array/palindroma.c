/* Verificare che una stringa sia palindroma
 * 
 */

#include<stdio.h>
#define N 100
int main()
{

	char s[N];
	int n=0,i;
	scanf("%s",s);
	
	while(s[n]!='\0') n++;
	i=0;
	while(s[i]==s[n-i-1] && i<n/2) i++;
	
	
     if(i<n/2) 
        printf("la parola non e' palindroma!\n");
      else
        printf("la parola e' palindroma!\n");

        
     
	
	
	
	
	}
