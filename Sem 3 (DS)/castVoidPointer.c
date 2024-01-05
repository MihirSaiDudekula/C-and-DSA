#include <stdio.h>
void process_data(void *ptr, int type);

int main()
{
    int x=10;
    char ch = 'A';
    float pi = 3.14;

    process_data(&x,1); // Passing integer by reference
    process_data(&ch,2);  // Passing character by reference
    process_data(&pi,3);  //  // Passing float by reference
    return 0;
}

void process_data(void *ptr, int dtype)
{
    switch(dtype)
    {
    case 1:
        {
        printf("Integer type data. Type-cast to integer pointer for dereferencing.\n");
        int d = *(int*)ptr;
        printf("Data is %d\n", d);
        break;
        }
    case 2:
        {
        printf("Character type data. Type-cast character pointer for dereferencing.\n");
        char d = *(char*)ptr;
        printf("Data is %c\n", d);
        break;
        }
    case 3:
        {
        printf("Float type data. Type-cast float pointer for dereferencing.\n");
        float d = *(float*)ptr;
        printf("Data is %f\n", d);
        break;
        }
    }
}
