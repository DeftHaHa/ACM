#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 200005;
int fa[maxn];
int Find(int x){ return fa[x] == x ? x:fa[x] = Find(fa[x]);}
struct edge{
	int u,v,w;
}e[maxn];
bool cmp(edge a,edge b){
	return a.w < b.w;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) fa[i] = i;
	for(int i = 0;i < m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e,e+m,cmp);
	int ans = -n+1,cnt = 0;
	for(int i = 0;i < m;){
		int j = i;
		if(Find(e[i].u)!=Find(e[i].v)) ans++;
		while(j+1 < m && e[j+1].w == e[i].w){
			if(Find(e[j+1].u) != Find(e[j+1].v)) ans++;
			j++;	
		}
		for(int k = i;k <= j;k++) if(Find(e[k].u) != Find(e[k].v)){
			fa[Find(e[k].u)] = Find(e[k].v);
			cnt++;
		}
		if(cnt == n-1) break;
		i = j+1;
	}
	printf("%d\n",ans);
	return 0;
}
