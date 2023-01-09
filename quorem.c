#include <stdio.h>
int main()
{
	int n1,n2;
	float q,r;
	printf("enter 2 numbers");
	scanf("%d%d",&n1,&n2);
	q=(int)n1/n2;
	r=n1%n2;
	printf("the quotient of this division is %f",q);
	printf("the remainder of this division is %f",r);
	return 0;

}
