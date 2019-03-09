#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> e[20005];
int match[20005];
bool vis[20005];
bool dfs(int u)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(!vis[v])
		{
			vis[v]=true;
			if(match[v]==-1||dfs(match[v]))
			{
				match[v]=u;
				return true;
			}
		}
			
	}
	return false;
}
int main()
{
	int n,k;
	memset(match,-1,sizeof(match));
	cin>>n;
	int u,v;
	for(int u=1;u<=n;u++)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&v);
			v+=10000;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		ans+=dfs(i);
	}    // for(int i=1;i<=n;i++) cout<<i<<' '<<match[i]<<endl;
	cout<<ans<<endl;
	return 0;
}
