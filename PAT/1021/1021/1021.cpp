#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<int> e[10005];
int d[10005],maxd=0;
bool vis[10005];
queue<int> q;
void bfs(int s)
{
	d[s]=0;
	maxd=0;
	memset(vis,false,sizeof(vis));
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=true;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			if(!vis[v])
			{
				q.push(v);
				d[v]=d[u]+1;
				maxd=max(maxd,d[v]);
			}
		}
	}
}
void dfs(int u)
{
	vis[u]=true;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(!vis[v])
		{
			dfs(v);
		}
	}
}
int main()
{
	int N;
	while(cin>>N)
	{
		int u,v;
		int t=N-1;
		while(t--)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		memset(vis,false,sizeof(vis));
		int tot=0;
		for(int i=1;i<=N;i++)
		{
			if(!vis[i])
			{
				dfs(i);
				tot++;
			}
		}
		if(tot==1)
		{
			bfs(1);
			set<int> ans;
			int temp;
			for(int i=1;i<=N;i++)
			{
				if(maxd==d[i]) {ans.insert(i);temp=i;}
			}
			bfs(temp);
			for(int i=1;i<=N;i++)
			{
				if(maxd==d[i]) ans.insert(i);
			}
			for(set<int>::iterator it=ans.begin();it!=ans.end();it++) printf("%d\n",*it);
		}
		else printf("Error: %d components\n",tot);
	}
	return 0;
}