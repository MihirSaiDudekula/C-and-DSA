#include <stdio.h>
struct student
{
int roll;
char name[20];
float marks[3];
float percent;
};
int main() {
  struct student s[3];
  for(int i=0;i<3;i++)
    {
        printf("\n enter the roll no of the student\n");
        scanf("%d",&s[i].roll);
        printf("\n enter the name of the student\n");
        scanf("%d",&s[i].roll);
       printf("\n enter the marks of the student in 3 subjects\n");
        for(int j=0;j<3;j++)
          {
            scanf("%f",&s[i].marks[j]);
          }
        
        
        
    }
  printf("\nRoll no\tname\tmarks\tpercentage");
  for(int i=0;i<3;i++)
  {
	  printf("%d\t\t%s\t%.2f\t%.2f\n",s[i].roll,s[i].name,(s[i].marks[0]+s[i].marks[1]+s[i].marks[2]),(((s[i].marks[0]+s[i].marks[1]+s[i].marks[2])/3)*100));
  
  
  }


    return 0;
}
