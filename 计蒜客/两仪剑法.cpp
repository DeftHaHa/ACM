#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int T;
	cin>>T;
	long long a,b;
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",a*b/gcd(a,b));
	}
	return 0;
}
