#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mod;
//µÝÍÆ:f(n)=f(n-1)+f(n-3)+f(n-4)
/*
1 1 0 0
0 0 1 0
1 0 0 1
1 0 0 0
*/
int a[]={0,2,4,6,9};
struct matrix
{
	int n[4][4];
}A;
matrix mul(matrix a,matrix b)
{
	matrix res;
	memset(res.n,0,sizeof(res.n));
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				res.n[i][j]=(res.n[i][j]+a.n[i][k]*b.n[k][j])%mod;
	return res;
}
void display(matrix a)
{
	cout<<"####"<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		cout<<a.n[i][j]<<' ';
		cout<<endl;
	}
}
matrix matpow(matrix a,int n)
{
	matrix res;
	memset(res.n,0,sizeof(res.n)); 
	for(int i=0;i<4;i++) res.n[i][i]=1;
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
	int L; int b[4];
	matrix A;
	memset(A.n,0,sizeof(A.n));
	A.n[0][0]=A.n[0][1]=A.n[1][2]=A.n[2][0]=A.n[2][3]=A.n[3][0]=1;
	while(~scanf("%d%d",&L,&mod))
	{
		if(L<5) printf("%d\n",a[L]%mod);
		else
		{
			matrix temp=matpow(A,L-4);
			printf("%d\n",(9*temp.n[0][0]+6*temp.n[1][0]+4*temp.n[2][0]+2*temp.n[3][0])%mod);
		}
	}
}
