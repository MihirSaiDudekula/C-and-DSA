#include <stdio.h>
int main()
{
	int a,b;
	printf("enter two numbers to check for the larger number");
	scanf("%d%d",&a,&b);
	int big,smol;
	big = (a>b)?a:b;
	printf("\n larger value is %d ",big);
	smol = (a<b)?a:b;
        printf("\n smaller value is %d ",smol);
	return 0;

}
