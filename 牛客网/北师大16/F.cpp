#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int maxm=200005;
struct edge
{
	int v,next;
	long long w;
}e[maxm];
int p[maxm],eid;
void addedge(int u,int v,long long  w)
{
	e[eid].w=w;
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
long long cnt[100005];
struct cmp
{
	bool operator()(const int &a,const int &b)
	{
		return cnt[a]>cnt[b];
	}
};
priority_queue<int,vector<int>,cmp> q;
bool vis[100005];
int main()
{
	int n,m;
	int x,y;
	long long z;
	int T;
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			cnt[i]=0;
			vis[i]=false;
		}
		memset(p,-1,sizeof(p));
		eid=0;
		while(m--)
		{
			scanf("%d%d%lld",&x,&y,&z);
			cnt[x]+=z;
			cnt[y]+=z;
			addedge(x,y,z);
			addedge(y,x,z);
		}
		int pos;
		long long mincnt=1e17;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]<mincnt)
			{
				mincnt=cnt[i];
				pos=i;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++) q.push(i);
		while(!q.empty())
		{
			int u=q.top();
			q.pop();
			if(!vis[u])
			{
				ans=max(ans,cnt[u]);  //cout<<"pick"<<u<<'='<<q.size()<<endl;
			}
			else continue;
			vis[u]=true;    
			for(int i=p[u];i!=-1;i=e[i].next)
			{      
				int v=e[i].v;
				if(!vis[v])
				{
					cnt[v]-=e[i].w;
					q.push(v);
				}
			}
		}
		printf("%lld\n",ans);	
	}
	return 0;
}
