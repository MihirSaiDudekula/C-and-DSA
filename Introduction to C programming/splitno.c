#include <stdio.h>
int main()
{
	float n=2573;
	int d1,d2,d3,d4;
	int a,b,c;
	d1=(int)2573/1000;
	printf("\n %d",d1);
	a=(int)2573%1000;
	d2=(int)a/100;
	b=(int)a%100;
        d3=(int)b/10;
	c=(int)n%10;
        d4=c;
	printf("\n %d",d2);
	printf("\n %d",d3);
	printf("\n %d",d4);




	//printf("\n %d",d4);
	
	
	return 0;

}
