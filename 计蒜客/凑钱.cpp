#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n[35];
	for(int i=1;i<=30;i++) cin>>n[i];
	int sum=0;
	for(int i=1;i<=30;i++) sum+=n[i];
	cout<<"sum="<<sum<<endl;
	bool dp[10005];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=30;i++)
	{
		for(int j=sum;j>=n[i];j--)
		{
			dp[j]+=dp[j-n[i]];
		}
	}
	for(int j=0;j<=sum;j++)
	{
		if(!dp[j])
		{
			cout<<j<<' '<<endl;
			break;
		}
		
	}
	return 0;
}
