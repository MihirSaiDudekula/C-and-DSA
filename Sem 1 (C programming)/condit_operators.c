#include <stdio.h>
int main()
{
	int a=5,b=5,c=10,r=0;
	r=(a==b)&&(c>b);
	printf("\n %d",r);
	r=(a==b)&&(c<b);
        printf("\n %d",r);
	r=(a==b)||(c>b);
        printf("\n %d",r);
	r=(a==b)||(c<b);
        printf("\n %d \n",r);

	r=(a!=b)&&(c>b);
        printf("\n %d",r);
        r=(a!=b)&&(c<b);
        printf("\n %d",r);
        r=(a!=b)||(c>b);
        printf("\n %d",r);
        r=(a!=b)||(c<b);
        printf("\n %d \n",r);



	return 0;
}
