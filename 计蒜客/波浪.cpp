#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;\

int main()
{
	int n,m;
	int num[105][105];
	int cnt=0;
	cin>>n>>m;
	for(int j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(int i=1;i<=n;i++)
				num[i][j]=++cnt;
		}
		else
		{
			for(int i=n;i>=1;i--)
				num[i][j]=++cnt;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",num[i][1]);
		for(int j=2;j<=m;j++)
		{
			printf(" %d",num[i][j]);
		}
		printf("\n");
	}
	return 0;
}
