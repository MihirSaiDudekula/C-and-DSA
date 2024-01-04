#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct course
{
  char cname[30];
  char sdate[30];
};
int main()
{
  FILE *of;
  of = fopen("test.txt","w");

  struct course inp1 = {"ALgorithms","30OCT"};
  struct course inp2 = {"DS","28OCT"};
  struct course inp3 = {"Programming","1OCT"};
  fwrite(&inp1,1,sizeof(struct course),of);
    fwrite(&inp2,1,sizeof(struct course),of);
    fwrite(&inp3,1,sizeof(struct course),of);
  if(fwrite !=0)
    printf("contents written succesfully");
  else
    printf("An unexpected error occured");
  fclose(of);
    
}
