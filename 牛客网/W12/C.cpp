#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[100005];
int d[100005];
int dp[100005][15][2];
int n,m;
int main()
{
	cin>>n>>m;
	memset(s,0,sizeof(s));
	scanf("%s",s);
	memset(d,0,sizeof(d));
	int cnt=0,tag;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			tag=i;
			break;
		}
	}
	d[0]=1;
	for(int i=tag+1;i<n;i++)
	{
		if(s[i-1]!=s[i])
		{
			d[++cnt]=1;
		}
		else d[cnt]++;
	}
	int ans=0;
	if(m==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(cnt<=m)
	{
		cout<<n-tag<<endl;
		return 0;
	}
	dp[0][0][0]=d[0];
	for(int i=1;i<=cnt;i++)
	{
		if(i&1) dp[i][0][0]=dp[i-1][0][0];
		else dp[i][0][0]=dp[i-1][0][0]+d[i];
		for(int j=1;j<=m;j++)
		{
			if(i&1)
			{
				dp[i][j][1]=max(dp[i-1][j][1]+d[i],dp[i-1][j-1][0]+d[i]);
				dp[i][j][0]=dp[i-1][j][0];
			}
			else
			{
				dp[i][j][0]=max(dp[i-1][j][0]+d[i],dp[i-1][j-1][1]+d[i]);
				dp[i][j][1]=dp[i-1][j][1];
			}
		}
	}
	ans=dp[cnt][0][0];
	for(int i=1;i<=m;i++)
	{
		ans=max(ans,dp[cnt][i][0]);
		ans=max(ans,dp[cnt][i][1]);
	}
	cout<<ans<<endl;
	return 0;
} 
