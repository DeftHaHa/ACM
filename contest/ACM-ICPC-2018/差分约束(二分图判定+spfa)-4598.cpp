#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue> 
using namespace std;
#define fuck printf
const int maxn=305,maxm=90005;
int N;
int mp[maxn][maxn];
struct edge
{
	int v,next,w;
}e[maxm];
int p[maxm],eid;
void addedge(int u,int v,int w)
{
	e[eid].v=v;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
int color[maxn];
bool dfs(int u,int c)
{
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if(!color[v])
		{
			color[v]=3-c;
			if(!dfs(v,color[v])) return false;
		}
		else if(color[v]==c) return false;
	}
	return true;
}
int d[maxn],cnt[maxn];
bool inq[maxn];
bool spfa()
{
	queue<int> q;
	while(!q.empty()) q.pop();
	for(int i=1;i<=N;i++)
	{
		q.push(i);
		d[i]=0;
		cnt[i]=0;
		inq[i]=true;
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=false;
		for(int i=p[u];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(e[i].w+d[u]<d[v])
			{
				d[v]=e[i].w+d[u];
				if(!inq[v])
				{
					q.push(v);
					cnt[v]++;
					inq[v]=true;
					if(cnt[v]>N) return false;
					
				}
			}
		}
	}
	return true;
}
int main()
{
	int TC;
	cin>>TC;
	int T=1000;
	while(TC--)
	{
		scanf("%d",&N);
		char s[maxn];
		eid=0;
		memset(p,-1,sizeof(p));
		for(int i=1;i<=N;i++)
		{
			scanf("%s",s);
			for(int j=1;j<=N;j++)
			{
				mp[i][j]=s[j-1]-'0';
				if(mp[i][j]) addedge(i,j,0);
			}
		}
		memset(color,0,sizeof(color));
		bool flag=true;
		for(int i=1;i<=N;i++)  //判断二分图 
		{
			if(!color[i])
			{
				color[i]=1;
				if(!dfs(i,1))
				{
					flag=false;
					break;
				}
			}
		}
		if(!flag)
		{
			fuck("No\n");
			continue;
		}
		eid=0;
		memset(p,-1,sizeof(p));
		for(int i=1;i<=N;i++)
		{
			for(int j=i+1;j<=N;j++) //只要单向边就行 ,因为反过来
			{ 						//无非是再添加同一条单向边 
				if(mp[i][j])
				{
					if(color[i]==1) addedge(i,j,-T);
					else addedge(j,i,-T); 
				}
				else
				{
					if(color[i]==1) addedge(j,i,T-1);
					else addedge(i,j,T-1);
				}
			}
		}
		if(spfa()) fuck("Yes\n");
		else fuck("No\n");
	}
	return 0;
}
map[i][j]=0,|ai-aj|<T,map[i][j]=1,|ai-aj||>=T;|ai|<T

