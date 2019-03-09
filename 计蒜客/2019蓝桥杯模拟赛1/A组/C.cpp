#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int main()
{
	ll ans = 1;
	int n = 2019;
	for(int i = 1;i < n;i++){
		int cnt = 0;
		int t = i;
		while(t){
			if(t&1) cnt++;
			t>>=1;
		}
		ans = (ans*((1LL<<cnt)-1))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
