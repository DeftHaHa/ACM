#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long MOD=1000000007;
long long dp[55][55][15][15];
int maze[55][55];
int n,m,k;
int dfs(int x,int y,int tot,int maxw)
{
	if(dp[x][y][tot][maxw+1]!=-1) return dp[x][y][tot][maxw+1];   //数组存maxw+1防止越界  
	long long way=0;
	if(x==n&&y==m)
	{
		if(tot==k) way++;
		else if(tot==k-1&&maze[x][y]>maxw) way++;
	}
	else
	{
		if(x<n)
		{
			if(maze[x][y]>maxw) way+=dfs(x+1,y,tot+1,maze[x][y]);
			way%=MOD;
			way+=dfs(x+1,y,tot,maxw);
			way%=MOD;
		}
		if(y<m)
		{
			if(maze[x][y]>maxw) way+=dfs(x,y+1,tot+1,maze[x][y]);
			way%=MOD;
			way+=dfs(x,y+1,tot,maxw);
			way%=MOD;
		}
	}
	return dp[x][y][tot][maxw+1]=way;
}
int main()
{
	//freopen("DATA.txt","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&maze[i][j]);
	memset(dp,-1,sizeof(dp));   
	dfs(1,1,0,-1);
	cout<<dp[1][1][0][0]<<endl;
	return 0;
}
