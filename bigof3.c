#include <stdio.h>
int main()
{
	int a,b,c;
	printf("enter three numbers to check for the larger number");
	scanf("%d%d%d",&a,&b,&c);
	int big,smol;
	big = (a>b && a>c)?a:((b>a && b>c)?b:c);
	printf("\n larger value is %d ",big);
	//smol = (a<b)?a:b;
        //printf("\n smaller value is %d ",smol);
	return 0;


}	
	




