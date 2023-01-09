#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,disc,r1,r2,rp,ip;
	printf("\n enter the coefficient of x^2  ");
	scanf("%f",&a);
	printf("\n enter the coefficient of x  ");
        scanf("%f",&b);
	printf("\n enter the constant term  ");
        scanf("%f",&c);
	disc=((b*b)-(4*a*c));
	if(disc>0)
	{
		r1=(((-1*b)+sqrt(disc))/(2*a));
		r2=(((-1*b)-sqrt(disc))/(2*a));
		printf("\nFirst root is  %f ",r1);
		printf("\nSecond root is  %f ",r2);
	}
	if(disc<0)
	{
		rp=(-1*b)/(2*a);
		ip=(sqrt((-1*disc)))/(2*a);
		//r1=(((-1*b)+sqrt(disc))/(2*a));
                //r2=(((-1*b)-sqrt(disc))/(2*a));
                printf("\nFirst root is %f+i%f ",rp,ip);
                printf("\nSecond root is %f-i%f ",rp,ip);
	
	
	}
		
	
	if(disc==0)
	{
		printf("  \n Both roots are equal  ");
		r1=(((-1*b))/(2*a));
                r2=(((-1*b))/(2*a));
                printf("\nFirst root is %f ",r1);
                printf("\nSecond root is %f ",r2);
	
	}
	return 0;

}
