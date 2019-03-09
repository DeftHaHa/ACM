#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
typedef long long ll;
struct matrix
{
	ll n[3][3];
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
matrix matpow(matrix a,ll n)
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
	ll N,M;
	scanf("%I64d%I64d",&N,&M);
	if(N < M) puts("1");
	else if(N == M) puts("2");
	else{
		matrix A;
		A.n[0][0] = A.n[0][1] = A.n[1][0] = 1;
		A.n[1][1] = 0;
		A = matpow(A,N-M+1);
		printf("%I64d\n",(A.n[0][1]+A.n[0][0])%mod);
	}
	return 0;
}
