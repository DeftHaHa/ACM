#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char Map[2000005];
bool vis[2000005];
int n,m;
void dfs(int x)
{
	vis[x] = true;
	int row = x/m+1;
	int col = x%m;
	if(col == 0)
	{
		row--;
		col = m;
	}
	if(row!=1&&!vis[x-m]&&Map[x-m]!='#') dfs(x-m);
	if(row!=n&&!vis[x+m]&&Map[x+m]!='#') dfs(x+m);
	if(col!=1&&!vis[x-1]&&Map[x-1]!='#') dfs(x-1);
	if(col!=m&&!vis[x+1]&&Map[x+1]!='#') dfs(x+1);
}
int main()
{
	memset(Map,'#',sizeof(Map));
	cin>>n>>m;
	getchar();
	for(int i = 1;i <= n ;i++)
	{
		int tag = (i-1)*m;
		for(int j = 1;j <= m;j++)
		{
			scanf("%c",&Map[++tag]);
		}
		getchar();
	}
	memset(vis,false,sizeof(vis));
	for(int i = 1;i <= n;i++)
	{
		if(Map[(i-1)*m+1]!='#'&&!vis[(i-1)*m+1]) dfs((i-1)*m+1);
		if(Map[i*m]!='#'&&!vis[i*m]) dfs(i*m);
	}
	for(int i = 1;i <= m;i++) if(Map[i]!='#'&&!vis[i]) dfs(i);
	for(int i = (n-1)*m+1;i <= n*m;i++) if(Map[i]!='#'&&!vis[i]) dfs(i);
	int ans = 0;
	for(int i = 1;i <= n*m ;i++)
	{
		if(Map[i]=='#'||!vis[i]) ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}


