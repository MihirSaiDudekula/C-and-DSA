#include<stdio.h>
struct stud{
    char name[20];
    int usn;
    float cgpa;
};

int main()
{
    struct stud s = {"Amit",100,8.5};
    struct stud *sptr = &s;

    // Print using structure variable
    printf("Name: %s   USN:%d  %.2f\n", s.name,s.usn,s.cgpa);

    // Print using structure pointer
    printf("Name: %s   USN:%d  %.2f\n", sptr->name,sptr->usn,sptr->cgpa);
    return  0;
}
