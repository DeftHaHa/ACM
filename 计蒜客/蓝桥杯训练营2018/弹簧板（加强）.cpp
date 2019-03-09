#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a[100005],dp[100005];
int main()
{
	int n;
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		if(!dp[i]) dp[i] = 1;
		if(i + a[i] > n) ans = max(ans,dp[i]);
		else dp[i+a[i]] = max(dp[i+a[i]],dp[i] + 1);
	}
	cout<<ans<<endl;
	return 0;
}
