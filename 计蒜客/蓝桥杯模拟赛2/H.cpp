#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
ll a[1000005];
ll dp[1000005],cp[1000005];//从i开始的最大 最小区间和 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	n--;
	for(int i = 1;i <= n;i++) a[i] = abs(a[i]-a[i+1]);
	ll ans = 0;
	dp[n+1] = cp[+1] = 0;
 	for(int i = n;i >= 1;i--){
		dp[i] = max(a[i],a[i] - cp[i+1]);
		cp[i] = min(a[i],a[i] - dp[i+1]);
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
