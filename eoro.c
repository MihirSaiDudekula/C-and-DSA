#include <stdio.h>
int main()
{
	int num;
	printf("enter the number to check for if the given no is even or odd");
	scanf("%d",&num);
	((num%2)==0)?printf("%d is even",num):printf("%d is odd",num);
	return 0;

}
