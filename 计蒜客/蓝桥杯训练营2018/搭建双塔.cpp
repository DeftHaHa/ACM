#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N,h[105];
	int dp[105][2005]; //dp[i][j] i块水晶组成双塔，双塔高度差为j时较高塔的最大高度 
	cin>>N;
	int sum = 0;
	for(int i = 1;i <= N;i++)
	{
		cin>>h[i];
		sum += h[i];
	}
	memset(dp,0xc0,sizeof(dp)); //只有0,0合法，其他设为负无穷 
	dp[0][0] = 0;
	for(int i = 1;i <= N;i++)
	{
		for(int j = sum;j >= 0;j--)
		{
			dp[i][j] = max(dp[i][j],dp[i-1][j]); //第i块不放 
			if(j >= h[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-h[i]]+h[i]); //放在较高的上面
			if(j<=sum-h[i]) dp[i][j] = max(dp[i][j],dp[i-1][j+h[i]]); //放在较低的上面之后较低的仍是较低的 
			if(h[i]>=j) dp[i][j] = max(dp[i][j],dp[i-1][h[i]-j]+j);//放在较低的上面之后低的变成了高的 
		}
	}
	int ans = 0;
	for(int i = 0;i <= N;i++) ans = max(ans,dp[i][0]);
	cout<<ans<<endl; 
	
	return 0;
}
