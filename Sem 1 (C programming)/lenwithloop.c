#include <stdio.h>

int main() {
	char str[20];
	int i=0;
	printf("enter string");
	//gets(str);
	fgets(str, sizeof(str), stdin); 
	while(str[i]!='\0')
	{
		i++;
	
	}
	printf("length of string is = %d \n",i);
	return 0;
}
