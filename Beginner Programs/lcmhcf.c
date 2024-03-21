#include <stdio.h>
void lcm_gcd(int n1,int n2)
{
  int gcd,lcm,rem,num,denom;
  num=(n1>n2)?n1:n2;
  denom=(n1<n2)?n1:n2;
        
  while(rem!=0)
    {
      num=denom;
      denom=rem;
      rem=num%denom;      
    }
  gcd=denom;
  lcm=(n1*n2)/gcd;

  printf("GCD id %d",gcd);
  printf("LCM id %d",lcm);
}
void main()
{
  int a,b;
  printf("enter 2 numbers");
  scanf("%d%d",&a,&b);
  lcm_gcd(a,b);
}
