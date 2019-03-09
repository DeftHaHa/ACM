#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int maze[1005][1005];
int dp[1005][1005];
int main()
{
	int n,m,x,y,v,c;
	cin>>n>>m>>x>>y>>v>>c;
	for(int i = 1;i <= n;i++){
		for(int j=1;j <= m;j++){
			scanf("%d",&maze[i][j]);
		}
	} 
	memset(dp,0,sizeof(dp));
	dp[x][y] = v;
	for(int i = x;i <= n;i++){
		for(int j = y;j <= m;j++){
			if(i==x&&y==j) continue;
			if(i==x) dp[i][j] = dp[i][j-1] + maze[i][j];
			else if(j==y) dp[i][j] = dp[i-1][j] + maze[i][j];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + maze[i][j];
			if(dp[i][j] > c) dp[i][j] = c;
			else if(dp[i][j] < 0) dp[i][j] = -2e9;
		}
	}
	for(int i = x;i >= 1;i--){
		for(int j = y;j >= 1;j--){
			if(i==x&&y==j) continue;
			if(i==x) dp[i][j] = dp[i][j+1] + maze[i][j];
			else if(j==y) dp[i][j] = dp[i+1][j] + maze[i][j];
			else dp[i][j] = max(dp[i+1][j],dp[i][j+1]) + maze[i][j];
			if(dp[i][j] > c) dp[i][j] = c;
			else if(dp[i][j] < 0) dp[i][j] = -2e9;
		}
	}
	for(int i = x;i <= n;i++){
		for(int j = y;j >= 1;j--){
			if(i==x&&y==j) continue;
			if(i==x) dp[i][j] = dp[i][j+1] + maze[i][j];
			else if(j==y) dp[i][j] = dp[i-1][j] + maze[i][j];
			else dp[i][j] = max(dp[i-1][j],dp[i][j+1]) + maze[i][j];
			if(dp[i][j] > c) dp[i][j] = c;
			else if(dp[i][j] < 0) dp[i][j] = -2e9;
		}
	}
	for(int i = x;i >= 1;i--){
		for(int j = y;j <= m;j++){
			if(i==x&&y==j) continue;
			if(i==x) dp[i][j] = dp[i][j-1] + maze[i][j];
			else if(j==y) dp[i][j] = dp[i+1][j] + maze[i][j];
			else dp[i][j] = max(dp[i+1][j],dp[i][j-1]) + maze[i][j];
			if(dp[i][j] > c) dp[i][j] = c;
			else if(dp[i][j] < 0) dp[i][j] = -2e9;
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j=1;j <= m;j++){
//			printf("%3d",dp[i][j]);
//		}
//		cout<<endl;
//	} 
	int ans = max(max(dp[1][1],dp[1][m]),max(dp[n][1],dp[n][m]));
	if(ans<0) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
