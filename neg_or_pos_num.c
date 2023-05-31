#include <stdio.h>
int main()
{
	int num;
	//int t=0;
	printf("enter the required number ");
	scanf("%d",&num);
	(num>0)?printf("positive"):((num==0)?printf("zero"):printf("Negative"));
}
	
