#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100005],Max[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	ll sum = 0;
	Max[n+1] = 0;
	for(int i = n;i >= 1;i--){
		sum += a[i];
		Max[i] = max(Max[i+1],sum);
	}
	sum = 0;
	ll dp = 0;
	ll ans = -2e9,SUM = 0;
	for(int i = 1;i <= n;i++)
	{
		sum += a[i];
		dp = max(sum,dp);
		SUM += a[i];
		ans = max(ans,max(SUM,dp+Max[i+1])); 
		if(SUM < 0) SUM = 0;
	}
	printf("%lld\n",ans);
	return 0;
}
