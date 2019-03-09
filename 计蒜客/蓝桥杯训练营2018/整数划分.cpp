#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long mod = 1e9+9;
int main()
{
	int M;
	long long dp[100005];
	cin>>M;
	int n;
	while(M--)
	{
		cin>>n;
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i;j <= n;j++)
			{
				dp[j] = (dp[j]+dp[j-i])%mod;
			}
		}
		cout<<dp[n]<<endl;
	}
	
	return 0;
}
