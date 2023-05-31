int rootof(int n)
{
  return (int)sqrt(n);
}
int prime(int num,int root)
{
  int i,c=0;
  for(i=2;i<root;i++)
    {
      if(num%i==0)
      {
        c++;
      }
    }
  if(c==0)
  {
    return 1;
  }
  if(c>0)
  {
    return 0;
  }
}
int main() {
    // printf("Hello, world!");
  int b=16,c;
  int d;
  c=rootof(b);
  d=prime(b,c);
  if(d==1)
  {printf("Prime number");}
  if(d==0)
  {printf("composite number");}  
  printf("\n%d\n",c);
    return 0;
}
