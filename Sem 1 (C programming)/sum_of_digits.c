#include <stdio.h>

int main() {
  int n;
  int r=0;
  int s=0;
  printf("enter any number ");
  scanf("%d",&n);

  while(n>0)
    {
      r=n%10;
      s=s+r;
      n=n/10;
      
    }
  printf("%d",s);


  
    return 0;
}
