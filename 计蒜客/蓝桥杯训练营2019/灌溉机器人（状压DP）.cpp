#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int N,M;
int Map[105];
int depot[105];
int dp[105][65][65];
bool fit_self(int x){
	return !((x & (x>>1)) || (x & (x>>2)) ); 
}
bool fit_map(int x,int flag){
	return (x | flag) == flag;
}
bool fit_up(int x,int flag){
	return (x&flag) == 0;
}
int Count(int x){
	int res = 0;
	while(x){
		res += (x&1);
		x>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d",&N,&M);
	memset(Map,0,sizeof(Map));
	char ch = getchar();
	for(int i = 0;i < N;i++){
		for(int j = 0;j < M;j++){
			scanf("%c",&ch);
			if(ch == 'P') Map[i] |= (1<<j);
		}
		getchar();
	}
	int cnt = 0;
	for(int i = 0;i < (1<<M);i++){
		if(fit_self(i)) depot[cnt++] = i;
	}
	memset(dp,0,sizeof(dp)); 
	for(int i = 0;i < cnt;i++){
		if(fit_map(depot[i],Map[0]))
		for(int j = 0;j < cnt;j++){
			if(fit_map(depot[j],Map[1]) && fit_up(depot[i],depot[j])){
				dp[1][i][j] = Count(depot[i]) + Count(depot[j]);
			}
		}
	}
	bool pos = 0;
	for(int i = 2;i < N;i++){
		for(int now = 0;now < cnt;now++){
			if(fit_map(depot[now],Map[i]))
	        for(int j = 0;j < cnt;j++){
	        	if(fit_map(depot[j],Map[i-1]) && fit_up(depot[now],depot[j]))
	        	for(int k = 0;k < cnt;k++){
	        		if(fit_map(depot[k],Map[i-2]) && fit_up(depot[now],depot[k]) && fit_up(depot[j],depot[k])){
	        			dp[pos][j][now] = max(dp[pos][j][now],dp[1-pos][k][j] + Count(depot[now]));
	        			//dp[pos][now][j] = max(dp[pos][now][j],dp[1-pos][j][k] + Count(depot[now]));
					}
				}
			}
		}
		pos = 1- pos;
    }
	pos = N%2 ? 0:1;
	int ans = 0;
	for(int i = 0;i < cnt;i++){
		for(int j = 0;j < cnt;j++){
			ans = max(dp[pos][i][j],ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
