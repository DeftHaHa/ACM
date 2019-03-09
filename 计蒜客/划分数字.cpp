#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	long long dp[305][305];
	memset(dp,0,sizeof(dp));
	int n,K;
	cin>>n>>K;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=K;k++)
			{
				dp[j][k]+=dp[j-i][k-1];
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=K;i++) ans+=dp[n][i];
	cout<<ans<<endl;
	return 0;
}
