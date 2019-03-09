#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll x[105],y[105];
ll s[1000005];
int cnt;
bool cmp(ll a,ll b){return a>b;}
int main()
{
	int T;
	int n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i = 0;i < n;i++) scanf("%lld%lldf",&x[i],&y[i]);
		cnt = 0;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				for(int k = j + 1;k < n;k++){
					ll now = abs((x[i]*y[j]-x[j]*y[i])+(x[j]*y[k]-x[k]*y[j])+(x[k]*y[i]-x[i]*y[k]));
					s[cnt++] = now;
				}
			}
		}
		nth_element(s,s+k-1,s+cnt,cmp);
		if(s[k-1]%2) printf("%lld.50\n",s[k-1]/2);
		else printf("%lld.00\n",s[k-1]/2);
	}
	return 0;
}
