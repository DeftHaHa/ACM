#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
#include<cmath>
using namespace std;
bool vis[10005];
pair<int,int> e[10005];
int main()
{
	int N,M;
	int u,v;
	scanf("%d%d",&N,&M);
	for(int i = 0;i < M;i++){
		scanf("%d%d",&e[i].first,&e[i].second);
	}
	int Q,k;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&k);
		int t = 0;
		memset(vis,false,sizeof(vis));
		while(k--){
			scanf("%d",&u);
			vis[u] = true;
		}
		bool ok = true;
		for(int i = 0;i < M;i++){
			if(!vis[e[i].first] && !vis[e[i].second]){
				ok = false;
				break;
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
} 
