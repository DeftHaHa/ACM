#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
struct edge
{
	int next,v;
}e[400005];
int p[400005],eid;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
bool vis[200005];
int path[400005],cnt;
void dfs(int u)
{
	vis[u]=true;
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		if(!vis[e[i].v])
		{
			path[cnt++]=u;
			dfs(e[i].v);
			path[cnt++]=e[i].v;
		}
	}
	
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	memset(p,-1,sizeof(p));
	eid=0;
	int u,v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	memset(vis,false,sizeof(vis));
	cnt=0;
	dfs(1);
	//for(int i=0;i<cnt;i++) cout<<"-->"<<path[i]; cout<<endl;
	int x=cnt/k;   //cout<<x<<endl;
	if((double)cnt/(double)k-double(x)>0) x+=1;
	for(int i=1;i<=k;i++)
	{
		int st=(i-1)*x,en=i*x;
		if(en>cnt)
		{
			printf("%d",cnt-st);
			for(int j=st;j<cnt;j++) printf(" %d",path[j]);
		}
		else
		{
			printf("%d",x);
			for(int j=st;j<en;j++) printf(" %d",path[j]);
		}
		printf("\n");
	}
	return 0;
}
