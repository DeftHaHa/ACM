#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;	
int mod = 1000;
int n;
int dp[1005],a[1005];
int pro[1005][1005];
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++){
		pro[i][i] = a[i];
		for(int j = i+1;j <= n;j++){
			pro[i][j] = pro[i][j-1] * a[j] % mod;
		}
	}
	dp[0] = 0;
	dp[1] = a[1];
	for(int i = 2;i <= n;i++){
		for(int j = 0;j < i;j++){
			dp[i] = max(dp[i],dp[j]+pro[j+1][i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
