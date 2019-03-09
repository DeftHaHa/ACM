#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long mod=1e9+7;
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
	long long m;
	long long n;
	cin>>n>>m;
	long long ans=(quickpow(m,n)-(m*quickpow(m-1,n-1))%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
} 
