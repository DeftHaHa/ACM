#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	long long a[20],b[20];
	for(int i=0;i<20;i++)
	{
		scanf("%lld/%lld",&a[i],&b[i]);
	}
	long long ta=a[0],tb=b[0];
	for(int i=1;i<20;i++)
	{
		long long newb=tb*b[i]/gcd(tb,b[i]);
		long long newa=newb/tb*ta+newb/b[i]*a[i];
		ta=newa;
		tb=newb;
	}
	long long GCD=gcd(ta,tb);
	printf("%lld/%lld\n",ta/GCD,tb/GCD);
	cout<<gcd(ta/GCD,tb/GCD);
	return 0;
}
