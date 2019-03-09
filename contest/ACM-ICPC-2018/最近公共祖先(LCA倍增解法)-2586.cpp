#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=40005,MAXM=80005;
int d[MAXN], fa[MAXN][20];
int dis[MAXN];
struct edge
{
	int v,next,w;
}e[MAXM];
int p[MAXM],eid;
bool vis[MAXN];
void init() 
{
    memset(d, -1, sizeof(d));
    memset(p,-1,sizeof(p));
    eid=0;
}
void addedge(int u,int v,int w)
{
	e[eid].w=w;
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
void dfs(int node) { 
    for (int i = p[node]; i != -1; i = e[i].next) {
        if (d[e[i].v] == -1) {      
            d[e[i].v] = d[node] + 1;
            dis[e[i].v]=dis[node]+e[i].w;
            fa[e[i].v][0] = node;
            dfs(e[i].v);
        }
    }
}

int lca(int x, int y) {
    int i, j;
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (i = 0; (1 << i) <= d[x]; i++); 
    i--; 
    for (j = i; j >= 0; j--) {
        if (d[x] - (1 << j) >= d[y]) {
            x = fa[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (j = i; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}
int main()
{
	int T;
	cin>>T;
	int n,m;
	int u,v,w;
	int a,b;
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dis[1]=0;
		d[1]=0;
		dfs(1); // for(int i=1;i<=n;i++) printf("##%d %d\n",i,dis[i]);
		for (int level = 1; (1 << level) <= n; level++) 
		{
   			for (int i = 1; i <= n; i++) 
			{
        		fa[i][level] = fa[fa[i][level - 1]][level - 1]; 
    		}
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			int A=lca(a,b);
			printf("%d\n",dis[a]+dis[b]-2*dis[A]);
		}
	
	}
	return 0;
}
