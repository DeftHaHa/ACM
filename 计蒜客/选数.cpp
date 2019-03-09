#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int l_size=50000005;
bool is_p[l_size];
int prime[5000005],cnt;
int num[25];
void euler()
{
	memset(is_p,1,sizeof(is_p));
	cnt=0;
	is_p[0]=is_p[1]=false;
	for(long long i=2;i<=l_size;i++)
	{
		if(is_p[i]) prime[cnt++]=i;
		for(long long j=0;j<cnt&&i*prime[j]<=l_size;j++)
		{
			is_p[prime[j]*i]=false;
			if(i%prime[j]==0) break;
		}
	}
}
int ans=0;
int n,k;
void dfs(int cnt,int pos,long long sum)
{
	if(cnt==k&&is_p[sum]) ans++;
	for(int i=pos+1;i<=n;i++)
	{
		dfs(cnt+1,i,sum+num[i]);	
	}
}
int main()
{
	euler();
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}
