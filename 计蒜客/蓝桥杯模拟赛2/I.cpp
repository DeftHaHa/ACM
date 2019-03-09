#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 300005;
ll sum[300005];
int main()
{
	int n,a;
	ll m;
	sum[0] = 0;
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a);
		sum[i] = sum[i-1]+a;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(sum[j] - sum[i-1] < m) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
