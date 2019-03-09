#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int mp[1005][20];
int mapping(int floor,int k)
{
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		if(k>>i&1)
		{
			if(!mp[floor][i]) return -1;
			cnt++;
		}
	}
	return cnt;
}
bool pro[2][20];
bool linecheck(int j,int k)
{
	memset(pro,false,sizeof(pro));
	for(int i=0;i<m;i++)
	{
		if(k>>i&1)
		{
			pro[0][i]=pro[0][i+1]=pro[0][i+2]=true;
		}
		if(j>>i&1)
		{
			pro[0][i+1]=true;
		}
	}
	for(int jj=1;jj<=m;jj++)
	{
		if(!pro[0][jj]) return false;
	}
	return true;
}
bool lastcheck(int j,int k)
{
	memset(pro,false,sizeof(pro));
	for(int i=0;i<m;i++)
	{
		if(k>>i&1)
		{
			pro[0][i]=pro[0][i+1]=pro[0][i+2]=true;
		}
		if(j>>i&1)
		{
			pro[1][i]=pro[1][i+1]=pro[0][i+1]=pro[1][i+2]=true;
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int jj=1;jj<=m;jj++)
		{
			if(!pro[i][jj]) return false;
		}
	}
	return true;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=n-1;j>=0;j--)
			scanf("%d",&mp[i][j]);
	int maxj=1<<m;
	int dp[1005][maxj+5];
	bool corr[1005][maxj+5];
	memset(corr,false,sizeof(corr));
	memset(dp,0x3f,sizeof(dp));
	for(int j=0;j<maxj;j++)
	{
		dp[0][j]=0;
		corr[0][j]=true;
	}
	int ans=0x3f3f3f3f;
	for(int j=0;j<maxj;j++)
	{
		int cnt=mapping(1,j);
		if(cnt!=-1)
		{
			dp[1][j]=cnt;
			corr[1][j]=true;
		}
	} 
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<maxj;j++)
		{
			int cnt=mapping(i,j);
			if(cnt!=-1)
			{
				corr[i][j]=true;
				for(int k=0;k<maxj;k++)
				{
					if(corr[i-1][k]&&linecheck(j,k))
					{
						dp[i][j]=min(dp[i][j],dp[i-1][k]+cnt);
						if(i==n&&lastcheck(j,k))
						{
							ans=min(dp[i][j],ans);
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
