#include <stdio.h>

	int main()
	{
		int i,n,k;
		scanf("%d %d",&n,&k);
		
		for(i=1;i<=n;i++)
		{
			if((k+5*s(i))<=240)
			continue;
			else 
			break;
		}
		
		printf("%d ",i-1);
		
	}


	int s(int num)
	{
		return num*(num+1)/2;
	}