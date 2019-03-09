#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll getcnt(ll p, ll x ) {
    ll res = 0;
    while(x) {
        res += x/p;
        x /= p;
    }
    return res;
}
ll a[1000005],c[1000005];
int main() {
    ll n,b;
    scanf("%I64d%I64d",&n,&b);
    int cnt = 0;
    for(ll i = 2;i*i <= b;i++) {
    	if(b%i==0){
    		a[++cnt] = i;
    		c[cnt] = 1;
    		b/=i;
    		while(b%i==0){
	            c[cnt]++;
	            b /= i;
	        }
		}
    }
    if(b!=1) a[++cnt] = b,c[cnt] = 1; 
    ll Min = 1e18;
    for( ll i = 1; i <= cnt; i ++ ) {
    	//cout<<a[i]<<'#'<<c[i]<<endl;
        Min = min(Min,getcnt(a[i],n)/c[i]);
    }
    printf("%I64d\n",Min);
    
    return 0;
}
