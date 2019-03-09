#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mod=10;
long long quickpow(long long a,long long n)
{
	long long res=1;
	while(n)
	{
		if(n&1) res=(res*a)%10;
		a=(a*a)%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	int T;
	cin>>T;
	long long a;
	while(T--)
	{
		scanf("%lld",&a);
		printf("%lld\n",quickpow(a,a));
	}
	return 0;
}
