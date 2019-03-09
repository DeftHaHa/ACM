#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
struct matrix
{
	long long n[4][4];
};
void dispaly(matrix temp)
{
	for(int i=0;i<3;i++){ 
		for(int j=0;j<3;j++) 
		printf("%d ",temp.n[i][j]);
		cout<<endl;
		}
}
matrix mul(matrix a,matrix b)
{
	matrix res;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			res.n[i][j]=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				res.n[i][j]=(res.n[i][j]+a.n[i][k]*b.n[k][j])%mod;
	return res;	
}
matrix quick_pow(matrix mat,long long n)
{
	matrix ans;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ans.n[i][j]=0;
	for(int i=0;i<3;i++) ans.n[i][i]=1;
	while(n)
	{
		if(n&1) ans=mul(ans,mat);
		mat=mul(mat,mat);
		n>>=1;
	}
	return ans;
}
int main()
{
	long long a,b,c;
	long long n;
	matrix mat;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mat.n[i][j]=0;
	cin>>n;
	cin>>a>>b>>c;
	if(n==1) cout<<1<<endl;
	else if(n==2) cout<<2<<endl;
	else
	{
		mat.n[0][0]=a;
		mat.n[0][1]=b;
		mat.n[0][2]=c;
		mat.n[1][0]=1;
		mat.n[2][2]=1;
		matrix temp=quick_pow(mat,n-2);
	       //	dispaly(temp);
		printf("%lld\n",(temp.n[0][0]*2+temp.n[0][1]+temp.n[0][2])%mod);
	}
	return 0;
}
