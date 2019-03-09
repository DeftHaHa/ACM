#include<iostream>
#include<cstdio>
using namespace std;
long long mod;
long long quickPow(long long a,long long b){
	long long res = 1;
	while(b){
		if(b&1) res = res*a%mod;
		b/=2;
		a = a*a%mod;
	}
	return res;
}
int main()
{
	int t;
	long long x,y;
	cin>>t;
	while(t--){
		cin>>x>>y>>mod;
		cout<<quickPow(x,y)<<endl;
	}
	return 0;
}
