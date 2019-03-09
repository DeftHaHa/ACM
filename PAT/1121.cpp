#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int Map[100005]; 
int peo[10005],ans[10005];
bool vis[100005];
int main()
{
	int N,M;
	scanf("%d",&N);
	int u,v;
	memset(Map,-1,sizeof(Map));
	while(N--){
		scanf("%d%d",&u,&v);
		Map[u] = v;
		Map[v] = u;
	}
	scanf("%d",&M);
	int cnt = 0;
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < M;i++){
		scanf("%d",&peo[i]);
		vis[peo[i]] = true;
	}
	for(int i = 0;i < M;i++){
		if(Map[peo[i]] == -1 || !vis[Map[peo[i]]]) ans[cnt++] = peo[i];
	}
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	if(cnt>0){
		printf("%05d",ans[0]);
		for(int i = 1;i < cnt;i++){
			printf(" %05d",ans[i]);
		}
		puts("");
	}
	return 0;
}
