#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	int p[10005];
	double pro[10005];
	cin>>n>>m;
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%lf",&p[i],&pro[i]);
	}
	double dp[10005];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= m;i++)
	{
		for(int j = n;j >= p[i];j--)
		{
			dp[j] = max(1.0-(1-dp[j-p[i]])*(1-pro[i]),dp[j]);
		}
	}
	printf("%.1lf%%\n",dp[n]*100);
	return 0;
}
