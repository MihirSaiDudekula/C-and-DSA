#include <stdio.h>
int main()
{
	int n=4;
	int bin=0;
	if(n%2==0){
		if(n%4==0)
		{
			if(n%8==0)
			{
				bin=bin+1000;
				break;

			
			}

			bin=bin+100;
			break;
		
		
		}

		bin=bin+10;
		break;
	}
	if(n%2!=0)
	{
		n=n-1;
		bin=bin+1;

		        if(n%2==0){
                if(n%4==0)
                {
                        if(n%8==0)
                        {
                                bin=bin+1000;

                        }

                        bin=bin+100;


                }

                bin=bin+10;
        }
	
	}
	
	printf("\n %d",bin);
	return 0;

}
