#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
long long dp[35][35];
int main()
{
	int n,m;
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	dp[0][1] = 1;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(j==1) dp[i][j] = dp[i-1][2] + dp[i-1][n];
			else if(j==n) dp[i][j] = dp[i-1][n-1] + dp[i-1][1];
			else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
		//	cout<<dp[i][j]<<' ';
		}//cout<<endl;
	}
	cout<<dp[m][1]<<endl;
	return 0;
}
