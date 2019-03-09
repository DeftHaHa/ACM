#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;	
int cnt=0,w[720005];
int dp[720005];
int main()
{
	int n[7];
	int sum=0,tot=0;
	for(int i=1;i<=6;i++)
	{
		scanf("%d",&n[i]);
		sum+=i*n[i];
		tot+=n[i];
	}

	for(int i=1;i<=6;i++)
	{
		for(int j=1;;j*=2)
		{
			if(j<n[i])
			{
				w[cnt]=j*i;
				cnt++;
			}
			else
			{
				w[cnt]=n[i]*i;
				cnt++;
				break;
			}
		}
	}
	
	memset(dp,0,sizeof(dp));
	if(sum&1) printf("Can't be divided.\n");
	else
	{
		int aim=sum/2;
		dp[0]=1;
		for(int i=0;i<cnt;i++)
		{
			for(int j=aim;j>=w[i];j--)
			{
				if(dp[j-w[i]])
				{
					dp[j]=1;
				}
			}
		}       //cout<<dp[aim]<<endl;
		if(dp[aim]) cout<<"Can be divided."<<endl;
		else cout<<"Can't be divided."<<endl;
	}
	return 0;
}
