#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int fa[100005];
int getfa(int x){
	return fa[x] == x ? x:fa[x] = getfa(fa[x]);
}
int w[100005],Min[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		fa[i] = i;
		scanf("%d",&w[i]);
		Min[i] = w[i];
	}
	int a,b;
	while(m--){
		scanf("%d%d",&a,&b);
		a = getfa(a);
		b = getfa(b);
		if(a!=b) fa[a] = b;
	}
	for(int i = 1;i <= n;i++) Min[fa[i]] = min(Min[fa[i]],w[i]);
	ll sum = 0;
	for(int i = 1;i <= n;i++){
		if(fa[i] == i)
			sum += Min[i];
	}
	printf("%lld\n",sum);
	return 0;
}
