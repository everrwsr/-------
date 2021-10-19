//3.15
#include "stdio.h"
int g1(int m,int n)
{
	if(m==0&&n>=0)
	return 0;
	else
	if(m>0&&n>=0)
	return (g(m-1,2*n)+2);
	else
	return -1;
}
	else
	return -1;
	
}
int main()
{
	int m,n,c;
	printf("«Î ‰»Îm=  «Î ‰»În= \n ");
	scanf("%d %d",&m,&n);
	c=g1(m,n);
	printf("  \ng1(m,n)=""%d",c);
}
