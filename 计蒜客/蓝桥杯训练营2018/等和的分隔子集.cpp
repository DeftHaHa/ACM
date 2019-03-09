#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int sum = (1+N)*N/2; 
	int ans = 0;
	long long dp[10005];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	if(sum&1) cout<<0<<endl;
	else
	{
		sum/=2;
		for(int i = 1;i <= N;i++)
		{
			for(int j = sum;j >= i;j--)
			{
				dp[j] += dp[j-i];
			}
		}
		cout<<dp[sum]/2<<endl;
	}
	
	return 0;
}
