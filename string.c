#include <stdio.h>
#define N 100

int main(){

	char s1[N], s2[N];
	int i=0;
		
	printf("Iserisci s1:\n");
	scanf("%s", s1);

	printf("Iserisci s2:\n");
	scanf("%s", s2);	
		
	while( s1[i]==s2[i] && s1[i]!='\0' )
		i++;		
	if( s1[i]<s2[i] ){
		printf("%s precede %s\n", s1,s2);
	}else
		if(s1[i]>s2[i])
			printf("%s precede %s\n", s2,s1);
		else
			printf("Le due stringhe sono uguali");
return 0;	
}
