#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	int mat[205][205];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mat[i][j]);
	int ans[205][205];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans[j][n-i+1]=mat[i][j];
		}
	}
	swap(n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mat[i][j]=ans[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",mat[i][1]);
		for(int j=2;j<=m;j++)
		{
			printf(" %d",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
