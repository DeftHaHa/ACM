#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long mod;
long long quickpow(long long a,long long n)
{
	long long res=1;
	while(n)
	{
		if(n&1) res=(res*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	long long a,b;
	long long c,d;
	while(~scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&mod))
	{
		c=c*d;
		a%=mod;
		b%=mod; 
		a=(a*b)%mod;
		if(!a||!b||!c||!d) printf("0\n");
		else printf("%lld\n",quickpow(a,c));
	}
	return 0;
}
