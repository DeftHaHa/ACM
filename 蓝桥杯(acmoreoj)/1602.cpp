#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> edge[10005],W[10005];
int N;
bool vis[10005];		
int End,maxd;
void dfs(int u,int w)
{
	vis[u]=true;
	if(w>maxd)
	{
		maxd=w;
		End=u;
	}
	for(int j=0;j<edge[u].size();j++)
	{
		int v=edge[u][j];
		if(!vis[v])
		{
			dfs(v,w+W[u][j]);
		}
	}
	
}
int main()
{

	int u,v,w;
	cin>>N;
	for(int i=0;i<N-1;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(v);
		W[u].push_back(w);
		edge[v].push_back(u);
		W[v].push_back(w);
	}
	maxd=0;
	memset(vis,false,sizeof(vis));
	dfs(1,0);
	memset(vis,false,sizeof(vis));
	dfs(End,0);
	cout<<10*maxd+maxd+maxd*(maxd-1)/2<<endl;
	return 0;
}
