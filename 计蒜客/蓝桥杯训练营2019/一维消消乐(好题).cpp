#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int w[10005],dp[10005][2];//dp[i][1]��ʾ��i��β��w[i]��ǰ��Ľ�ϣ�[i][0]��ʾ����ǰ��Ľ�� 
int main()
{
	int n;
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",&w[i]);
	long long ans = 0;
	dp[0][1] = dp[0][0] = 0;
	for(int i = 1;i < n;i++){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = dp[i-1][0] + w[i]*w[i-1];
	}
	cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
	return 0;
}
