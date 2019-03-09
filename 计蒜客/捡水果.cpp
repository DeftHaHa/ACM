#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int w[1005][1005];
int dp[1005][1005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	dp[1][1]=w[1][1];
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=w[i][1]+dp[i-1][1];
		dp[i][i]=w[i][i]+dp[i-1][i-1];
		for(int j=2;j<=i-1;j++)
		{
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+w[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
