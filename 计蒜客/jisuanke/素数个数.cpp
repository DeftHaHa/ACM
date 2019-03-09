#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long maxn=76543220;
bool vis[maxn];
bool is_p[maxn];
long long prime[10000005],cnt=0;
int main()
{
	memset(is_p,1,sizeof(is_p));
	memset(vis,false,sizeof(vis));
	is_p[0]=is_p[1]=false;
	
	for(long long i=2;i<=maxn;i++)
	{
		if(is_p[i]) prime[cnt++]=i;
		for(long long j=0;j<cnt&&i*prime[j]<=maxn;j++)
		{// if(i*prime[j]>76543100) cout<<i*prime[j]<<endl;
			is_p[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}   cout<<"#####"<<cnt<<endl;
	
	
	int ans=0;
	int n[8]={0,1,2,3,4,5,6,7};
	do
	{
		int sum=0;
		for(int i=0;i<8;i++)
		{
			sum=sum*10+n[i];
		}
		if(!vis[sum])
		{
			vis[sum]=true;
			if(is_p[sum])
			{
				ans++;//cout<<sum<<endl;
			}
		}
	}while(next_permutation(n,n+8));
	cout<<"###"<<ans<<endl;
	return 0;
}
