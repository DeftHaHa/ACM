#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*2+1;i++)
	{
		if(i&1)
		{
			for(int j = 1;j <= m*2+1;j++)
			{
				if(j&1) printf("+");
				else printf("-");
			}
		}
		else
		{
			for(int j = 1;j <= m*2+1;j++)
			{
				if(j&1) printf("|");
				else printf("*");
			}
		}
		printf("\n");
	}
	
	return 0;
}
