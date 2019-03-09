#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct matrix
{
	double n[2][2];
};
matrix mul(matrix a,matrix b)
{
	matrix res;
	memset(res.n,0,sizeof(res.n));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				res.n[i][j]+=a.n[i][k]*b.n[k][j];
	return res;
}
matrix matpow(matrix a,int n)
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
	double A,B;
	double x,y;
	int k;
	scanf("%lf%lf%lf%lf%d",&A,&B,&x,&y,&k);
	matrix a;
	a.n[0][0]=(100.0-x)/100.0;
	a.n[0][1]=y/100;
	a.n[1][0]=x/100.0;
	a.n[1][1]=(100.0-y)/100.0;
	a=matpow(a,k);     
	//cout<<a.n[0][0]<<' '<<a.n[0][1]<<endl<<a.n[1][0]<<' '<<a.n[1][1]<<endl;
	printf("%.2lf %.2lf\n",a.n[0][0]*A+a.n[0][1]*B,a.n[1][0]*A+a.n[1][1]*B);
	return 0;
}
