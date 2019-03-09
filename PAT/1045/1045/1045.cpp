#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[205][10005];
int main()
{
	int N,M,L;
	cin>>N>>M;
	int fa[205];
	for(int i=0;i<M;i++) scanf("%d",&fa[i]);
	cin>>L;
	int s[10005],tot=0,t;
	while(L--)
	{
		scanf("%d",&t);
		if(t<=N) s[tot++]=t;
	}
	for(int i=0;i<205;i++) dp[i][0]=0;
	for(int i=0;i<1005;i++) dp[0][i]=0;
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=tot;j++)
		{
			if(fa[i-1]==s[j-1]) dp[i][j]=dp[i][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[M][tot]<<endl;
	return 0;
}