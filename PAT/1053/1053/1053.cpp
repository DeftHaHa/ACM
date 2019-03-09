#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct edge
{
	int v,next;
}e[10005];
int p[10005],eid;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int N,M,S;
bool isleaf[105],vis[105];
int w[105],W;
int path[105],tot,anstot=0;
struct answer
{
	string s;
	vector<int> path;
}ans[1005];
void dfs(int u)
{
	vis[u]=true;
	W+=w[u];
	path[++tot]=u;
	if(W==S&&isleaf[u])
	{
		for(int i=0;i<=tot;i++)
		{
			int temp=w[path[i]];
			ans[anstot].path.push_back(temp);
			ans[anstot].s+='0'+temp;
		}
		anstot++;
	}
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if(!vis[v])
		{
			dfs(v);
		}
	}
	W-=w[u];
	tot--;
	vis[u]=false;
}
bool cmp(const answer &a,const answer &b)
{
	return a.s>b.s;
}
int main()
{
	cin>>N>>M>>S;
	for(int i=0;i<N;i++) scanf("%d",&w[i]);
	memset(p,-1,sizeof(p));
	memset(isleaf,true,sizeof(isleaf));
	eid=0;
	int n,u,v;
	while(M--)
	{
		scanf("%d%d",&u,&n);
		isleaf[u]=false;
		while(n--)
		{
			scanf("%d",&v);
			addedge(u,v);
		}
	}
	memset(vis,false,sizeof(vis));
	W=0;
	tot=-1;
	dfs(0);
	sort(ans,ans+anstot,cmp);
	for(int i=0;i<anstot;i++)
	{
		printf("%d",ans[i].path[0]);
		for(int j=1;j<ans[i].path.size();j++)
		{
			printf(" %d",ans[i].path[j]);
		}
		cout<<endl;
	}
	return 0;
}