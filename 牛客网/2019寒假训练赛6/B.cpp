#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m,d,x;
	scanf("%lld%lld%lld%lld",&n,&m,&d,&x);
	ll l = 1,r = x;
	ll ans = r;
	while(l<r){
		ll mid = (l+r)/2;
		ll sum = mid*n+mid*(mid-1)/2*d;
		if(sum < m) l = mid+1;
		else r = mid;
	}
	printf("%lld\n",r);
	
	return 0;
} 
