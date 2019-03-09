#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=105,maxm=10005;
bool G[maxn][maxn];
int col[maxn];
int N;
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
bool dfs(int u,int c)
{
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if(!col[v])
		{
			col[v]=3-c;
			if(!dfs(v,col[v])) return false;
		}
		else if(col[v]==c) return false;
		
	}
	return true;
}
int main()
{
	
	while(~scanf("%d",&N))
	{
		int v;
		memset(G,0,sizeof(G));
		for(int u=1;u<=N;u++)
		{
			while(1)
			{
				scanf("%d",&v);
				if(!v) break;
				G[u][v]=true;
			}
		}
		eid=0;
		memset(p,-1,sizeof(p));
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(!G[i][j]||!G[j][i])
				{
					addedge(i,j);
					addedge(j,i);
				}
			}
		}
		memset(col,0,sizeof(col));
		bool flag=true;
		for(int i=1;i<=N;i++)
		{  //cout<<col[i]<<endl;
			if(!col[i])
			{
				col[i]=1;
				if(!dfs(i,1))
				{
					flag=false;
					//break;
				}
			} 
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
