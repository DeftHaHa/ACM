#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int a[200005],p[200005],cnt = 0;
int b[200005];
map<int,int> vis;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int n,m,k;
	ll sum = 0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(a+1,a+n+1,cmp);
	int tot = m*k;
	for(int i = 1;i <= tot;i++){
		vis[a[i]]++;
		sum += a[i];
	}
	int t = 0;
	for(int i = 1;i <= n;i++){
		if(vis[b[i]]){
			vis[b[i]]--;
			t++;
			if(t==m){
				t = 0;
				p[++cnt] = i;
			}
		}
	}
	printf("%I64d\n",sum);
	printf("%d",p[1]);
	for(int i = 2;i < k;i++) printf(" %d",p[i]);
	puts("");
	return 0;
}
