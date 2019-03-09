#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int Map[20][20];
int n;
bool vis[20];
int ans = 0x3f3f3f3f;
void dfs(int cnt,int u,int sum){
	if(sum >= ans) return;
	if(cnt == n){
		ans = min (ans,sum+Map[u][1]);
		return;
	}
	vis[u] = true;
	for(int i = 2;i <= n;i++){
		if(!vis[i]){
			dfs(cnt+1,i,sum + Map[u][i]);
		}
	}
	vis[u] = false;
}
int main()
{
	scanf("%d",&n);
	memset(Map,0,sizeof(Map));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d",&Map[i][j]);
		}
	}
	memset(vis,false,sizeof(vis));
	dfs(1,1,0);
	printf("%d\n",ans);
	return 0;
}
