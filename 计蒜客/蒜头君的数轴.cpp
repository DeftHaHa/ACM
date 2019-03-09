#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int n;
	long long x[100005];
	long long d[100005];
	cin>>n;
	for(int i=0;i<n;i++) scanf("%lld",&x[i]);
	sort(x,x+n);
	d[1]=x[1]-x[0];
	int tag;
	long long M=-1e9-7;
	for(int i=1;i<n;i++)
	{
		d[i]=x[i]-x[i-1];
		if(d[i]>M)
		{
			M=d[i];
			tag=i;
		}
	}
	long long GCD;
	if(tag!=1) GCD=d[1];
	else GCD=d[2];
	for(int i=1;i<n;i++)
	{
		if(i!=tag)
		{
			GCD=gcd(GCD,d[i]);
		}
	}
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		if(i!=tag)
		{
			ans+=d[i]/GCD-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
