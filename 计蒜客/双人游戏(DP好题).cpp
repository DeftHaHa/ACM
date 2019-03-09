#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int num[505][505];
int dp1[505][505],dp2[505][505],dp3[505][505],dp4[505][505];
int main()
{
	int n,m;
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
	memset(dp3,0,sizeof(dp3));
	memset(dp4,0,sizeof(dp4));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&num[i][j]);
	for(int i=1;i<=n;i++)  //左上到右下 
		for(int j=1;j<=m;j++)
			dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+num[i][j];
	for(int i=n;i>=1;i--) //左下到右上 
		for(int j=1;j<=m;j++)
			dp2[i][j]=max(dp2[i][j-1],dp2[i+1][j])+num[i][j];
	for(int i=1;i<=n;i++)   //右上到左下 
		for(int j=m;j>=1;j--)
			dp3[i][j]=max(dp3[i][j+1],dp3[i-1][j])+num[i][j];
	for(int i=n;i>=1;i--)  //右下到左上 
		for(int j=m;j>=1;j--)
			dp4[i][j]=max(dp4[i][j+1],dp4[i+1][j])+num[i][j];
	int ans=0;
	for(int i=2;i<n;i++)    //枚举所有可能重复经过的一个位置 
	{
		for(int j=2;j<m;j++)
		{
			ans=max(ans,num[i][j]+max(dp1[i-1][j]+dp2[i][j-1]+dp3[i][j+1]+dp4[i+1][j],
			dp1[i][j-1]+dp2[i+1][j]+dp3[i-1][j]+dp4[i][j+1]));
		}
	}
	cout<<ans<<endl;
	return 0;
}
