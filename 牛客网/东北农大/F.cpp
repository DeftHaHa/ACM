#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	long long n;
	while(T--)
	{
		scanf("%lld",&n);
		if(n&1) printf("%lld\n",(n/2)*((n+1)/2));
		else printf("%lld\n",(n/2)*(n/2));
	}
	return 0;
}

