#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int sum[40];
	int aim;
	int n;
	int ans=0;
	sum[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+i;
	if(sum[n]&1) printf("0\n");
	else
	{
		aim=sum[n]/2;
		long long dp[aim+5];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=aim;j>=i;j--)
			{
				dp[j]+=dp[j-i];
			}
		}
		cout<<dp[aim]/2<<endl;
	}
	
	return 0;
}
