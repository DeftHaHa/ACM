#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct edge{
	int v,next;
}e[200005];
int eid,p[200005];
void addedge(int u,int v){
	e[eid].v = v;
	e[eid].next = p[u];
	p[u] = eid++;
}
int child[100005];
void dfs(int u){
	for(int i = p[u];i != -1;i = e[i].next){
		int v = e[i].v;
		dfs(v);
		child[u] += child[v] + 1; 
	}
}
int main()
{
	int n;
	cin>>n;
	int u,v;
	int ind[100005];
	memset(ind,0,sizeof(ind));
	memset(p,-1,sizeof(p));
	eid = 0;
	for(int i = 0; i < n-1;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		ind[v]++;
	}
	int S;
	for(int i=1;i <= n;i++){
		if(!ind[i]){
			S = i;
			break;
		}
	}
	memset(child,0,sizeof(child));
	dfs(S);
	for(int i=1;i <= n;i++){
		printf("%d\n",child[i]);
	}
	return 0;
}
