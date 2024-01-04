#include <stdio.h>

int main() {
    int n=20;
    int n1=0;
    int n2=1;
  int i=0;
  int fib=0;
  printf("\n %d",n1);
  printf("\n %d",n2);
    while(i<=n)
      {
        fib=n1+n2;
        n1=n2;
        n2=fib;
        
        printf("\n %d",fib);
        i++;
      }
    return 0;
}
  
