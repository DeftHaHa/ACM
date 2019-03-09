#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool is_p[8000005];
int prime[2000005],cnt;
long long maxn;
void euler()
{
	memset(is_p,1,sizeof(is_p));
	is_p[0]=is_p[1]=false;
	cnt=0;
	for(long long i=2;i<=maxn;i++)
	{
		if(is_p[i]) prime[cnt++]=i;
		for(long long j=0;j<cnt&&i*prime[j]<=maxn;j++)
		{
			is_p[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
}
int main()
{
	int l,r;
	cin>>l>>r;
	maxn=(long long)r;
	euler();
	int ans1=0x3f3f3f3f,ans2=0xc0c0c0c0;
	int a=-1,b,c,d;
	int i=lower_bound(prime,prime+cnt,l)-prime;
	for(i++;i<cnt;i++)
	{
		if(prime[i]-prime[i-1]<ans1)
		{
			ans1=prime[i]-prime[i-1];
			a=prime[i-1];
			b=prime[i];
		}
		if(prime[i]-prime[i-1]>ans2)
		{
			ans2=prime[i]-prime[i-1];
			c=prime[i-1];
			d=prime[i];
		}
	}
	if(a!=-1) printf("%d,%d are closest, %d,%d are most distant.\n",a,b,c,d);
	else printf("There are no adjacent primes.\n");
	return 0;
}
