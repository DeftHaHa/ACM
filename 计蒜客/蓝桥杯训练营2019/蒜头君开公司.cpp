#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[15];
int task[15][15];
int N;
int ans = 0x3f3f3f3f;
void dfs(int peo,int sum){
	if(sum >= ans) return;
	if(peo == N+1 && sum < ans) ans = sum;
	for(int i = 1;i <= N;i++){
		if(!vis[i]){
			vis[i] = true;
			dfs(peo+1,sum + task[i][peo]);
			vis[i] = false;
		}
	}
}
int main()
{
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			scanf("%d",&task[i][j]);
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
