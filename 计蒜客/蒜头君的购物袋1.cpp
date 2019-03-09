#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[20005];
int main()
{
	int V,n;
	int v[35];
	cin>>V>>n;
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=V;j>=v[i];j--)
		{
			dp[j]+=dp[j-v[i]];
		}
	}
	for(int i=V;i>=0;i--)
	{  
		if(dp[i])
		{
			cout<<V-i<<endl;
			break;
		}
	}
	return 0;
}
