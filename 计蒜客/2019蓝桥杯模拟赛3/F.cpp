#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
ll p[100005];
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i = 1;i <= n;i++) scanf("%lld",&p[i]);
	sort(p+1,p+n+1);
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		int l = i,r = n;
		ll aim = p[i] + d;
		while(l <= r){
			int mid = (l+r)/2;
			if(p[mid] <= aim) l = mid+1;
			else r = mid-1;
		}
		ans += (r-i);
	}
	printf("%lld\n",ans);
	
	return 0;
}
