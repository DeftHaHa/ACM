#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge
{
	int v,next;
	int w,f;
}e[250005];
int eid,p[250005];
void addedge(int u,int v,int w,int f)
{
	e[eid].v = v;
	e[eid].w = w;
	e[eid].f = f;
	e[eid].next = p[u];
	p[u] = eid++;
}
int dis[505],fee[505];
bool vis[505];
struct cmp
{
	bool operator() (int a,int b)const
	{
		return dis[a] > dis[b];
	}
};
priority_queue<int,vector<int>,cmp> q;
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(fee,0x3f,sizeof(fee));
	memset(vis,false,sizeof(vis));
	while(!q.empty()) q.pop();
	dis[s] = 0;
	fee[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int u = q.top();
		q.pop();
		vis[u] = true;
		if(dis[u] == INF) return;
		for(int i = p[u];i != -1;i=e[i].next)
		{
			int v = e[i].v;
			if(!vis[v])
			{
				int newd = e[i].w + dis[u];
				if(newd < dis[v])
				{
					dis[v] = newd;
					fee[v] = e[i].f + fee[u];
				}
				else if(newd == dis[v]) fee[v] = min(fee[v],fee[u] + e[i].f);
				q.push(v);
			}
		}
	}
}
int main()
{
	int N,M,S,D;
	scanf("%d%d%d%d",&N,&M,&S,&D);
	memset(p,-1,sizeof(p));
	eid = 0;
	int u,v,w,f;
	for(int i = 0;i < M;i++)
	{
		scanf("%d%d%d%d",&u,&v,&w,&f);
		addedge(u,v,w,f);
		addedge(v,u,w,f);
	}
	dijkstra(S);
	printf("%d %d\n",dis[D],fee[D]);
	
	return 0;
}
