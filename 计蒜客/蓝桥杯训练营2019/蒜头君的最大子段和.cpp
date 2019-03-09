#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	ll a,sum = 0;
	ll ans = -1e10;
	while(n--){
		scanf("%lld",&a);
		sum += a;
		ans = max(ans,sum);
		if(sum < 0){
			sum = 0;
		}
	}
	printf("%lld\n",ans);
		
	

	return 0;
}
