#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
int w[10005];
bool dp[105],path[10005][105];
int ans[10005];
bool cmp(int a,int b){
	return a > b;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= N;i++) scanf("%d",&w[i]);
	sort(w+1,w+N+1,cmp);
	memset(dp,false,sizeof(dp));
	memset(path,false,sizeof(path));
	dp[0] = true;
	bool ok = false;
	for(int i = 1;i <= N;i++){
		for(int j = M-w[i];j >= 0;j--){
			if(dp[j]){
				dp[j+w[i]] = true;
				path[i][j+w[i]] = true;
				if(j+w[i] == M) ok = true;
			}
		}
	}
	if(ok){
		int i = N,j = M,cnt = 0;
		while(i > 0 && j >= 0){
			if(path[i][j]){
				ans[++cnt] = w[i];
				j -= w[i];
			}
			i--;
		}
		printf("%d",ans[1]);
		for(int i = 2;i <= cnt;i++) printf(" %d",ans[i]);
		puts("");
	}
	else puts("No Solution");
	return 0;
}
