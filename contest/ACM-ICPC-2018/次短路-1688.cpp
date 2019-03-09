#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1005,maxm=10005;
const int inf=0x3f3f3f3f;
struct edge
{
	int v,next,w;
}e[maxm];
int eid,p[maxm];
void addedge(int u,int v,int w)
{
	e[eid].v=v;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
int S,F;
int d[maxn][2],cnt[maxn][2];
bool vis[maxn][2];
struct node
{
	int id,dist,mark;
	bool operator<(const node &p)const
	{
		return p.dist<dist;
	}
};
priority_queue<node> q;
void djkstra(int s)
{
	memset(d,0x3f,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	memset(vis,false,sizeof(vis));
	cnt[s][0]=1;
	d[s][0]=0;
	node S;
	S.id=s;
	S.mark=0;
	S.dist=0;
	q.push(S);
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(vis[t.id][t.mark]) continue;
		int k=t.mark;
		int u=t.id;
		vis[u][k]=true;
		for(int i=p[u];i!=-1;i=e[i].next)
		{
			int v=e[i].v;
			int newd=e[i].w+d[u][k];
			if(newd<d[v][0])
			{
				if(d[v][0]!=inf)  //更新最短路的同时也要更新次短路 
				{
                    d[v][1]=d[v][0];
                    cnt[v][1]=cnt[v][0];
                    node x;
                    x.id=v;x.dist=d[v][1];x.mark=1;
                    q.push(x);
                }
				d[v][0]=newd;
				cnt[v][0]=cnt[u][k];
				node x;
				x.dist=d[v][0];x.id=v;x.mark=0;
				x.dist=d[v][k];
				q.push(x);
				
			}
			else  if(newd==d[v][0]) cnt[v][0]+=cnt[u][k];
			else if(newd<d[v][1])  //介于最短与次短之间 
			{
				d[v][1]=newd;
				cnt[v][1]=cnt[u][k];
				node x;
				x.dist=d[v][1];x.id=v;x.mark=1;
				q.push(x);
			}
			else if(newd==d[v][1])
			{
				cnt[v][1]+=cnt[u][k]; 
			}			
		}
	}
	
}
int main()
{
	int N,M;
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&N,&M);
		int u,v,w;
		eid=0;
		memset(p,-1,sizeof(p));
		while(M--)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		scanf("%d%d",&S,&F);
		djkstra(S); //cout<<"###"<<d[F][0]<<'='<<cnt[F][0]<<' '<<d[F][1]<<'='<<cnt[F][1]<<endl;
		if(d[F][0]+1==d[F][1]) cnt[F][0]+=cnt[F][1];
		printf("%d\n",cnt[F][0]);
	}
	
	
	return 0;
}
