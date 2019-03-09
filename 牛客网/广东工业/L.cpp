#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long mod=1e9+7;
long long qp(long long a,long long n)
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
	int T;
	cin>>T;
	long long x,a,y,b;
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&x,&a,&y,&b);
		if(qp(x,a)==qp(y,b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}



