#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 300005*2;
int c[maxn];
int n;
struct edge{
	int u,v,next;
}e[maxn];
int p[maxn],eid = 0;
int tot1 = 0,tot2 = 0;
void addedge(int u,int v){
	e[eid].v = v;
	e[eid].u = u;
	e[eid].next = p[u];
	p[u] = eid++;
}
int dp[maxn][3];
bool vis[maxn];
void dfs(int fa,int u){
	vis[u] = true;
	for(int i = p[u];i!=-1;i=e[i].next){
		int v = e[i].v;
		if(!vis[v]){
			dfs(u,v);
		}
	}
	dp[u][c[u]]++;
	dp[fa][0] += dp[u][0];
	dp[fa][1] += dp[u][1];
	dp[fa][2] += dp[u][2];
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&c[i]);
		if(c[i]==1) tot1++;
		else if(c[i]==2) tot2++;
	}
	memset(p,-1,sizeof(p));
	for(int i = 1;i < n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	memset(dp,0,sizeof(dp));
	memset(vis,false,sizeof(vis));
	dfs(0,1);
	int ans = 0;
	for(int i = 0;i < eid;i++){
		int u = e[i].u;
		int v = e[i].v;
		if(dp[u][0]<dp[v][0] || dp[u][1] < dp[v][1] || dp[u][2] < dp[v][2]) swap(u,v);
		if((dp[v][1]==tot1 && dp[v][2] == 0)||(dp[v][2]==tot2&&dp[v][1]==0) ) ans++;
	}
	printf("%d\n",ans/2);
	return 0;
}
