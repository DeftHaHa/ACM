#include<iostream>
#include<cstring>
using namespace std;
struct edge
{
	int v,next;
}e[105];
int eid;
int p[105];
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int d[105];
int q[105],head,tail;
bool vis[105];
int c[105];
int dmax=0;
void bfs(int s)
{
	d[s]=0;
	memset(vis,false,sizeof(vis));
	memset(c,0,sizeof(c));
	vis[s]=true;
	head=tail=0;
	q[tail]=s;
	tail++;
	while(head<tail)
	{
		int u=q[head];
		head++;
		for(int i=p[u];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(!vis[v])
			{
				c[u]++;
				d[v]=d[u]+1;
				q[tail]=v;
				tail++;
				if(d[v]>dmax) dmax=d[v];
			}
		}
	}
}
int main()
{
	int N,M;
	while(cin>>N>>M)
	{
		int u,v,m;
		eid=0;
		memset(p,-1,sizeof(p));
		bool leaf[105];
		memset(leaf,true,sizeof(leaf));
		while(M--)
		{
			cin>>u>>m;
			leaf[u]=false;
			while(m--)
			{
				cin>>v;
				addedge(u,v);
			}
		}
		bfs(1);
		int ans=0,j;
		for(j=1;j<=N;j++)
		{
			if(d[j]==0&&c[j]==0)
				ans++;
		}
		cout<<ans;
		for(int i=1;i<=dmax;i++)
		{
			ans=0;
			for(j=1;j<=N;j++)
			{
				if(d[j]==i&&c[j]==0)
					ans++;
			}
			cout<<' '<<ans;
		}
		cout<<endl;
	}
	return 0;
}