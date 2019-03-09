#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	double w[35][35];
	memset(w,0,sizeof(w));
	freopen("DATA.txt","r",stdin);
	for(int i=1;i<=29;i++)
	{
		for(int j=1;j<=i;j++) 
			scanf("%lf",&w[i][j]);
	}
	for(int i=1;i<=29;i++)
	{
		for(int j=1;j<=i;j++)
		{
			w[i+1][j]+=w[i][j]/2.0;
			w[i+1][j+1]+=w[i][j]/2.0;
		}
	}
	for(int i=1;i<=30;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("%.1lf ",w[i][j]);
		}cout<<endl;
	}
	double m=100000.0,M=0;
	for(int i=1;i<=30;i++)
	{
		m=min(w[30][i],m);
		M=max(w[30][i],M);
	}
	printf("%lf ",2086458231.0/m*M);
}
