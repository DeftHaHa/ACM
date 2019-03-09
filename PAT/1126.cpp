#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[505],d[505];
int getfa(int x){
	return fa[x] == x? x : fa[x] = getfa(fa[x]);
}
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= N;i++) fa[i] = i;
	memset(d,0,sizeof(d));
	int u,v;
	for(int i = 0;i < M;i++){
		scanf("%d%d",&u,&v);
		d[u]++;
		d[v]++;
		u = getfa(u);
		v = getfa(v);
		if(u!=v) fa[u] = v;
	}
	int cntc = 0,cnte = 0,cnto = 0;
	for(int i = 1;i <= N;i++){
		if(fa[i] == i) cntc++;
		if(d[i]&1) cnto++;
		else cnte++;
	}
	printf("%d",d[1]);
	for(int i = 2; i <= N;i++) printf(" %d",d[i]);
	puts("");
	if(cntc > 1 || (cnto!=2&&cnto!=0)) puts("Non-Eulerian");
	else if(cnto == 0) puts("Eulerian");
	else puts("Semi-Eulerian");
	return 0;
}
