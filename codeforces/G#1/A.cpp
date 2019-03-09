#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll b,k;
ll a[100005];
int main()
{
	scanf("%I64d%I64d",&b,&k);
	for(int i = 0;i < k;i++) scanf("%I64d",&a[i]);
	ll ans = 0,w = 1;
	for(int i = k-1;i >=0;i--)
	{
		ans = (ans+a[i]*w)%2;
		w = w * b%2;
	}
	if(ans&1) puts("odd");
	else puts("even");
	return 0;
}
