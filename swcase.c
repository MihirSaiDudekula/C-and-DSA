#include <stdio.h>

int main() {
    int num1,num2;
    char opt;
  printf("\n Enter the first number");
  scanf("%d",&num1);
  printf("Enter the second number");
  scanf("%d",&num2);
  printf("\nenter your operation choice");
  //printf("\n 1-add 2-subtract 3-multipply 4-divide");
  scanf(" %c",&opt);
  switch(opt)
  {
	case '+':
		  printf("\n the sum is %d",(num1+num2)); break;
	case '-':
                  printf("\n the subtract is %d",(num1-num2)); break;
	case '*':
                  printf("\n the prod is %d",(num1*num2)); break;
	case '/':
                  printf("\n the division is %f",(float)num1/num2); break;
	default:
                  printf("\n error in input");
  }
    return 0;
}

