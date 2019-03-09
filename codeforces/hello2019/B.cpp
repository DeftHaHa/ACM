#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
bool dp[15][400];
int main()
{
	int n;
	int a[20];
	cin>>n;
	int sum = 0;
	memset(dp,false,sizeof(dp));
	dp[0][0] = true;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		for(int j=0;j<360;j++) dp[i][j]=dp[i-1][(j+a[i])%360]||dp[i-1][(j-a[i]+360)%360];
	}
	if(dp[n][0]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
