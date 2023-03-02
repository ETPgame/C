#include <stdio.h>
#include<math.h>
int main()
{
	int i,k,a,b,c,j,t,sum,count,min;
	int m,n,temp,l;
	int shu[1000];
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		temp=0;
		scanf("%d",&min);
		for(j=1;j<=5;j++)
		{
			scanf("%d",&shu[j]);
			
		}
		for(j=1;j<=5;j++)
		{
			if(min>shu[j])
			{
				temp+=shu[j];
			}
		}
		printf("%d\n",temp);
	}

	return 0;
}
