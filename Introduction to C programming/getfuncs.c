#include <stdio.h>

int main () {
   char str[50];
   char ch;
  int i=0;

   printf("Enter a string : ");
   // str=getchar();
  while(ch != ' ')
    {
      ch= getchar();
      str[i]=ch;
      i++;
    }

   // printf("You entered: %s", str);
  int j=0;
  while(str[j] != ' ')
    {
      putchar(str[j]);
      j++;
    }
  puts(str);

   return(0);
}
