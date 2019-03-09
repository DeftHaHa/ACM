#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//从 序列 a0~an中删除最少的元素满足p1>=p2>=...pi<=pi+1<=pi+2<=...px;
//思路:从前往后和从后往前分别做一次以i结尾的最长不上升子序列
//注意：Nlog(N)的解法dp[i]表示的并不是以a[i]为结尾的 
int main()
{
	int n;
	int a[1005];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=n;
	int dp1[1005],dp2[1005];
	for(int i=0;i<n;i++) dp1[i]=dp2[i]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<=a[j]) dp1[i]=max(dp1[i],dp1[j]+1);
		}
	}
	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[i]<=a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
		}
	}

	for(int i=0;i<n;i++)
	{
		ans=min(ans,n-dp1[i]-dp2[i]+1);
	}
	cout<<ans<<endl;
	return 0;
}
