#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int e,f,n;
	cin>>e>>f>>n;
	int W = f - e;//weight of money
	int dp[10005];
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	int v,w;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d%d",&v,&w);
		for(int j = w;j <= W;j++)
		{
			dp[j] = min(dp[j],dp[j-w]+v);
		}		
	}
	if(dp[W]==0x3f3f3f3f) cout<<"impossible.\n";
	else cout<<dp[W]<<endl;
	return 0;
}
