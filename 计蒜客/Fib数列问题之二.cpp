#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long mod;
struct matrix
{
	long long n[3][3];
};
matrix mul(matrix a,matrix b)
{
	matrix res;
	memset(res.n,0,sizeof(res.n));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				res.n[i][j]=(res.n[i][j]+a.n[i][k]*b.n[k][j])%mod;
	return res;
}
matrix matpow(matrix a,long long n)
{
	matrix res;
	memset(res.n,0,sizeof(res.n));
	for(int i=0;i<2;i++) res.n[i][i]=1;
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
	long long n;
	cin>>n>>mod;
	if(n==1||n==2) cout<<1<<endl;
	else
	{
		matrix a;
		a.n[0][0]=a.n[0][1]=a.n[1][0]=1;
		a.n[1][1]=0;    
		a=matpow(a,n-2);  
		printf("%d\n",(a.n[0][0]+a.n[0][1])%mod);
	}
	return 0;
}
