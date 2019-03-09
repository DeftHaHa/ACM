#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll a[100005];
ll f(int n)
{
	ll sum = 0,Max = -2e9;
	for(int i = 0;i < n;i++){
		sum += a[i];
		Max = max(Max,sum);
		if(sum < 0) sum = 0;
	}
	return Max;
}
int main()
{
	int n;
	scanf("%d",&n);
	ll SUM = 0;
	for(int i = 0;i < n;i++){
		scanf("%lld",&a[i]);
		SUM += a[i];
	}
	ll ans = f(n);
	for(int i = 0;i < n;i++) a[i] = -a[i];
	printf("%lld\n",max(SUM+f(n),ans));
	return 0;
}
