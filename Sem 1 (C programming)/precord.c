#include <stdio.h>
int main()
{
	int a;
	int b;
	int c;
	int d;
	int res;	
	printf("\n enter 4 numbers \n");
	// assume the numbers are a=10 b=5 c=2 d=10
	scanf("%d%d%d%d",&a,&b,&c,&d);
	res=a/b*(c+d)*a/b;
	printf("\n result is = %d ",res);
	
	return 0;

}
