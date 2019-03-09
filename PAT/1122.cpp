#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
bool Map[205][205],vis[205];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	int u,v;
	while(M--){
		scanf("%d%d",&u,&v);
		Map[u][v] = Map[v][u] = true;
	}
	int K,n,path[1005];
	scanf("%d",&K);
	while(K--){
		bool ok = true;
		scanf("%d",&n);
		memset(vis,false,sizeof(vis));
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&path[i]);
			if(!vis[path[i]]) vis[path[i]] = true,cnt++;
			if(i>1){
				if(!Map[path[i]][path[i-1]]) ok = false;
			}
		}
		if(cnt!=N ||n!=N+1 || path[n]!=path[1]) ok = false;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
