#include <stdio.h>

/*structure declaration*/
struct employee{
    char name[30];
    int empId;
    float salary;
    char dept_name[30];
};

int main()
{
    /*declare structure variable*/

    int nemp;
    printf("\n Enter the number of employees\n");
    scanf("%d",&nemp);

    struct employee emp[nemp];

    /*read employee details*/
    for(int i=0;i<nemp;i++)
    {
        printf("\nEnter details :\n");
        printf("\nName ?:\n");
        scanf("%s", emp[i].name);
        printf("\nID ?:\n");
        scanf("%d",&emp[i].empId);
        printf("\nSalary ?:\n");
        scanf("%f",&emp[i].salary);
        printf("\ndepartment Name ?:\n");
        scanf("%s", emp[i].dept_name);

    }


    /*print employee details*/
    for(int i=0;i<nemp;i++)
    {
        printf("\nEntered detail is:");
        printf("\nName: %s"   ,emp[i].name);
        printf("\nId: %d"     ,emp[i].empId);
        printf("\nSalary: %f\n",emp[i].salary);
        printf("\ndepartment Name: %s"   ,emp[i].dept_name);
    }
    return 0;
}
