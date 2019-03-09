#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct edge
{
	int next,v;
}e[1000005];
int p[1000005];
int eid;
void addege(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int d[1000000];
struct cmp
{
	bool operator()(const int &a,const int &b) const
	{
		return d[a]>d[b];
	}
};
priority_queue<int,vector<int>,cmp> q;
bool vis[1000000];
void djkstra(int s)
{
	memset(d,0x3f,sizeof(d));
	memset(vis,false,sizeof(vis));
	d[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		vis[u]=true;
		for(int i=p[u];i!=-1;i=e[i].next)
		{
			if(!vis[e[i].v])
			{
				if(d[u]+1<d[e[i].v])
				{
					d[e[i].v]=d[u]+1;
					q.push(e[i].v);
				}
			}
		}
	}
}
int main()
{   
	int n,m,x;
	 x=13;
	memset(p,-1,sizeof(p));
	eid=0;
	cin>>n>>m;  
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			int now=i*m+j;
			if(!(x&1)&&i>1) addege(now,(i-1)*m+j);
			if(!(x>>1&1)&&j<m) addege(now,now+1);
			if(!(x>>2&1)&&i<n) addege(now,(i+1)*m+j);
			if(!(x>>3&1)&&j>1) addege(now,now-1);
		}
	}
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	int st=sx*m+sy,en=ex*m+ey;
	djkstra(st);
	if(d[en]<0x3f3f3f3f) cout<<d[en];
	else cout<<-1<<endl;
	return 0;
}
