#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
//长度不超过50且连续0和1长度不超过10的01字符串有多少种 
using namespace std;
int main()
{
	long long dp[55][3][15];
	memset(dp,0,sizeof(dp));
	dp[1][0][1]=dp[1][1][1]=1;
	for(int i=2;i<=50;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=1;k<=min(10,i);k++)
			{
				dp[i][j][k]+=dp[i-1][j][k-1];
				dp[i][j][1]+=dp[i-1][1-j][k];
			}
		}
	}
	long long ans=0;
	for(int j=0;j<2;j++)
		for(int k=1;k<=10;k++)
			ans+=dp[50][j][k];
	cout<<ans<<endl;
	return 0;
}
