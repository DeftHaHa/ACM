#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[5005],b[5005];
int dp[5005][5005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int pos = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		while(a[i] - a[pos] > 5) pos++;
		b[i] = pos;
	}
	sort(a+1,a+n+1);
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= k;i++){
		for(int j = n;j >= 1;j--){
			dp[]	
		}
		
	}
	
	return 0;
}
