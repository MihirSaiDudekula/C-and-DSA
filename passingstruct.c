#include <stdio.h>
struct student
{
char name[20];
int age;
float marks;
};
void display(struct student s)
{
printf(" displaying information\n");
    printf("Name = %s\n",s.name);
    printf("Age = %d\n",s.age);
    printf("Marks = %.2f\n",s.marks);
}
int main()
{
  struct student s1;
printf("enter the name of the student ");
  scanf("%s",s1.name);
  printf("enter the age of the student ");
  scanf("%d",&s1.age);
  printf("enter the marks of the student ");
  scanf("%f",&s1.marks);
display(s1);
    return 0;
}
