
#include <stdio.h>

int main() {

  int n[10];

  printf("Enter 5 integers: ");

  // taking input and storing it in an array
  for(int i = 0; i < 10; ++i) {
     scanf("%d", &n[i]);
  }

  printf("Displaying integers: ");

  // printing elements of an array
  for(int i = 0; i < 10; ++i) {
     printf("%d\n", n[i]);
  }
  return 0;
}

