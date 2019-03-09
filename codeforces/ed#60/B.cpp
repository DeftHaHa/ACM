#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
ll a[200005];
int main()
{
	ll n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(int i = 1;i <= n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	ll a1 = a[n],a2 = a[n-1];
	ll t = m/(k+1);
	ll ans = (a1*k+a2)*t + (m-t*(k+1))*a1;
	printf("%I64d\n",ans);
	return 0;
}
