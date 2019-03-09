#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[1005];
ll dp[1005];
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		scanf("%lld",&a[i]);
	}
	ll ans = 0;
	for(int i = 0;i < n;i++){
		dp[i] = a[i];
		for(int j = 0;j < i;j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i],dp[j]+a[i]);
			}
		}
		ans = max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
