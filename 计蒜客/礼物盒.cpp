#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int h[40],w[40];
int dp[105];
int main()
{
	for(int i=1;i<=36;i++) scanf("%d%d",&w[i],&h[i]);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=36;i++)
	{
		if(h[i]<=20)
		{
			for(int j=100;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+1);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=100;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}
