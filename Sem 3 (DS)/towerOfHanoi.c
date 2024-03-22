#include <stdio.h>


void toh(int n,char source,char spare,char dest)
{
    if(n==1)
    {
        printf("\n Moved %c to %c ",source,dest);
        return;
    }
    toh(n-1,source,dest,spare);
    toh(1,source,spare,dest);
    toh(n-1,spare,source,dest);
}
int main()
{
  int n=4;
  toh(n,'A','B','C');
}
