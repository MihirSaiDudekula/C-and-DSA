#include <stdio.h>

int main() {
int x=5;
  int y=7;
int *p;
  int *q;
p=&x;
  q=&y;
  int sum=*p+*q;
printf("%d",sum);  
  printf("%d",p);
}
