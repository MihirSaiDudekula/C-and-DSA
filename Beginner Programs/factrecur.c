#include <stdio.h>
int fact(int n)
{
  if(n==0)
    return 1;
  else
    return n*fact(n-1);
}
int main()
{
  int n=5,f=1;
  f=fact(n);
  printf("%d",f);
  return 0;
}
