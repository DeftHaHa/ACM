#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=998244353;
long long f(long long n)
{
	long long res=1;
	while(n)
	{
		res*=n%10;
		n/=10;
	}
	return res;
}
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	long long n,k;
	scanf("%lld%lld",&n,&k);
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		long long a=f(i);
		if(a)
		for(long long j=1;j<=n;j++)
		{
			
			long long b=f(j);
			if(b)
			{
				if(gcd(a,b)<=k) ans++;
			}
			
		}
	}
	printf("%lld\n",ans%mod);
	return 0;
}
