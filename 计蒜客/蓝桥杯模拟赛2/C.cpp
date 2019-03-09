#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
const ll mod = 10086;
ll quick_pow(ll a,int b){
	ll res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ll a = 1e12;
	ll sum = 0;
	for(ll i = 1;i <= mod;i++){
		sum = (sum + quick_pow(i,2019))%mod;
	}
	cout<<sum<<endl;
	ll ans = (a/mod)*sum%mod;
	a %= mod;
	
	for(ll i = 1;i <= a;i++){
		ans = (ans+quick_pow(i,2019))%mod;	
	}
	cout<<ans<<endl;
	return 0;
}
