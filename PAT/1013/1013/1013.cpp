#include<iostream>
#include<cstring>
using namespace std;
bool m[1005][1005];
int N,M,K;
bool vis[1005];
void dfs(int u)
{
	vis[u]=true;
	for(int i=1;i<=N;i++)
	{
		if(!vis[i]&&m[u][i])
			dfs(i);
	}
}

int main()
{
	while(cin>>N>>M>>K)
	{
		int u,v;
		memset(m,false,sizeof(m));
		while(M--)
		{
			cin>>u>>v;
			m[u][v]=true;
			m[v][u]=true;
		}
		while(K--)
		{
			memset(vis,false,sizeof(vis));
			int q;
			cin>>q;
			vis[q]=true;
			int ans=0;
			for(int i=1;i<=N;i++)
			{
				if(!vis[i])
				{
					ans++;
					dfs(i);
				}
			}
			cout<<ans-1<<endl;
		}
	}
	return 0;
}