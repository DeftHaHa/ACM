#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=200005,maxm=2000005;
struct edge
{
	int v,next;
	bool is_cut;
}e[maxm];
int p[maxm],eid;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	e[eid].is_cut=false;
	p[u]=eid++;
}
int idx,dfn[maxn],low[maxn];
int S[maxn],top;
int bcc_cnt,bccno[maxn];
int cut_cnt;
void tarjan(int u,int fa)  
{  
    dfn[u]=low[u]=++idx;  
    S[++top] = u;  
    for(int i=p[u];i!=-1;i=e[i].next)  
    {  
        int v=e[i].v;  
        if(!dfn[v])  
        {  
            tarjan(v,i);  
            low[u] = min(low[u],low[v]);  
            if(low[v] > dfn[u])  
            {  
            	e[i^1].is_cut=true;
            	e[i].is_cut=true;
                cut_cnt++;
            }  
        }  
        else if(i!=(fa^1))  
        {  
            low[u] = min(low[u],dfn[v]);  
        }  
    }  
    if(dfn[u] == low[u])
    {  
        ++bcc_cnt;
        do  
        {  
            bccno[S[top]] = bcc_cnt;  
            --top;  
        }  
        while(S[top+1] != u);  
    }  
} 
vector<int> E[maxn];
int far,id;
void dfs(int u,int father,int d)
{
	if(d>far)   
	{
		id=u;
		far=d;
	}
	for(int i=0;i<E[u].size();i++)
	{
		if(E[u][i]!=father)
		{
			dfs(E[u][i],u,d+1);
		}
	}
}
int main()
{
	int N,M;
	while(~scanf("%d%d",&N,&M))
	{
		if(!N&&!M) return 0;
		int u,v;
		memset(p,-1,sizeof(p));
		eid=0;
		while(M--)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		idx=bcc_cnt=cut_cnt=top=0;
		for(int i=0;i<=N;i++) dfn[i]=0;
		tarjan(1,-1);
		for(int i=0;i<=N;i++) E[i].clear();
		for(int u=1;u<=N;u++)
		{
			for(int i=p[u];i!=-1;i=e[i].next)
			{
				if(e[i].is_cut)
				{
					E[bccno[u]].push_back(bccno[e[i].v]);
				}
			}
		}
		far=0;
		dfs(1,-1,1);
		dfs(id,-1,1);
		printf("%d\n",cut_cnt-far+1);
	}
	return 0;
}
