#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int dp[30];
	int m[]={0,2,2,2,2,3,3,3,5,5};
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=9;i++)
	{
		for(int j=27;j>=m[i];j--)
		{
			dp[j]+=dp[j-m[i]];
		}
	}
	int ans=0;
	for(int i=1;i<=27;i++) if(dp[i]) ans++;
	cout<<ans<<endl;
	return 0;
}
