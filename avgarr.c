#include <stdio.h>

void main() {
	int n,i;
	int num[10],sum=0;
	float avg=0.0;
	printf("Enter the array elements - 10");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&num[i]);
		sum=sum+num[i];	
	}
	
	avg=(float)sum/10;
	printf("\n the average of all entered values is %f",avg);

}
  
