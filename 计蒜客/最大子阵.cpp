#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int mat[55][55];
	int sumc[55][55];
	int n,m;
	cin>>n>>m;
	memset(sumc,0,sizeof(sumc));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&mat[i][j]);
			sumc[i][j]=mat[i][j]+sumc[i-1][j];
		}
	}		
	int ans=mat[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			for(int k=1;k<=m;k++)
			{ 
				sum+=sumc[j][k]-sumc[i-1][k];   
				ans=max(ans,sum);
				if(sum<0) sum=0;
				
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
