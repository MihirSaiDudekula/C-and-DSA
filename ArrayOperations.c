#include <stdio.h>
void main()
{
        int n,choice,ele,pos;
        printf("enter no of elements");
        scanf("%d",&n);
        int arr[10];
        printf("enter choice of operation");
        scanf("%d",&choice);
        printf("\n this is a suitable heading \n");
        for(int i=0;i<n;i++)
        {
                scanf("%d",&arr[i]);
        }
        if(choice>0 && choice<6)
        {
                switch(choice)
                {
                        case 1:

                                printf("\n enter the element and position at which we must insert\n");
                                scanf("%d %d",&ele,&pos);
                                n++;
                                for(int i=n-1;i>=(pos-1);i--)
                                {
                                        arr[i]=arr[i-1];

                                }
                                arr[pos-1]=ele;
                                for(int i=0;i<n;i++)
                                {
                                        printf("%d",arr[i]);
                                }
                                break;
                        case 2:

                                printf("\n enter the element and position at which we must delete\n");
                                scanf("%d",&pos);
                                for(int i=(pos-1);i<n;i++)
                                {
                                        arr[i]=arr[i+1];

                                }
                                n--;
                                for(int i=0;i<n;i++)
                                {
                                        printf("%d",arr[i]);
                                }
                                break;




                }
        }

}
