#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_N=100005;
const int MAX_M=100005;
struct edge {
    int v, next;
}e[MAX_M];
int p[MAX_N], eid;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
int dfn[MAX_N], low[MAX_N];
int idx=0;
int belong[MAX_N], scc=0; 
int s[MAX_N], top = 0;
bool in_stack[MAX_N];
int node_cnt[MAX_N];
void tarjan(int u) 
{
    dfn[u] = low[u] = ++idx;
    s[top++] = u;
    in_stack[u] = true;
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc;
        do {
            belong[s[--top]] = scc;
            node_cnt[scc]++;
            in_stack[s[top]] = false;
        }while(s[top]!=u);
    }
}
int outd[MAX_N],ind[MAX_N];
int main()
{
	int T,c=0;
	cin>>T;
	memset(in_stack,false,sizeof(in_stack));
	while(T--)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		int u,v;
		memset(p,-1,sizeof(p));
		eid=0;
		for(int i=0;i<M;i++)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		scc=idx=top=0;
		for(int i=0;i<=N;i++) dfn[i]=node_cnt[i]=0;
		for(int i=1;i<=N;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
		//Ëõµã 
		if(scc==1)
		{
			printf("Case %d: -1\n",++c);
			continue;
		}
		for(int i=1;i<=scc;i++) outd[i]=ind[i]=0;
		for(int j=1;j<=N;j++)
        {
            for(int k=p[j];k!=-1;k=e[k].next)
            {
                if(belong[e[k].v]!=belong[j]) 
                {
                    outd[belong[j]]++;
                    ind[belong[e[k].v]]++;
                }
            }
        }
        int mincnt=N;
		for(int i=1;i<=scc;i++)
		{
			if(!outd[i]||!ind[i]) mincnt=min(mincnt,node_cnt[i]);
		}  
		printf("Case %d: %d\n",++c,N*(N-1)-M-mincnt*(N-mincnt));
	}
	return 0;
}
