#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	long long f[55][55];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		f[i][1]=f[i][i]=1;
		for(int j=2;j<=i-1;j++)
		{
			f[i][j]=f[i-1][j]+f[i-1][j-1];
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}
