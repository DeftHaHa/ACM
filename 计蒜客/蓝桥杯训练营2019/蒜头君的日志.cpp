#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1005],b[1005];
int dp[1005][1005];//以a[i],b[i]结尾的 并且最后一位为b[j]的。。。 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		dp[i][0] = 0;
	}
	for(int i = 1;i <= m;i++){
		dp[0][i] = 0;
		scanf("%d",&b[i]);
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int Max = 0;
		for(int j = 1;j <= m;j++){
			dp[i][j] = dp[i-1][j];
			if(a[i] > b[j]) Max = max(Max,dp[i-1][j]);
			else if(a[i] == b[j]) dp[i][j] = Max+1;
			if(i==n) ans = max(ans,dp[n][j]); 
		}
	}
	printf("      ");
	for(int i = 1;i <= m;i++) printf("%3d",b[i]);cout<<endl;
	for(int i = 0;i <= n;i++){
		if(i>0)printf("%3d",a[i]);
		else printf("   ");
		for(int j = 0;j <= m;j++){
			printf("%3d",dp[i][j]);
		}
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

