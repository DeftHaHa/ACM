#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1005;
int dp1[MAXN][MAXN],dp2[MAXN][MAXN],dp3[MAXN][MAXN],dp4[MAXN][MAXN];
int w[MAXN][MAXN];
int main()
{
	int n,m,x,y,v,c;
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&v,&c);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&w[i][j]);
	dp1[x][y]=dp2[x][y]=dp3[x][y]=dp4[x][y]=v;
	for(int j=y-1;j>=0;j--)
	{
		if(dp1[x][j+1]>0)
		{
			dp1[x][j]=w[x][j]+dp1[x][j+1];
			if(dp1[x][j]>c) dp1[x][j]=c;
		}
		else dp1[x][j]=-1;
		dp3[x][j]=dp1[x][j];
	}
	for(int j=y+1;j<=m;j++)
	{
		if(dp2[x][j-1]>0)
		{
			dp2[x][j]=w[x][j]+dp2[x][j-1];
			if(dp2[x][j]>c) dp2[x][j]=c;
		}
		else dp2[x][j]=-1;
		dp4[x][j]=dp2[x][j];
	}
	for(int i=x-1;i>=0;i--)
	{
		if(dp1[i+1][y]>0)
		{
			dp1[i][y]=w[i][y]+dp1[i+1][y];
			if(dp1[i][y]>c) dp1[i][y]=c;
		}
		else dp1[i][y]=-1;
		dp2[i][y]=dp1[i][y];
	}
	for(int i=x+1;i<=n;i++)
	{
		if(dp3[i+1][y]>0)
		{
			dp3[i][y]=w[i][y]+dp3[i-1][y];
			if(dp3[i][y]>c) dp3[i][y]=c;
		}
		else dp3[i][y]=-1;
		dp4[i][y]=dp3[i][y];
	}
	for(int i=x-1;i>=0;i--)
	{
		for(int j=y-1;j>=0;j--)
		{
			if(dp1[i+1][j]>0||dp1[i][j+1]) 
			{
				dp1[i][j]=max(dp1[i+1][j],dp1[i][j+1])+w[i][j];
				if(dp1[i][j]>c) dp1[i][j]=c;
			}
				
			else dp1[i][j]=-1;
		}
	}
	for(int i=x-1;i>=0;i--)
	{
		for(int j=y+1;j<=m;j++)
		{
			if(dp2[i+1][j]>0||dp2[i][j-1]) 
			{
				dp2[i][j]=max(dp2[i+1][j],dp2[i][j-1])+w[i][j];
				if(dp2[i][j]>c) dp2[i][j]=c;
			}
				
			else dp2[i][j]=-1;
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		for(int j=y-1;j>=0;j--)
		{
			if(dp3[i-1][j]>0||dp3[i][j+1]) 
			{
				dp3[i][j]=max(dp3[i-1][j],dp3[i][j+1])+w[i][j];
				if(dp3[i][j]>c) dp3[i][j]=c;
			}
				
			else dp3[i][j]=-1;
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		for(int j=y+1;j<=m;j++)
		{
			if(dp4[i-1][j]>0||dp4[i][j-1]) 
			{
				dp4[i][j]=max(dp4[i-1][j],dp4[i][j-1])+w[i][j];
				if(dp4[i][j]>c) dp4[i][j]=c;
			}
				
			else dp4[i][j]=-1;
		}
	}
	int ans=-1;
	ans=max(dp1[1][1],ans);
	ans=max(dp2[1][m],ans);
	ans=max(dp3[n][1],ans);
	ans=max(dp4[n][m],ans);
	if(ans>=0) cout<<ans<<endl;
	else cout<<-1<<endl;
}
