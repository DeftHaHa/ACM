#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll quick_pow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res;
}
ll euler(ll n){
	ll res = n;
    for(ll i = 2;i*i <= n;i++){
        if(n%i==0){
            res = res / i * (i-1);
            while(n%i == 0) n/=i;
        }
    }
    if(n > 1) res = res / n * (n-1);
    return res;
}
int main()
{
	ll n,k,A,B;
	scanf("%lld%lld%lld%lld",&n,&k,&A,&B);
	printf("%lld\n",quick_pow(k,n*euler(n)/2)*(A+B)%mod);
	return 0;	
}
