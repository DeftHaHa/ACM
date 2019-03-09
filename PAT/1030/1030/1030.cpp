#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
const int inf=0x3f3f3f3f;
int N,M,S,D;
struct edge
{
	int v,next,w,c;
}e[250005];
int p[250005],eid;
void addedge(int u,int v,int w,int c)
{
	e[eid].w=w;
	e[eid].c=c;
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int d[505],cost[505],mincost=inf,path[505];
bool vis[505];
stack<int> ans;
void dijkstra(int s)
{
	memset(vis,false,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	cost[s]=0;
	for(int i=0;i<N;i++)
	{
		int min_w=inf,u,j;
		for(j=0;j<N;j++)
		{
			if(!vis[j]&&d[j]<min_w)
			{
				u=j;
				min_w=d[j];
			}
		}
		vis[u]=true;
		for(j=p[u];j!=-1;j=e[j].next)
		{
			int v=e[j].v,dnew=d[u]+e[j].w;
			if(!vis[v]&&dnew<=d[v])
			{
				path[v]=u;
				cost[v]=cost[u]+e[j].c;
				if(v==D)
				{
					if(dnew<d[v]||cost[D]<mincost)
					{
						mincost=cost[v];
						while(!ans.empty()){ans.pop();}
						int temp=v;
						while(temp!=S)
						{
							ans.push(temp);
							temp=path[temp];
						}
					}
				}
				d[v]=dnew;
			}
		}
	}
}
int main()
{
	cin>>N>>M>>S>>D;
	{
		eid=0;
		memset(p,-1,sizeof(p));
		int u,v,w,c;
		while(M--)
		{
			scanf("%d%d%d%d",&u,&v,&w,&c);
			addedge(u,v,w,c);
			addedge(v,u,w,c);
		}
		dijkstra(S);
		cout<<S;
		while(!ans.empty())
		{
			cout<<' '<<ans.top();
			ans.pop();
		}
		cout<<' '<<d[D]<<' '<<mincost<<endl;
	}
	return 0;
}