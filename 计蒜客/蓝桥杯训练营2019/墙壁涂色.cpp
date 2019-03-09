#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	long long dp[55][2];
	dp[1][0] = 0;
	dp[1][1] = 3;
	int n;
	scanf("%d",&n);
	for(int i = 2;i <= n;i++){
		dp[i][1] = dp[i-1][0];
		dp[i][0] = dp[i-1][1]*2 + dp[i-1][0];
	}
	printf("%lld\n",dp[n][0]);
	return 0;
}
