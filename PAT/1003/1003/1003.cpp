#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
int N,m,c1,c2;
struct edge
{
	int v,next,w;
}e[250005];
int eid;
int p[250005];
void addedge(int u,int v,int w)
{
	e[eid].v=v;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
int tot;
bool vis[505];
int d[505];
int rs[505];
int M[505];
int num[505];
void dijkstra(int s)
{
	memset(d,0x3f,sizeof(d));
	memset(vis,false,sizeof(vis));
	memset(M,0,sizeof(M));
	d[s]=0;
	M[s]=rs[s];
	num[s]=1;
	tot=0;
	for(int i=0;i<N;i++)
	{
		int min_w=inf,v;
		for(int j=0;j<N;j++)
		{
			if(!vis[j]&&d[j]<min_w)
			{
				v=j;
				min_w=d[j];
			}
		}
		vis[v]=true;
		for(int j=p[v];j!=-1;j=e[j].next)
		{
			int x=e[j].v;
			int dnew=d[v]+e[j].w;
			if(!vis[x]&&dnew<d[x])
			{
				d[x]=dnew;
				num[x]=num[v];
				M[x]=M[v]+rs[x];
			}
			else if(!vis[x]&&dnew==d[x])
			{
				num[x]+=num[v];
				if(M[x]<rs[x]+M[v]) M[x]=M[v]+rs[x];
			}
		}
	}
}
int main()
{
	
	while(cin>>N>>m>>c1>>c2)
	{
		for(int i=0;i<N;i++)
			cin>>rs[i];
		eid=0;
		memset(p,-1,sizeof(p));
		int u,v,w;
		while(m--)
		{
			cin>>u>>v>>w;
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dijkstra(c1);
		cout<<num[c2]<<' '<<M[c2]<<endl;
	}
	return 0;
}