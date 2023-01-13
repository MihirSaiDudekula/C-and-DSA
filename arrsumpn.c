#include <stdio.h>

int main() {
  int num[10],ps=0,pc=0,nc=0,zc=0,ns=0;
  printf("\n enter 10 array elements \n");
  for(int i=0;i<10;i++)
    {
      scanf("%d",&num[i]);
    }
    for(int i=0;i<10;i++)
    {
      if(num[i]>0)
      {
        pc++;
        ps=ps+num[i];
      }
      else if(num[i]<0)
      {
        nc++;
        ns=ns+num[i];
      }
      else
      {
        zc++;
      }
      
    }
printf("\nthe sum of positive integers witihn the array is %d and there are %d positive numbers",ps,pc);
  printf("\nthe sum of negative integers witihn the array is %d and there are %d positive numbers",ns,nc);
  printf("and there are %d zeroes in the array",zc);
}
