#include <stdio.h>

int main() {
    int m;
  printf("\n enter your marks  ");
  scanf("%d",&m);
  if(m<50)
  {
    printf("F GRADE");
  }
  else if(m>=50 && m<60)
  {
    printf("D GRADE");
  }
  else if(m>=60 && m<70)
  {
    printf("C GRADE");
  }
  else if(m>=70 && m<80)
  {
    printf("B GRADE");
  }
  else if(m>=80 && m<90)
  {
    printf("A GRADE");
  }
  else if(m>=90)
  {
    printf("A+ GRADE");
  }
    return 0;
}
