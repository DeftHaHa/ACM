#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long mod=1e9+7;
struct matrix
{
	long long n[6][6];
};
matrix mul(matrix a,matrix b)
{
	matrix res;
	memset(res.n,0,sizeof(res.n));
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			for(int k=0;k<6;k++)
				res.n[i][j]=(res.n[i][j]+(a.n[i][k]*b.n[k][j])%mod)%mod;
	return res;
}
matrix matpow(matrix a,long long n)
{
	matrix res;
	memset(res.n,0,sizeof(res.n));
	for(int i=0;i<6;i++) res.n[i][i]=1;
	while(n)
	{
		if(n&1) res=mul(res,a);
		a=mul(a,a);
		n>>=1;
	}
	return res;
}
int main()
{
	int bf[10]={0,4,5,6,1,2,3};
	matrix a;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			a.n[i][j]=4;
	long long n;
	int m;
	cin>>n>>m;
	int x,y;
	while(m--)
	{
		cin>>x>>y;
		a.n[x-1][bf[y]-1]=0;
		a.n[y-1][bf[x]-1]=0;
	}
	if(n==1) printf("4\n");
	else
	{
		a=matpow(a,n-1);
		long long ans=0;
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				ans=(ans+(4*a.n[i][j])%mod)%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
