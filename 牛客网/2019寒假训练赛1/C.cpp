#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxj = (1<<12) + 5;
int p[3005];
bool cmp(int a,int b){
	return a > b;
} 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&p[i]);
	}
	if(p[n] >= p[1]){
		printf("-1\n");
		return 0;
	}
	int w[3005],cnt = 0;
	for(int i = 1;i <= n;i++){
		if(p[i]<=p[1] && p[i] >= p[n]) w[cnt++] = p[i];
	}
	sort(w,w+cnt,cmp);
	bool dp[maxj];
	memset(dp,false,sizeof(dp));
	dp[w[0]] = true;
	for(int i = 1;i < cnt;i++){
		if(w[i] == w[i-1]) continue;
		for(int j = 0;j < maxj;j++){
			dp[j^w[i]] |= dp[j]; 
		}
	}
	int ans = 0;
	for(int j = maxj-1;j >= 0 ;j--){
		if(dp[j]){
			ans = j;
			break;
		}
	}
	if(!ans) puts("-1");
	else printf("%d\n",ans);
	return 0;
}
