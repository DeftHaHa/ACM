#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int dp[2][5005];
int main()
{
	string rs,s;
	int N;
	cin>>N>>rs;
	s = rs;
	reverse(s.begin(),s.end());
	memset(dp,0,sizeof(dp));
	int now = 0;
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			if(s[i-1] == rs[j-1]) dp[now][j] = dp[1-now][j-1] + 1;
			else dp[now][j] = max(dp[1-now][j],dp[now][j-1]);
		}
//		for(int j = 1;j <= N;j++){
//			printf("%d ",dp[now][j]);
//		}printf("\n");
		now = 1 - now;
	}
	int com = N&1 ? dp[0][N] : dp[1][N];
	printf("%d\n",N-com);
	return 0;
}
