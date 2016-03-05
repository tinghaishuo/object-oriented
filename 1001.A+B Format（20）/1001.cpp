#include<stdio.h>
int main()
{
	int a,b,c,p,q,k;
	scanf("%d %d",&a,&b);
	getchar();
	c=a+b;
	if(c<0)
	{
		c=-c;
		printf("-");
	}
	if(c/1000000==0)
	{
		if(c/1000==0)
		{
			printf("%d",c);
		}
		else if(c/1000!=0)
		{
			p=c/1000;
			q=c-1000*p;
			printf("%d,%03d",p,q);
		}
	}
	else 
	{
		p=c/1000000;
		q=(c-1000000*p)/1000;
		k=c-1000000*p-1000*q;
		printf("%d,%03d,%03d",p,q,k);
	}
	return 0;
	
	
}
