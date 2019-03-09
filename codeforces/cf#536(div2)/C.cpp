#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int a[300005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	ll ans = 0;
	for(int i = 0;i < n/2;i++){
		//cout<<a[i]<<' '<<a[n-i-1]<<endl;
		ans += (a[i]+a[n-i-1])*(a[i]+a[n-i-1]);
	}
	printf("%I64d\n",ans);
	return 0;
}
