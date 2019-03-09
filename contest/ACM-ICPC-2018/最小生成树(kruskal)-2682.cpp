#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxv=1000005,maxn=605;
const int Listsize=200005;
int v[maxn];
struct edge
{
	int u,v,w;
}e;
int fa[maxn];
bool is_prime[Listsize];
int prime[Listsize];
void euler()
{
	memset(is_prime,true,sizeof(is_prime));
	int cnt=0;
	is_prime[0]=is_prime[1]=false;    //×¢Òâµã= = 
	for(int i=2;i<Listsize;i++)
	{
		if(is_prime[i]) prime[cnt++]=i;
		for(int j=0;j<cnt;j++)
		{   
			if(i*prime[j]>Listsize) break;
			is_prime[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
}
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;	
}
vector<edge> q;
int way;
int kruskal()
{
	int res=0;
	sort(q.begin(),q.end(),cmp);
	for(int i=0;i<q.size();i++)
	{
		q[i].u=get(q[i].u);
		q[i].v=get(q[i].v);
		if(q[i].u!=q[i].v)
		{
			fa[q[i].u]=q[i].v;
			res+=q[i].w;
			way++;
		}
	}
	return res;
}
void init()
{
	for(int i=0;i<maxn;i++) fa[i]=i;
	q.clear();
	way=1;
}
int main()
{
	int T;
	euler();
	cin>>T;
	while(T--)
	{
		init();
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++) scanf("%d",&v[i]);
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(is_prime[v[i]]||is_prime[v[j]]||is_prime[v[i]+v[j]])
				{
					e.u=i;
					e.v=j;
					e.w=min(min(v[i],v[j]),abs(v[i]-v[j]));
					q.push_back(e);
				}
			}
		}
		int ans=kruskal();
		if(way==N) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
