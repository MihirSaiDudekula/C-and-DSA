#include <stdio.h>
int main()
{
	float cel,far;
	printf("\nEnter temperature in *C \n");
	scanf("%f",&cel);
	far=((9*(cel/5))+32);
	printf("\n This temperature in *F is = %f \n",far);
	
	return 0;
}
