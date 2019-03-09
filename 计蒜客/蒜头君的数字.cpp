#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
long long d[200005],a[200005];
long long sum[200005];
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	scanf("%lld",&a[0]);
	d[0]=a[0];
	for(int i=1;i<n;i++)
	{
		scanf("%lld",&a[i]);
		d[i]=a[i]-a[i-1];
	}
	int l,r,x;
	while(m--)
	{
		scanf("%d%d%d",&l,&r,&x);
		d[l]=(d[l]+x+mod)%mod;
		d[r+1]-=x;
	}
	for(int i=1;i<n;i++)
	{
		d[i]=(d[i]+d[i-1]+mod)%mod;
	}
	for(int i=1;i<n;i++)
	{
		d[i]=(d[i]+d[i-1]+mod)%mod;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if(l>0) printf("%lld\n",(d[r]-d[l-1]+mod)%mod);
		else printf("%lld\n",(d[r]+mod)%mod);
	}
	return 0;
}
