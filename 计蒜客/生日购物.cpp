#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	freopen("DATA.txt","r",stdin);
	int v[25],w[25];
	for(int i=1;i<=20;i++) scanf("%d%d",&v[i],&w[i]);
	int dp[505];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=20;i++)
	{
		for(int j=500;j>=v[i];j--)
		{
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	cout<<dp[500]<<endl;
	return 0;
}
