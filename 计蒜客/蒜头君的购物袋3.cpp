#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int V,n;
	int v[1005],w[1005];
	cin>>n>>V;
	for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
	int dp[10005];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=v[i];j<=V;j++)
		{
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	cout<<dp[V]<<endl;
	return 0;
}
