#include <stdio.h>
struct account
{
long int acc_no;
char acc_type[20];
char cust_name[20];
float balance;
char adrs[50];
long int phone;
};
void display(struct account a)
{
  printf("\n\nUSER INFO\n");
  printf("Username = %s\n",a.cust_name);  
  printf("Account type = %s\n",a.acc_type);
  printf("Account number = %ld\n",a.acc_no);
  printf("Account Balance= %.2f\n",a.balance);
  printf("Phone number = %ld\n",a.phone);
  printf("User Address = %s\n",a.adrs);  
}
float deposit(float b,float d)
{
  b=b+d;
  return b;
}
int main()
{
  struct account a1;

  printf("Enter Username\n");
  scanf("%s",a1.cust_name);
    printf("Enter Account type\n");
  scanf("%s",a1.acc_type);
      printf("Enter Account number\n");
  scanf("%ld",&a1.acc_no);
  //   printf("Enter Account Balance\n");
  // scanf("%f",a1.balance);
    printf("Enter Phone number\n");
  scanf("%ld",&a1.phone);
    printf("Enter User Address\n");
    scanf("%s",a1.adrs);

  float depo;
  a1.balance=0;
  printf("Enter Amount to be deposited \n");
  scanf("%f",&depo);
  a1.balance=deposit(a1.balance,depo);
  display(a1);


    return 0;
}
