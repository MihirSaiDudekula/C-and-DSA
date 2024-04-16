#include <stdio.h>
#include <string.h>
struct Person
{
  char name[20];
  float salary;
}mihir,p[20];

int main()
{
    printf("Hello, World!\n");
    strcpy(mihir.name,"Mihir Sai");
    mihir.salary=2500;
    printf("the name of the person is %s\n",mihir.name);
    printf("%f",mihir.salary);
    prinitf("enter the name of the first person");
    fgets(p[1].name,30, stdin);
    printf("%s\n",p[1].name);
}

