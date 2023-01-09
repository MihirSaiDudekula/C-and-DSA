//program for printf
//program for scanf function
#include <stdio.h>
//main function
int main(){
	//local variable declaration
	int c,a,b;
	int sum=0;
	int div=1;
	int mul=0;
	//read values for these variables
	printf("\nenter values for three variables\n");
	scanf("%d%d%d",&a,&b,&c);
	//add values
	sum=a+b+c;
	printf("\nthe summation of three variables %d %d and %d is %d \n",a,b,c,sum);
	printf("\n ASCII value of char A is %d \n",'A');
	return 0;
}


