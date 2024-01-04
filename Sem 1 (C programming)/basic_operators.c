#include <stdio.h>

int main(){
	int a=0,b=0,c=0,d=0;
	//read values
	printf("enter values");
	scanf("%d%d%d",&a,&b,&c);
	printf("\n The values you have entered are a= %d b=%d c=%d",a,b,c);

	float avg=0;
	int sum=0;
	int rem=1;
	int prod=1;
	int toggle=5;

	//perform operations
	sum = a+b+c;
	avg=(sum/3);
	d=a/b;
	rem = a%b;
	prod=a*b*c;

	//print the results
	printf("\n the sum of 3 numbers = %d \n",sum);
	printf("\n the average of 3 numbers = %f \n",avg);
	printf("\n the division of 3 numbers = %d \n",d);
	printf("\n the remainder of 3 numbers = %d \n",rem);
	printf("\n the product of 3 numbers = %d \n",prod);

	//print the results
	printf("\n toggle value now is = %d \n",toggle);
	printf("\n toggle++ = %d \n",toggle++);
	printf("\n toggle value now is = %d \n",toggle);
        printf("\n ++toggle = %d \n",++toggle);
	printf("\n toggle value now is = %d \n",toggle);
        printf("\n toggle-- = %d \n",toggle--);
	printf("\n toggle value now is = %d \n",toggle);
        printf("\n --toggle = %d \n",--toggle);

}
