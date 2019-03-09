#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Edge
{
	int v,next;
}e[400005];
int eid,p[400005];
ll a[200005];
void addedge(int u,int v)
{
	e[eid].v = v;
	e[eid].next = p[u];
	p[u] = eid++;
}
ll dp[200005],w[200005];
ll SUM = 0;
ll ans;
void dfs1(int dep,int u,int fa)
{
	w[u] = a[u];
	dp[1] += a[u]*dep;
	for(int i = p[u];i!=-1;i = e[i].next){
		int v = e[i].v;
		if(v != fa)
		{
			dfs1(dep+1,v,u);
			w[u] += w[v];
		}
	}
}
void treedp(int u,int fa)
{
	for(int i = p[u];i!=-1;i = e[i].next)
	{
		int v = e[i].v;
		if(v != fa){
			dp[v] = dp[u] + SUM - 2*w[v];
			ans = max(ans,dp[v]);
			treedp(v,u);
		}
	}
}
int main()
{
	int n;
	int u,v;
	cin>>n;
	for(int i = 1;i <= n;i++){
		scanf("%I64d",&a[i]);
		SUM += a[i];
	}
	eid = 0;
	memset(p,-1,sizeof(p));
	for(int i = 0;i < n-1;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dp[1] = 0;
	dfs1(0,1,0); 
	ans = dp[1];
	treedp(1,0); 
	cout<<ans<<endl;
	return 0;
} 
/*
8
9 4 1 7 10 1 6 5
1 4
1 2
1 5
5 6
5 7
5 8
2 3

*/
