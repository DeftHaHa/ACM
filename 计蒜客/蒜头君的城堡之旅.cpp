#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[55][55][55][55];
int w[55][55];
//�����Ͻ��ߵ����½��ٴ����»ص����ϵĲ��ظ�������ֵ
//����������ͬʱ�������ߵ����� ,i+j!=k+l�ж�ͬһ�׶Σ����ж��Ƿ�Ϊͬһ�� 
int main()
{
	memset(dp,0,sizeof(dp));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&w[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int l=1;l<=m;l++)
				{
					if(i+j==k+l&&(i!=k||j!=l))
					{
						dp[i][j][k][l]=
						max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1])
						,max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))
						+w[i][j]+w[k][l];
					}
				}
			}
		}
	}
	cout<<max(dp[n-1][m][n][m-1],dp[n][m-1][n-1][m])<<endl;
	return 0;
}

