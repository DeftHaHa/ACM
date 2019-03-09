#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int TW;
	int N,w[1005];
	cin>>TW;
	cin>>N;
	int sumW = 0;
	for(int i = 1;i <= N;i++)
	{
		scanf("%d",&w[i]);
		sumW += w[i];
	}
	int lack = sumW - TW;
	long long dp[100005];
	int path[100005];
	memset(path,0,sizeof(path));
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 1;i <= N;i++)
	{
		for(int j = lack;j >= w[i];j--)
		{
			dp[j] += dp[j-w[i]];
			if(dp[j-w[i]]) path[j] = i;
		}
	}
	if(dp[lack]==0) cout<<0<<endl;
	else if(dp[lack]>1) cout<<-1<<endl;
	else
	{
		int ans[105],cnt = 0;
		int now = lack;
		while(path[now]>0)
		{
			ans[cnt++] = path[now];
			now -= w[path[now]];
		}
		sort(ans,ans+cnt);
		cout<<ans[0];
		for(int i = 1 ;i < cnt;i++) cout<<' '<<ans[i];
		cout<<endl;
	}
	return 0;
}
