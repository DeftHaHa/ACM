#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
struct edge
{
	int next,v;
}e[250005];
int eid,p[250005];
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
bool vis[505],same=false;
queue<int> q;
int color[505];
void bfs(int s)
{
	memset(vis,false,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push(s);
	vis[s]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=p[u];i!=-1;i=e[i].next)
		{
			if(color[e[i].v]==color[u]) {same=true;return;}
			if(!vis[e[i].v])
			{
				vis[e[i].v]=true;
				q.push(e[i].v);
			}
		}
	}
}
int main()
{
	int E,V,K;
	int u,v;
	set<int> C;
	while(cin>>E>>V>>K)
	{
		eid=0;
		memset(p,-1,sizeof(p));
		while(V--)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		int N;
		cin>>N;
		while(N--)
		{
			same=false;
			C.clear();
			for(int i=1;i<=E;i++)
			{
				scanf("%d",&color[i]);
				C.insert(color[i]);
			}
			if(C.size()>K) same=true;
			else bfs(1);
			if(same) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}