#include <stdio.h>

int main()
{
	int x =10;
	int *px=&x;
	int **ppx=&px;

	printf("\nthe value of *px is %d",*px);
    printf("\nthe value of *ppx is %d",**ppx);
    printf("\nthe address of px is %p",px);
    printf("\nthe address of ppx is %p",ppx);

    **ppx=999;
    printf("\nthe value of x is %d",x);
	return 0;
}