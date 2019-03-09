#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int w[1200005],v[1200005],cnt=0;
int main()
{
	int m;
	int sum = 0;
	for(int i = 1;i <= 6;i++)
	{
		cin>>m;
		sum += m*i;
		for(int k = 0;(1<<k) <= m;k++)
		{
			int now = 1<<k;
			w[cnt] = i*now;
			v[cnt] = now;
			cnt++;
		}
	}
	int dp[420005];
	memset(dp,0,sizeof(dp));
	if(sum&1)
	{
		cout<<"Can't be divided.\n";
		return 0;
	}
	sum /= 2;
	dp[0] = 1;
	
	for(int i=1;i < cnt;i++)
	{
		for(int j = sum;j >= w[i];j--) dp[j] |= dp[j-w[i]];
		if(dp[sum]) break;
	}
	if(dp[sum]) cout<<"Can be divided.\n";
	else cout<<"Can't be divided.\n";
	return 0;
}
