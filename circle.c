#include <stdio.h>
#define PI 3.1416

int main(void){
	float c;
	float a;
	float r;
	// statements
	printf("\nthis program accepts radius of the circle from the user amnd then displays the area and circumference of that circle");
        printf("\nPlease enter the radius of the circle ");
	scanf("%f",&r);
	c=(2*PI*r);
	a=(PI*r*r);
	printf("\n The radius of this circle is          : %10.2f",r);
	printf("\n The circumference of this circle is   : %10.2f",c);
	printf("\n The area of this circle is            : %10.2f",a);

	return 0;
}


