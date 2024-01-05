#include <stdio.h>
void square(int *ptr);

int main()
{
    int x=10;
    // Call by value
    square1(x);
    printf("After square1() call: x = %d\n",x);

    // Call by reference
    square2(&x);
    printf("After square2() call: x = %d\n",x);
    return 0;
}

void square1(int d)
{
    d = d * d;
}

void square2(int *px)
{
    *px = *px * *px;
}


//using pointers
#include<stdio.h>
struct stud{
    char name[20];
    int usn;
    float cgpa;
};

// Defining alternate name for student using typedef
typedef struct stud  student;

void process_data(student *sptr);

int main()
{
    student s = {"Amit",100,8.5};
    process_data(&s);  // Call by reference
    return  0;
}

void process_data(student *sptr)
{
    // Print using structure pointer
    printf("Name: %s   USN:%d  %.2f\n", sptr->name, sptr->usn, sptr->cgpa);
}
