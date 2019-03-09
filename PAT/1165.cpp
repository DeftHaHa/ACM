#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
	
	int T;
	scanf("%d",&T);
	ll A,B,C;
	for(int i = 1;i <= T;i++){
		scanf("%lld%lld%lld",&A,&B,&C);
		bool da = false;
		ll sum = A + B;
		if(A > 0 && B > 0 && sum < 0)  da = true;
		else if(A < 0 && B < 0 && sum >= 0) da = false;
		else if(sum > C) da = true;
	
		if(da) printf("Case #%d: true\n",i);
		else printf("Case #%d: false\n",i);
	}
	return 0;
}
