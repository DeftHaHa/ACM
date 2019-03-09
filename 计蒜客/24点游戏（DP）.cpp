#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int card[55];
	for(int i=0;i<52;i++) card[i+1]=i/4+1;
	int dp[55][30];
	memset(dp,0,sizeof(dp));
 	for(int i=0;i<=52;i++) dp[i][0]=1;
	for(int i=1;i<=52;i++)
	{
		for(int j=card[i];j<=24;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i-1][j-card[i]]; 
		}
		for(int j=0;j<=card[i]-1;j++) dp[i][j]=dp[i-1][j];
	}
	cout<<dp[52][24];
	return 0;
}
/*
int main()
{
	int card[55];
	for(int i=0;i<52;i++) card[i+1]=i/4+1;
	int dp[30];
	memset(dp,0,sizeof(dp));
 	dp[0]=1;
	for(int i=1;i<=52;i++)
	{
		for(int j=24;j>=card[i];j--)
		{
			dp[j]+=dp[j-card[i]]; 
		}
	}
	cout<<dp[24];
	return 0;
}*/
