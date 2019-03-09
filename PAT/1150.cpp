#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int Map[205][205];
bool vis[205];
int main()
{
	int N,M;
	int u,v,w;
	scanf("%d%d",&N,&M);
	memset(Map,0x3f,sizeof(Map));
	while(M--)
	{
		scanf("%d%d%d",&u,&v,&w);
		Map[u][v] = Map[v][u] = w;
	}
	int K;
	scanf("%d",&K);
	int path[205];
	int tag,ans = INF;
	for(int k = 1;k <= K;k++){
		int n;
		scanf("%d",&n);
		memset(vis,false,sizeof(vis));
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d",&path[i]);
			if(!vis[path[i]]){
				vis[path[i]] = true;
				cnt++;
			}
		}
		int sum = 0;
		for(int i = 2;i <= n;i++){
			sum += Map[path[i]][path[i-1]];
		}
		if(sum < INF && path[1] == path[n] && cnt==N){
			if(sum < ans){
				ans = sum;
				tag = k;
			}
			if(n==N+1) printf("Path %d: %d (TS simple cycle)\n",k,sum);
			else printf("Path %d: %d (TS cycle)\n",k,sum);
		}
		else if(sum<INF) printf("Path %d: %d (Not a TS cycle)\n",k,sum);
		else printf("Path %d: NA (Not a TS cycle)\n",k,sum);
	}
	printf("Shortest Dist(%d) = %d\n",tag,ans);
	return 0;
}
