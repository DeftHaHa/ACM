#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[55][55][55][55];
int w[55][55];
//从左上角走到右下角再从右下回到左上的不重复的最大价值
//当成两个人同时从左上走到右下 ,i+j!=k+l判断同一阶段，再判断是否为同一点 
int main()
{
	memset(dp,0,sizeof(dp));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&w[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=m;l++)
				{
					if(i+j==k+l&&(i!=k||j!=l))
					{
						dp[i][j][k][l]=
						max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1])
						,max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))
						+w[i][j]+w[k][l];
					}
				}
			}
		}
	}
	cout<<max(dp[n-1][m][n][m-1],dp[n][m-1][n-1][m])<<endl;
	return 0;
}

