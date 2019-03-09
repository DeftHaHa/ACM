#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100005];
bool cmp(ll a,ll b){
	return a>b;
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i = 1;i <= N;i++) scanf("%lld",&a[i]);
	int ans = 0;
	sort(a+1,a+N+1,cmp);
	for(int i = 1;i <= N;i++){
		if(a[i] <= i) break;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
