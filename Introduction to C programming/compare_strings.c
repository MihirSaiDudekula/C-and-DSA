#include <stdio.h>

int main() {
	char s1[100],s2[100];
	int i;
	printf("enter 2 strings");
	fgets(s1, sizeof(s1), stdin); 
	fgets(s2, sizeof(s2), stdin); 
	i=0;
	while(s1[i]==s2[i] && s1[i]!='\0')
		i++;
	if(s1[i]>s2[i])
		printf("s1>s2");
	else if(s1[i]<s2[i])
		printf("s1<s2");
	else
		printf("s1=s2");
    return 0;
}
