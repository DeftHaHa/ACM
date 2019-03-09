#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int p[1005];
	int m;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>p[i];
	cin>>m;
	int dp[1005];
	memset(dp,0,sizeof(dp));
	dp[m] = 1;
	if(m < 5) cout<<m<<endl;
	else
	{
		int ans = 0x3f3f3f3f;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 5;j <= m;j++)
			{
				if(dp[j]) ans = min(ans,j-p[i]); 
			}
			for(int j = 5;j <= m-p[i];j++)
			{
				dp[j] |= dp[j+p[i]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
