#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=5005,maxm=10005;
int N,M;
struct edge
{
	int v,next;
}e[maxm];
int p[maxm],eid;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int dfn[maxn],low[maxn],idx;
int cut[maxn],node1,rt_child,rt;

void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++idx;
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa||v==node1) continue;  // 
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(u==rt) rt_child++;   //根的孩子数，去掉根增加的连通分量等于孩子数-1 
			if(low[v]>=dfn[u])
			{
				cut[u]++; //非根节点去掉后增加的连通分量等于孩子数 
			}
		}
		else low[u]=min(dfn[v],low[u]);
	}
}
int main()
{
	while(~scanf("%d%d",&N,&M))
	{
		eid=0;
		memset(p,-1,sizeof(p));
		memset(dfn,0,sizeof(dfn));
		int u,v;
		while(M--)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		idx=0;
		int ans=0;
		for(node1=0;node1<N;node1++)
		{
			memset(cut,0,sizeof(cut));
			memset(dfn,0,sizeof(dfn));
			int sum=0;
			for(int j=0;j<N;j++)
			{
				if(j!=node1&&!dfn[j])
				{
					sum++;     
					rt=j;
					rt_child=0;
					tarjan(j,-1);
					cut[rt]=rt_child-1;
				}
			}
			for(int i=0;i<N;i++)
			{ 
				if(i!=node1)ans=max(ans,sum+cut[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
