#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int dp[35][35];
	int n,m;
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	dp[0][1]=1;
	for(int i=1;i<=m;i++)
	{
		dp[i][1]+=dp[i-1][2]+dp[i-1][n];
		dp[i][n]+=dp[i-1][n-1]+dp[i-1][1];
		for(int j=2;j<=n-1;j++)
		{
			dp[i][j]+=dp[i-1][j-1]+dp[i-1][j+1];
		}
	}
	cout<<dp[m][1]<<endl;
	return 0;
}
