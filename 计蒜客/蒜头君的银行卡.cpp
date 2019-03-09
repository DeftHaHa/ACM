#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct edge
{
	int next,v,w;
}e[100005];
int n,m;
int p[300005],eid;
void addege(int u,int v,int w)
{
	e[eid].v=v;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
int cnt[100005],d[100005];
bool instk[100005];
queue<int> q;
bool spfa(int s)
{
	memset(cnt,0,sizeof(cnt));
	memset(instk,0,sizeof(instk));
	memset(d,0x3f,sizeof(d));
	q.push(s);
	d[s]=0;
	cnt[s]++;
	instk[s]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		instk[u]=false;
		for(int i=p[u];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			if(!instk[v]&&e[i].w+d[u]<d[v])
			{
				d[v]=e[i].w+d[u];
				instk[v]=true;
				q.push(v);
				cnt[v]++;
				if(cnt[v]>n) return false;
			}
		}
	}
	return true;
}
int main()
{
	
	cin>>n>>m;
	int x,a,b,c;
	memset(p,-1,sizeof(p));
	eid=0; 
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&a,&b);
		if(x==1) 
		{
			scanf("%d",&c);   
			addege(a,b,-c);
		}
		else if(x==2)
		{
			scanf("%d",&c);
			addege(b,a,c);
		}
		else
		{
			addege(a,b,0);
			addege(b,a,0);
		}
	}
	for(int i=1;i<=n;i++) addege(0,i,0);
	if(spfa(0))
	{
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}
