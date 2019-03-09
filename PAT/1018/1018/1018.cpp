#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int inf=0x3f3f3f3f;
struct edge
{
	int next,v,w;
}e[250005];
int eid,p[250005];
void addedge(int u,int v,int w)
{
	e[eid].v=v;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
int cmax,N,sp,M;
int dist[505],path[505];
bool vis[505];
int tot=0;
vector<int> PATH[1005];
void dijkstra(int s)
{
	memset(vis,false,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	for(int i=0;i<=N;i++)
	{
		int u=0,min_w=inf;
		for(int j=0;j<=N;j++)
		{
			if(!vis[j]&&dist[j]<min_w)
			{
				u=j;
				min_w=dist[j];
			}
		}
		vis[u]=true;
		for(int j=p[u];j!=-1;j=e[j].next)
		{
			int v=e[j].v;
			int newd=dist[u]+e[j].w;
			if(!vis[v]&&newd<=dist[v])
			{
				path[v]=u;
				if(v==sp)
				{
					if(newd<dist[sp])
					{
						for(int i=0;i<tot;i++)
						{
							if(!PATH[i].empty()) PATH[i].clear();
						}
						tot=0;
					}
					int temp=v;
					while(temp!=0)
					{
						PATH[tot].push_back(temp);
						temp=path[temp];
					}
					tot++;
				}
				dist[v]=newd;
			}
		}
	}
}
int main()
{
	int s[505];
	while(cin>>cmax>>N>>sp>>M)
	{
		for(int i=1;i<=N;i++) cin>>s[i];
		eid=0;
		memset(p,-1,sizeof(p));
		while(M--)
		{
			int u,v,w;
			cin>>u>>v>>w;
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dijkstra(0);
		int per=cmax/2;
		vector<int>::reverse_iterator it;
		int mintake=inf,tag,a1,a2;
		int take,back;
		for(int i=0;i<tot;i++)
		{
			take=back=0;
			for(it=PATH[i].rbegin();it!=PATH[i].rend();it++)
			{
				if(s[*it]<per)
				{
					if(back>=per-s[*it])
					{
						back-=per-s[*it];
					}
					else 
					{
						take+=per-s[*it]-back;
						back=0;
					}
				}
				else
				{
					back+=s[*it]-per;
				}
			}                                               
			
			if(back<mintake)
			{
				tag=i;
				mintake=back;
				a1=take;
				a2=back;
			}
		}
		cout<<a1<<' '<<0;
		for(it=PATH[tag].rbegin();it!=PATH[tag].rend();it++)
		{
			cout<<"->"<<*it;
		}
		cout<<' '<<a2<<endl;
		for(int i=0;i<tot;i++)
		{
			if(!PATH[i].empty()) PATH[i].clear();
		}
	}
	return 0;
}