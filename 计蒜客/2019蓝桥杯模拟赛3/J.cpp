#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	if(n>m) swap(n,m);
	ll sum1 = (1+n)*n/2;
	ll sum3 = sum1*2 + (m-n)*n - n;
	//cout<<sum1<<' '<<sum3<<endl;
	ll l = 2,r = m+n;
	while(l <= r){
	 	ll mid = (l+r)/2;
	 	ll t = 0;
		if(mid <= n){
			ll len = mid - 2;
			t = sum3 - (1+len)*len/2;
		}
		else if(mid > m){
			ll len = m+n-mid+1; 
			t = (len)*(len+1)/2;
		}
		else t = sum1 + (m-mid)*n;
		//cout<<mid<<' '<<t<<endl;
	 	if(t >= k) l = mid+1;
	 	else r = mid - 1;
	}
	printf("%lld\n",r);
	
	
	return 0;
}
