#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int num[81];
	for(int i=1;i<=80;i++) num[i]=i;
	int dp[81];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=80;i++)
	{
		for(int j=num[i];j<=80;j++)
		{
			dp[j]+=dp[j-num[i]];
		}
	}
	cout<<dp[80];
	return 0;
}
