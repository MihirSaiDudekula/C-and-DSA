#include <stdio.h>
int main()
{
	float p,r,t;
	printf("\n enter principle rate and time for SI ");
	scanf("%f%f%f",&p,&r,&t);
	float s;
	s=((p*r*t)/100);
	printf("\n The simple interest computed is %f ",s);
	return 0;

}
