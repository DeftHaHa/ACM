#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[205];
int dp[205][8005];
int main()
{
	cin>>n;
	int sum = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = n/2+1;j >= 1;j--)
		{
			for(int k = sum/2;k >= a[i];k--)
			{
				dp[j][k] |= dp[j-1][k-a[i]]; //j个人总血量为k是否可行
			}
		}
	}
	int tag = n/2;
	for(int k =sum/2;k >= 0;k--)
	{
		if(dp[tag][k] || (n&1 && dp[tag+1][k])) //n为单数的话可能是n/2+1个的和小 
		{
			cout<<k<<' '<<sum-k<<endl;
			break;
		}
	}
	return 0;
}
