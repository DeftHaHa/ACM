#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod = 1e9+7;
long long a;
int main()
{
	long long n;
	cin>>n;
	long long ans = 0;
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld",&a);
		//ans = (ans + (2+n-i)*(n-i+1)/2%mod*a%mod*i%mod)%mod;
		ans = (ans+i*a%mod*((n-i+2)*(n-i+1)/2%mod)%mod)%mod; 
	}
	cout<<ans<<endl;
	return 0;
}
