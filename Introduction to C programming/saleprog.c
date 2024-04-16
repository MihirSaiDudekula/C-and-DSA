#include <stdio.h>
int main()
{
	int q;
	float dr;
	float up;
	float subt;
	float subtax;
	float taxam,discam;
	float total;
	float taxrate=8.5;

	printf("\n enter the number of items sold \n");
	scanf("%d",&q);
	printf("\n enter unit price \n");
        scanf("%f",&up);
	printf("\n enter the discount rate \n");
        scanf("%f",&dr);

	subt=q*up;
	discam=(subt*dr)/100;
	subtax=subt-discam;
	taxam=(subtax*taxrate)/100;
	total=subtax+taxam;

	printf("\n quantity sold %d \n",q);
	printf("\n unit price of items %f \n",up);
	printf("\n subtotal %f \n",subt);
	printf("\n discount amount %f \n",discam);
	printf("\n discount total %f \n",subtax);
	printf("\n sales tax %f \n",taxam);
	printf("\n GRAND TOTAL %f \n",total);




	

	
	
	return 0;

}
