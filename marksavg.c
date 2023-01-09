#include <stdio.h>
int main()
{
	float a,b,c,d,e;
	printf("\n enter marks of 5 students ");
	scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);
	float sum;
	sum=(a+b+c+d+e);
	float avg;
	avg = sum/5;
	printf("\n The average marks of a student is %f ",avg);
	return 0;

}
