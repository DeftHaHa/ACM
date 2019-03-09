#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mod=10007;
long long quickpow(long long a,int n)
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
int num[1005][1005];
void pascal(int k)
{
	for(int i=1;i<=k;i++)
	{
		num[i][1]=num[i][i+1]=1;
		for(int j=2;j<=i;j++) num[i][j]=(num[i-1][j-1]+num[i-1][j])%mod;
	}
}
int main()
{
	long long a,b;
	int k,n,m;
	scanf("%lld%lld%d%d%d",&a,&b,&k,&n,&m);
	a=quickpow(a,n);
	b=quickpow(b,m);
	pascal(k);     
	printf("%lld\n",(num[k][n+1]*a*b)%mod);
	return 0;
}
