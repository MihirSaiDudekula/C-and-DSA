#include <stdio.h>

int main() {
    int n,fact=1;
    printf("enter num for factorial");
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    {
      fact=fact*i;
    }
  printf("\n the factorial of n is %d  ",fact);
    return 0;
}
