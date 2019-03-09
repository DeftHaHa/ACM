#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--){
		ll n,a,b;
		scanf("%I64d%I64d%I64d",&n,&a,&b);
		if((double)b/2.0 >= (double)a){
			printf("%I64d\n",n*a);
		}
		else{
			ll t = n/2;
			ll res = n - t*2;
			printf("%I64d\n",res*a + t*b);
		}
	}
	return 0;
}
