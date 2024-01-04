#include <stdio.h>

int main()
{
	int q1,q2,q3,q4;
	int tq;
	int m1,m2;
	int tm;
	int fin;
	float total;
	float qperc,fperc,tperc;
	float qwt,twt,fwt;
 
	printf("\n Enter quiz 1 marks out of 100 ");
	scanf("%d",&q1);
	printf("\n Enter quiz 2 marks out of 100 ");
        scanf("%d",&q2);
	printf("\n Enter quiz 3 marks out of 100 ");
        scanf("%d",&q3);
	printf("\n Enter quiz 4 marks out of 100 ");
        scanf("%d",&q4);

	printf("\n Enter midterm 1 marks out of 100 ");
        scanf("%d",&m1);
	printf("\n Enter midterm 2 marks out of 100 ");
        scanf("%d",&m2);

	printf("\n Enter final exam marks out of 100 ");
        scanf("%d",&fin);

	tq=(q1+q2+q3+q4);
	qperc=(float)tq/4;
	qwt=(float)qperc*0.3;

	tm=(m1+m2);
	tperc=(float)tm/2;
	twt=(float)tperc*0.4;

	fperc=fin;
	fwt=(float)fperc*0.3;

	total=(float)qwt+twt+fwt;

	printf("\n=======================================================");
	printf("\n===================SCORECARD===========================");
	printf("\n=======================================================");
	printf("\n marks obtained in quiz 1 = %d ",q1);
	printf("\n marks obtained in quiz 2 = %d ",q2);
	printf("\n marks obtained in quiz 3 = %d ",q3);
	printf("\n marks obtained in quiz 4 = %d ",q4);
	printf("\n marks obtained in midterm 1 = %d ",m1);
	printf("\n marks obtained in midterm 2 = %d ",m2);
	printf("\n marks obtained in finals = %d ",fin);

	printf("\n weightage of quizzes = %f ",qwt);
	printf("\n weightage of midterms = %f ",twt);
	printf("\n weightage of finals  = %f ",fwt);
	printf("\n=======================================================");
	printf("\n GRAND TOTAL = %f",total);
	float m=total;	
	  if(m<50)
	  {
	    printf("\n GRADE RECEIVED : F GRADE");
	  }
	  else if(m>=50 && m<60)
	  {
	    printf("\n GRADE RECEIVED : D GRADE");
	  }
	  else if(m>=60 && m<70)
	  {
	    printf("\n GRADE RECEIVED : C GRADE");
	  }
	  else if(m>=70 && m<80)
	  {
	    printf("\n GRADE RECEIVED : B GRADE");
	  }
	  else if(m>=80 && m<90)
	  {
	    printf("\n GRADE RECEIVED : A GRADE");
	  }
	  else if(m>=90)
	  {
	    printf("\n GRADE RECEIVED : A+ GRADE");
	  }

	printf("\n=======================================================");



	
}
