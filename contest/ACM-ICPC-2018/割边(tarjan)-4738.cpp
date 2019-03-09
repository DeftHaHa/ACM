#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1005,maxm=2000005;
int inf=0x3f3f3f3f;
struct edge
{
	int v,next,w,u;
}e[maxm];
int p[maxm],eid;
void addedge(int u,int v,int w)
{
	e[eid].v=v;
	e[eid].u=u;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
int idx,dfn[maxn],low[maxn];
int ans;
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++idx;
	for(int i=p[u];i!=-1;i=e[i].next)
	{ 
		int v=e[i].v;
		if(!dfn[v])
		{
			tarjan(v,i);
			low[u]=min(low[u],low[v]); 
			if(low[v]>dfn[u])
			{
				ans=min(e[i].w,ans);
			}
		}
		else if(fa^1!=i&&dfn[v]<dfn[u]) low[u]=min(dfn[v],low[u]);
	}
}
int main()
{
	int N,M;
	while(~scanf("%d%d",&N,&M))
	{
		if(!N&&!M) break;
		eid=0;
		memset(p,-1,sizeof(p));
		int u,v,w;
		while(M--)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		for(int i=1;i<=N;i++) dfn[i]=0;
		idx=0;
		ans=inf;
		int cnt=0;
		for(int i=1;i<=N;i++)
		{
			if(!dfn[i])
			{
				tarjan(i,-1);
				cnt++;
			}
		} //cout<<cnt<<endl;
		if(cnt>1)
		{
			cout<<0<<endl;
			continue;
		}
		if(ans==inf) ans=-1;
		if(!ans) ans=1;
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 3
1 2 7
2 3 4
3 1 4
3 3
1 2 7
2 3 4
3 2 3
0 0
*/
