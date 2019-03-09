#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N,h[105];
	int dp[105][2005]; //dp[i][j] i��ˮ�����˫����˫���߶Ȳ�Ϊjʱ�ϸ��������߶� 
	cin>>N;
	int sum = 0;
	for(int i = 1;i <= N;i++)
	{
		cin>>h[i];
		sum += h[i];
	}
	memset(dp,0xc0,sizeof(dp)); //ֻ��0,0�Ϸ���������Ϊ������ 
	dp[0][0] = 0;
	for(int i = 1;i <= N;i++)
	{
		for(int j = sum;j >= 0;j--)
		{
			dp[i][j] = max(dp[i][j],dp[i-1][j]); //��i�鲻�� 
			if(j >= h[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-h[i]]+h[i]); //���ڽϸߵ�����
			if(j<=sum-h[i]) dp[i][j] = max(dp[i][j],dp[i-1][j+h[i]]); //���ڽϵ͵�����֮��ϵ͵����ǽϵ͵� 
			if(h[i]>=j) dp[i][j] = max(dp[i][j],dp[i-1][h[i]-j]+j);//���ڽϵ͵�����֮��͵ı���˸ߵ� 
		}
	}
	int ans = 0;
	for(int i = 0;i <= N;i++) ans = max(ans,dp[i][0]);
	cout<<ans<<endl; 
	
	return 0;
}
