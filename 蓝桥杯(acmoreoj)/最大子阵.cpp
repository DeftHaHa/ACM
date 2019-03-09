#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int M[505][505];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%d",&M[i][j]);
	}
	int r[505][505];
	for(int j=1;j<=n;j++) 
	{
		r[0][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			r[i][j]=r[i-1][j]+M[i][j];
		}
	}
	int ans=0xc0c0c0c0,sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sum=0;
			for(int k=1;k<=m;k++)
			{
				sum+=r[j][k]-r[i][k];
				ans=max(ans,sum);  //可能出现全为负数矩阵，所以要放在这里 
				if(sum<0) sum=0;		
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
